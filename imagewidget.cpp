#include "imagewidget.hpp"
#include <QtGui>
#include <QUndoStack>
#include "imagefilter.hpp"
#include "to1bitdialog.hpp"
#include "linearfilterdialog.hpp"
#include "normfilterdialog.hpp"
#include "common.hpp"

class CommandFilter : public QUndoCommand {	// filter は new で作る。delete してはいけない。不要になったらこのクラスが delete する。
public:
	CommandFilter(IImageFilter *filter, QImage *img, const QString &text = QString()) :
		m_filter(filter), m_img(img), m_before(*img)
	{
		setText(text);
	}
	~CommandFilter() { delete m_filter; }
	virtual void undo() { *m_img = m_before; }
	virtual void redo() { m_filter->filter(m_img); }
private:
	IImageFilter *m_filter;
	QImage *m_img;
	QImage m_before;
};

class CommandImageChange : public QUndoCommand {
public:
	CommandImageChange(QWidget *parent, QImage *img, const QImage &after, const QString &text = QString()) :
		m_parent(parent), m_img(img), m_before(*img), m_after(after)
	{
		setText(text);
	}
	virtual void undo() { *m_img = m_before; }
	virtual void redo() { *m_img = m_after; }
private:
	QWidget *m_parent;
	QImage *m_img;
	QImage m_before;
	QImage m_after;
};

ImageWidget::ImageWidget(QWidget *parent) :
	QWidget(parent),
	m_stack(new QUndoStack(this)),
	m_filePath(QString()),
	m_imageLabel(new QLabel(this)),
	m_magnification(1.),
	m_flagAutoImageResize(false)
{
	// m_stack->setUndoLimit(5);	// 別に制限しなくていいんじゃね?
	connect(m_stack, SIGNAL(canUndoChanged(bool)), this, SIGNAL(canUndoChanged(bool)));
	connect(m_stack, SIGNAL(canRedoChanged(bool)), this, SIGNAL(canRedoChanged(bool)));
	connect(m_stack, SIGNAL(cleanChanged(bool)), this, SIGNAL(cleanChanged(bool)));
	connect(m_stack, SIGNAL(undoTextChanged(QString)), this, SIGNAL(undoTextChanged(QString)));
	connect(m_stack, SIGNAL(redoTextChanged(QString)), this, SIGNAL(redoTextChanged(QString)));

	m_imageLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->setMargin(0);
	QScrollArea *scrollArea = new QScrollArea(this);
	scrollArea->setWidgetResizable(true);
	scrollArea->setBackgroundRole(QPalette::Midlight);
	scrollArea->setWidget(m_imageLabel);
	layout->addWidget(scrollArea);
	setLayout(layout);
}

QImage ImageWidget::image() const { return m_image; }

QString ImageWidget::filePath() const { return m_filePath; }

QSize ImageWidget::sizeHint() const { return m_image.size() * m_magnification + QSize(2, 2); }

void ImageWidget::setImage(const QImage &image) {
	m_image = image;
	m_stack->clear();
	m_filePath = QString();
	setWindowTitle(tr("無題"));
	updateImageLabel();
}

void ImageWidget::paste(const QImage &image) {
	CommandImageChange *cmd = new CommandImageChange(this, &m_image, image, tr("貼り付け"));
	m_stack->push(cmd);
	updateImageLabel();
	autoImageResize();
}

bool ImageWidget::load(const QString &filePath)
{
	if (!m_image.load(filePath)) {
		return false;
	}
	m_image.convertToFormat(QImage::Format_RGB888, Qt::ColorOnly);
	m_stack->clear();
	m_filePath = filePath;
	setWindowTitle(QFileInfo(filePath).fileName());
	updateImageLabel();
	return true;
}

bool ImageWidget::save(const QString &filePath)
{
	const bool result = m_image.save(filePath);
	if (result) {
		m_filePath = filePath;
		setWindowTitle(QFileInfo(filePath).fileName());
	}
	return result;
}

bool ImageWidget::canUndo() const { return m_stack->canUndo(); }

bool ImageWidget::canRedo() const { return m_stack->canRedo(); }

QString ImageWidget::redoText() const { return m_stack->redoText(); }

QString ImageWidget::undoText() const { return m_stack->undoText(); }

void ImageWidget::zoom(qreal m)
{
	if (m >= COMMON_MAGNIFICATION_MAX) { m = COMMON_MAGNIFICATION_MAX; }
	if (m <= COMMON_MAGNIFICATION_MIN) { m = COMMON_MAGNIFICATION_MIN; }
	m_magnification = m;
	setAutoImageResize(false);
	updateImageLabel();
	emitZoomStateChanged();
}

