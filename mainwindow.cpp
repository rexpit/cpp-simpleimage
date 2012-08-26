#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QtGui>
#include "imagewidget.hpp"
#include "common.hpp"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),
	m_activeWindow(NULL)
{
	ui->setupUi(this);

	mdiArea = new QMdiArea(this);
	mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setCentralWidget(mdiArea);
	connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow *)),
			this, SLOT(updateMenus()));

	editMagnification = new QLineEdit(this);
	editMagnification->setMaximumWidth(50);
	ui->zoomToolBar->addWidget(editMagnification);

	updateMenus();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
	if (event->mimeData()->hasFormat("text/uri-list")) {
		event->acceptProposedAction();
	}
}

void MainWindow::dropEvent(QDropEvent *event)
{
	const QList<QUrl> fileList(event->mimeData()->urls());
	for (QList<QUrl>::const_iterator it = fileList.begin(); it != fileList.end(); ++it) {
		const QString filePath = QDir::toNativeSeparators(it->toLocalFile());
		load(filePath);
	}
}

ImageWidget *MainWindow::createImageWidget()
{
	ImageWidget *child = new ImageWidget(mdiArea);
	mdiArea->addSubWindow(child);
	return child;
}

ImageWidget *MainWindow::activeImageWidget() const
{
	if (QMdiSubWindow *activeSubWindow = mdiArea->activeSubWindow()) {
		return qobject_cast<ImageWidget *>(activeSubWindow->widget());
	}
	return NULL;
}

void MainWindow::load(const QString &filePath)
{
	if (!filePath.isEmpty()) {
		const bool maximized = activeSubWindowIsMaximized();
		ImageWidget *widget = createImageWidget();
		if (widget->load(filePath)) {
			resizeAndShowSubWidget(widget, maximized);
		} else {
			QMessageBox::warning(this, tr("Error"), tr("Cannot load file."));
			widget->close();
		}
	}
}

void MainWindow::open()
{
	const QStringList filePathList(QFileDialog::getOpenFileNames(this, tr("Open Files"), tr("."), tr("Image (*.png *.jpg *.gif *.bmp);;BMP (*.bmp);;JPEG (*.jpg);;PNG (*.png);;GIF (*.gif)")));
	for (QStringList::const_iterator it = filePathList.begin(); it != filePathList.end(); ++it) {
		load(*it);
	}
}

void MainWindow::openClipboard()
{
	QImage image = QApplication::clipboard()->image();
	if (image.isNull()) { return; }
	const bool maximized = activeSubWindowIsMaximized();
	ImageWidget *widget = createImageWidget();
	widget->setImage(image);
	resizeAndShowSubWidget(widget, maximized);
}

void MainWindow::saveAs()
{
	ImageWidget *widget = activeImageWidget();
	if (!widget) { return; }
	QString dir = widget->filePath().isEmpty() ? tr(".") : widget->filePath();
	QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), dir, tr("Bitmap (*.bmp);;Potable Network Graphics (*.png);;JPEG (*.jpg)"));
	if (!filePath.isEmpty()) {
		if (!widget->save(filePath)) {
			QMessageBox::warning(this, tr("Error"), tr("Cannot save file."));
		}
	}
}

void MainWindow::undo()
{
	ImageWidget *widget = activeImageWidget();
	if (widget != NULL && widget->canUndo()) { widget->undo(); }
}

void MainWindow::redo()
{
	ImageWidget *widget = activeImageWidget();
	if (widget != NULL && widget->canRedo()) { widget->redo(); }
}

void MainWindow::copy()
{
	ImageWidget *widget = activeImageWidget();
	if (widget != NULL) {
		QClipboard *clipboard = QApplication::clipboard();
		clipboard->setImage(widget->image());
	}
}

void MainWindow::paste()
{
	QClipboard *clipboard = QApplication::clipboard();
	QImage image = clipboard->image();
	if (image.isNull()) { return; }

	const bool maximized = activeSubWindowIsMaximized();
	ImageWidget *widget = activeImageWidget();
	if (widget == NULL) {
		widget = createImageWidget();
		widget->setImage(image);
	} else {
		widget->paste(image);
	}
	resizeAndShowSubWidget(widget, maximized);
}

void MainWindow::filterGrayscale()
{
	ImageWidget *widget = activeImageWidget();
	if (widget != NULL) { widget->filterGrayscale(); }
}

void MainWindow::filterTo1Bit()
{
	ImageWidget *widget = activeImageWidget();
	if (widget != NULL) { widget->filterTo1Bit(); }
}

void MainWindow::linearFilter()
{
	ImageWidget *widget = activeImageWidget();
	if (widget != NULL) { widget->linearFilter(); }
}

void MainWindow::medianFilter()
{
	ImageWidget *widget = activeImageWidget();
	if (widget != NULL) { widget->medianFilter(); }
}

void MainWindow::normFilter()
{
	ImageWidget *widget = activeImageWidget();
	if (widget != NULL) { widget->normFilter(); }
}

void MainWindow::zoomIn()
{
	ImageWidget *widget = activeImageWidget();
	if (widget != NULL) { widget->zoomIn(); }
}

