#ifndef INSERTNOISEDIALOG_H
#define INSERTNOISEDIALOG_H

#include <QDialog>

namespace Ui {
class InsertRandomNoiseDialog;
}

class InsertRandomNoiseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsertRandomNoiseDialog(QWidget *parent = 0);
    ~InsertRandomNoiseDialog();
    double getDensity() const;

private:
    Ui::InsertRandomNoiseDialog *ui;
};

#endif // INSERTNOISEDIALOG_H
