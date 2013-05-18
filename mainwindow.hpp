#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QMdiArea;
class QLineEdit;
class ImageWidget;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);

signals:
	void editMagnificationChanged(qreal m);

private slots:
	void open();
	void openClipboard();
	void saveAs();
	void undo();
	void redo();
	void copy();
	void paste();
	void filterGrayscale();
	void filterTo1Bit();
	void linearFilter();
	void medianFilter();
	void normFilter();
	void filterInsertRandomNoise();
	void zoomIn();
	void zoomOut();
	void zoomFullScale();
	void setAutoImageResize(bool yes);
	void setTabVisible(bool view);
	void about();
	void aboutQt();
	void updateMenus();
	void setEditMagnification(qreal m);
	void setMagnificationFromEdit();

private:
	ImageWidget *createImageWidget();
	ImageWidget *activeImageWidget() const;
	void load(const QString &filePath);
	void resizeAndShowSubWidget(ImageWidget *widget, bool maximize);
	bool activeSubWindowIsMaximized() const;

	Ui::MainWindow *ui;
	QMdiArea *mdiArea;
	QLineEdit *editMagnification;
	ImageWidget *m_activeWindow;

};

#endif // MAINWINDOW_HPP