void ImageWidget::autoImageResize()
{
	const qreal magnificationX = (qreal)(size().width() - 2) / (qreal)m_image.width();
	const qreal magnificationY = (qreal)(size().height() - 2) / (qreal)m_image.height();
	m_magnification = qMin(qMin(magnificationX, magnificationY), 1.);
	updateImageLabel();
	emitZoomStateChanged();
}

bool ImageWidget::canZoomIn() const
{
	return m_magnification < COMMON_MAGNIFICATION_MAX;
}

bool ImageWidget::canZoomOut() const
{
	return m_magnification > COMMON_MAGNIFICATION_MIN;
}

qreal ImageWidget::magnification() const { return m_magnification; }

bool ImageWidget::isAutoImageResize() const
{
	return m_flagAutoImageResize;
}

void ImageWidget::undo()
{
	if (m_stack->canUndo()) {
		m_stack->undo();
		updateImageLabel();
	}
}

void ImageWidget::redo()
{
	if (m_stack->canRedo()) {
		m_stack->redo();
		updateImageLabel();
	}
}

void ImageWidget::filterGrayscale()
{
	CommandFilter *cmd = new CommandFilter(new FilterGrayscale(), &m_image, tr("グレースケール化"));
	m_stack->push(cmd);
	updateImageLabel();
}

void ImageWidget::filterTo1Bit()
{
	To1BitDialog dialog(this);
	if (dialog.exec() == dialog.Accepted) {
		const int threshold = dialog.getThreshold();
		IImageFilter *filter = NULL;
		switch (dialog.getWayTo1Bit()) {
		case To1BitDialog::WayThresholdMethod:
			filter = new FilterTwoLebelByThreshold(threshold);
			break;
		case To1BitDialog::WayErrorDiffusionMethod:
			filter = new FilterTwoLebelByErrorDiffusion();
			break;
		default:
			QMessageBox::warning(this, tr("Error"), tr("No good."));
			return;
		}
		CommandFilter *cmd = new CommandFilter(filter, &m_image, tr("2値化"));
		m_stack->push(cmd);
	}
	updateImageLabel();
}

void ImageWidget::linearFilter()
{
	LinearFilterDialog dialog(this);
	if (dialog.exec() == dialog.Accepted) {
		const QVector< QVector<int> > mask(dialog.getMatrix());
		const int denominator = dialog.getDenominator();
		const bool absolute = dialog.getAbsolute();
		if (mask.isEmpty() || denominator == 0) { return; }
		CommandFilter *cmd = new CommandFilter(new LinearFilter(mask, denominator, absolute), &m_image, tr("線形フィルタ"));
		m_stack->push(cmd);
	}
	updateImageLabel();
}

void ImageWidget::medianFilter()
{
	CommandFilter *cmd = new CommandFilter(new MedianFilter(3), &m_image, tr("メディアンフィルタ"));
	m_stack->push(cmd);
	updateImageLabel();
}

void ImageWidget::normFilter()
{
	NormFilterDialog dialog(this);
	if (dialog.exec() == dialog.Accepted) {
		const QVector< QVector<int> > maskX(dialog.getMatrixX());
		const QVector< QVector<int> > maskY(dialog.getMatrixY());
		if (maskX.isEmpty() || maskY.isEmpty()) { return; }
		CommandFilter *cmd = new CommandFilter(new NormFilter(maskX, maskY), &m_image, tr("ノルムフィルタ"));
		m_stack->push(cmd);
	}
	updateImageLabel();
}

void ImageWidget::zoomIn()
{
	if (canZoomIn()) {
		setAutoImageResize(false);
		zoom(m_magnification * 2.);
	}
}

void ImageWidget::zoomOut()
{
	if (canZoomOut()) {
		setAutoImageResize(false);
		zoom(m_magnification * 0.5);
	}
}

void ImageWidget::zoomFullScale()
{
	setAutoImageResize(false);
	zoom(1.);
}

void ImageWidget::setAutoImageResize(bool yes)
{
	m_flagAutoImageResize = yes;
	if (yes) { autoImageResize(); }
}

void ImageWidget::resizeEvent(QResizeEvent *event)
{
	if (m_flagAutoImageResize) { autoImageResize(); }
}

void ImageWidget::wheelEvent(QWheelEvent *event)
{
}

void ImageWidget::updateImageLabel()
{
	QPixmap pixmap(QPixmap::fromImage(m_image));
	pixmap = pixmap.scaled(m_image.size() * m_magnification, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	m_imageLabel->resize(sizeHint());
	m_imageLabel->setPixmap(pixmap);
}

void ImageWidget::emitZoomStateChanged()
{
	emit canZoomInChanged(canZoomIn());
	emit canZoomOutChanged(canZoomOut());
	emit magnificationChanged(m_magnification);
	emit autoImageResizeChanged(m_flagAutoImageResize);
}
