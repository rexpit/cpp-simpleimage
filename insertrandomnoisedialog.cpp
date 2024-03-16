#include "insertrandomnoisedialog.h"
#include "ui_insertrandomnoisedialog.h"

InsertRandomNoiseDialog::InsertRandomNoiseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertRandomNoiseDialog)
{
    ui->setupUi(this);
}

InsertRandomNoiseDialog::~InsertRandomNoiseDialog()
{
    delete ui;
}

double InsertRandomNoiseDialog::getDensity() const
{
    return 0.01 * ui->spinBoxDensity->value();
}
