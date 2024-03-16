#include "normfilterdialog.h"
#include "ui_normfilterdialog.h"
#include <QTextBlock>
#include <QMessageBox>
#include <QRegularExpression>
#pragma execution_character_set("utf-8")

NormFilterDialog::NormFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NormFilterDialog)
{
    ui->setupUi(this);
    setup();
}

NormFilterDialog::~NormFilterDialog()
{
    delete ui;
}

void NormFilterDialog::setup()
{
    filterList.append(FilterListItem(tr("勾配 (gradient)"), tr("0 -1 1"), tr("0\n-1\n1")));
    filterList.append(FilterListItem(tr("Roberts"), tr("0 0 0\n0 -1 0\n0 0 1"), tr("0 0 0\n0 0 1\n0 -1 0")));
    filterList.append(FilterListItem(tr("Prewitt"), tr("-1 0 1\n-1 0 1\n-1 0 1"), tr("-1 -1 -1\n0 0 0\n1 1 1")));
    filterList.append(FilterListItem(tr("Sobel"), tr("-1 0 1\n-2 0 2\n-1 0 1"), tr("-1 -2 -1\n0 0 0\n1 2 1")));

    for (auto it = filterList.begin(); it != filterList.end(); ++it) {
        ui->listWidgetFilter->addItem(it->text);
    }
}

void NormFilterDialog::setExampleFilter(int currentRow)
{
    // after
    if (currentRow < 0 || currentRow >= filterList.count()) {
        return;
    }
    const FilterListItem &filter = filterList[currentRow];
    ui->textEditX->setPlainText(filter.matrixX);
    ui->textEditY->setPlainText(filter.matrixY);
}

void NormFilterDialog::accept()
{
    // 行列のチェック
    const QVector< QVector<int> > matrixX(getMatrixX());
    const QVector< QVector<int> > matrixY(getMatrixY());
    class CheckMatrix {
        QWidget *parent;
    public:
        bool operator()(const QVector< QVector<int> > &matrix) const {
            if (matrix.empty()) {
                QMessageBox::warning(parent, tr("Error"), tr("行列の書式が不正です。"));
                return false;
            }
            if (matrix.size() % 2 == 0) {
                QMessageBox::warning(parent, tr("Error"), tr("行列の行数を奇数にしてください。"));
                return false;
            }
            const int colNum = matrix.first().size();
            if (colNum % 2 == 0) {
                QMessageBox::warning(parent, tr("Error"), tr("行列の列数を奇数にしてください。"));
                return false;
            }
            for (QVector< QVector<int> >::const_iterator it = matrix.begin(); it != matrix.end(); ++it) {
                if (it->size() != colNum) {
                    QMessageBox::warning(parent, tr("Error"), tr("各行の列数を統一してください。"));
                    return false;
                }
            }
            return true;
        }
        CheckMatrix(QWidget *a_parent) : parent(a_parent) {  }
    } checkMatrix(this);
    if (!(checkMatrix(matrixX) && checkMatrix(matrixY))) { return; }

    done(QDialog::Accepted);
}

QVector< QVector<int> > NormFilterDialog::getMatrixFromLineEdit(QTextEdit *edit) const
{   // 文字列から行列を得る
    QVector< QVector<int> > result;
    QTextCursor cr = edit->textCursor();
    cr.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
    for (QTextBlock block = cr.block(); block.isValid(); block = block.next()) {  // 行の走査
        const QString line = block.text();
        const QRegularExpression regExpSpTab(tr("[ \\t]+"));
        QStringList tokens = line.split(regExpSpTab);  // スペースでトークン分割
        if (!tokens.isEmpty() && tokens.first().isEmpty()) {
            tokens.removeFirst();
        }
        if (!tokens.isEmpty() && tokens.last().isEmpty()) {
            tokens.removeLast();
        }
        if (tokens.isEmpty()) {
            continue;
        }

        const QRegularExpression regExpInt(tr("^-?\\d+$"));
        QVector<int> row;
        for (auto it = tokens.begin(); it != tokens.end(); ++it) {
            if (!regExpInt.match(*it).hasMatch()) {
                result.clear();
                return result;
            }
            row.append(it->toInt());
        }
        result.append(row);
    }
    return result;
}

QVector< QVector<int> > NormFilterDialog::getMatrixX() const
{
    return getMatrixFromLineEdit(this->ui->textEditX);
}

QVector< QVector<int> > NormFilterDialog::getMatrixY() const
{
    return getMatrixFromLineEdit(this->ui->textEditY);
}
