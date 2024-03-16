#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QUndoStack;
class QLabel;

class ImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageWidget(QWidget *parent = 0);
    QImage image() const;
    QString filePath() const;
    QSize sizeHint() const;
    void setImage(const QImage &image);
    void paste(const QImage &image);
    bool load(const QString &filePath);
    bool save(const QString &filePath);
    bool canUndo() const;
    bool canRedo() const;
    QString redoText() const;
    QString undoText() const;
    void zoom(qreal m);
    void autoImageResize();
    bool canZoomIn() const;
    bool canZoomOut() const;
    qreal magnification() const;
    bool isAutoImageResize() const;

signals:
    void canRedoChanged(bool canRedo);
    void canUndoChanged(bool canUndo);
    void cleanChanged(bool clean);
    void undoTextChanged(const QString &undoText);
    void redoTextChanged(const QString &redoText);
    void canZoomInChanged(bool canZoomIn);
    void canZoomOutChanged(bool canZoomOut);
    void magnificationChanged(qreal m);
    void autoImageResizeChanged(bool flag);

public slots:
    void undo();
    void redo();
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

protected:
    void resizeEvent(QResizeEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    void updateImageLabel();
    void emitZoomStateChanged();

    QImage m_image;
    QLabel *m_imageLabel;
    QUndoStack *m_stack;
    QString m_filePath;
    qreal m_magnification;
    bool m_flagAutoImageResize;
};

#endif // WIDGET_H
