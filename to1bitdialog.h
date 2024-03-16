#ifndef TO1BITDIALOG_H
#define TO1BITDIALOG_H

#include <QDialog>

namespace Ui {
class To1BitDialog;
}

class To1BitDialog : public QDialog
{
    Q_OBJECT

public:
    enum WayTo1Bit {
        WayThresholdMethod,
        WayErrorDiffusionMethod,
        WayIllegal
    };
    explicit To1BitDialog(QWidget *parent = 0);
    ~To1BitDialog();
    WayTo1Bit getWayTo1Bit() const;
    int getThreshold() const;

private:
    Ui::To1BitDialog *ui;
};

#endif // TO1BITDIALOG_H