void MainWindow::zoomOut()
{
	ImageWidget *widget = activeImageWidget();
	if (widget != NULL) { widget->zoomOut(); }
}

void MainWindow::zoomFullScale()
{
	ImageWidget *widget = activeImageWidget();
	if (widget != NULL) { widget->zoomFullScale(); }
}

void MainWindow::setAutoImageResize(bool yes)
{
	ImageWidget *widget = activeImageWidget();
	if (widget != NULL) { widget->setAutoImageResize(yes); }
}

void MainWindow::setTabVisible(bool view)
{
	mdiArea->setViewMode(view ? QMdiArea::TabbedView : QMdiArea::SubWindowView);
}

void MainWindow::about()
{
	QMessageBox::about(this, tr("バージョン情報"), tr(common::ABOUT_TEXT));
}

void MainWindow::aboutQt()
{
	QMessageBox::aboutQt(this, tr("About Qt"));
}

void MainWindow::updateMenus()
{
	ImageWidget *oldWidget = m_activeWindow;
	m_activeWindow = activeImageWidget();
	ImageWidget *newWidget = m_activeWindow;
	const bool hasMdiChild = newWidget != NULL;

	ui->saveAsAct->setEnabled(hasMdiChild);
	ui->undoAct->setEnabled(hasMdiChild && newWidget->canUndo());
	ui->redoAct->setEnabled(hasMdiChild && newWidget->canRedo());
	ui->copyAct->setEnabled(hasMdiChild);
	ui->filterGrayscaleAct->setEnabled(hasMdiChild);
	ui->filterTo1BitAct->setEnabled(hasMdiChild);
	ui->linearFilterAct->setEnabled(hasMdiChild);
	ui->medianFilterAct->setEnabled(hasMdiChild);
	ui->normFilterAct->setEnabled(hasMdiChild);
	ui->zoomInAct->setEnabled(hasMdiChild && newWidget->canZoomIn());
	ui->zoomOutAct->setEnabled(hasMdiChild && newWidget->canZoomOut());
	ui->zoomFullScaleAct->setEnabled(hasMdiChild);
	ui->autoImageResizeAct->setEnabled(hasMdiChild);
	ui->autoImageResizeAct->setChecked(hasMdiChild && newWidget->isAutoImageResize());
	editMagnification->setEnabled(hasMdiChild);
	if (hasMdiChild) { setEditMagnification(newWidget->magnification()); }
	else { editMagnification->setText(QString()); }

	if (oldWidget != newWidget) {
		if (oldWidget != NULL) { oldWidget->disconnect(); ui->autoImageResizeAct->disconnect(); }
		if (hasMdiChild) {
			connect(newWidget, SIGNAL(canUndoChanged(bool)), ui->undoAct, SLOT(setEnabled(bool)));
			connect(newWidget, SIGNAL(canRedoChanged(bool)), ui->redoAct, SLOT(setEnabled(bool)));
			connect(newWidget, SIGNAL(canZoomInChanged(bool)), ui->zoomInAct, SLOT(setEnabled(bool)));
			connect(newWidget, SIGNAL(canZoomOutChanged(bool)), ui->zoomOutAct, SLOT(setEnabled(bool)));
			connect(newWidget, SIGNAL(autoImageResizeChanged(bool)), ui->autoImageResizeAct, SLOT(setChecked(bool)));
			connect(ui->autoImageResizeAct, SIGNAL(triggered(bool)), newWidget, SLOT(setAutoImageResize(bool)));
			connect(newWidget, SIGNAL(magnificationChanged(qreal)), this, SLOT(setEditMagnification(qreal)));
			connect(editMagnification, SIGNAL(returnPressed()), this, SLOT(setMagnificationFromEdit()));
		}
	}
}

void MainWindow::setEditMagnification(qreal m)
{
	editMagnification->setText(QString().setNum(m * 100.) + tr("%"));
}

void MainWindow::setMagnificationFromEdit()
{
	ImageWidget *widget = activeImageWidget();
	QString str(editMagnification->text());
	if (QRegExp(tr("^\\d+(\\.\\d*)?%?$")).exactMatch(str) && widget != NULL) {
		str.remove(QChar('%'));
		widget->zoom(str.toDouble() * 1e-2);
	}
}

void MainWindow::resizeAndShowSubWidget(ImageWidget *widget, bool maximize)
{
	widget->setMinimumSize(qMax(qMin(widget->sizeHint().width(), (int)(mdiArea->width() * 0.8)), 100),
		qMax(qMin(widget->sizeHint().height(), (int)(mdiArea->height() * 0.8)), 100));	// resize ではサイズ調整できないため、
	widget->showMaximized(); widget->showNormal();	// 一旦最大化してから通常サイズに戻す。
	widget->setMinimumSize(100, 100);
	if (maximize) { widget->showMaximized(); }
	widget->autoImageResize();
}

bool MainWindow::activeSubWindowIsMaximized() const
{
	const QWidget *widget = activeImageWidget();
	return (widget == NULL)
		? (mdiArea->viewMode() == QMdiArea::TabbedView)
		: widget->isMaximized();
}
