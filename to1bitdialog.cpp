#include "to1bitdialog.h"
#include "ui_to1bitdialog.h"

To1BitDialog::To1BitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::To1BitDialog)
{
    ui->setupUi(this);
}

To1BitDialog::~To1BitDialog()
{
    delete ui;
}

To1BitDialog::WayTo1Bit To1BitDialog::getWayTo1Bit() const
{
    return this->ui->radioButtonB->isChecked()
        ? WayThresholdMethod
        : this->ui->radioButtonE->isChecked()
            ? WayErrorDiffusionMethod
            : WayIllegal;
}

int To1BitDialog::getThreshold() const
{
    return this->ui->spinBoxT->value();
}
