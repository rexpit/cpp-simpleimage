#include "linearfilterdialog.h"
#include "ui_linearfilterdialog.h"
#include <QTextBlock>
#include <QMessageBox>
#include <QRegularExpression>
#pragma execution_character_set("utf-8")

LinearFilterDialog::LinearFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LinearFilterDialog)
{
    ui->setupUi(this);
    setup();
}

LinearFilterDialog::~LinearFilterDialog()
{
    delete ui;
}

void LinearFilterDialog::setup()
{
    filterList.append(FilterListItem(tr("平滑化フィルタ (3x3 加重平均)"), tr("1 2 1\n2 4 2\n1 2 1"), 16, false));
    filterList.append(FilterListItem(tr("平滑化フィルタ (3x3 平均)"), tr("1 1 1\n1 1 1\n1 1 1"), 9, false));
    filterList.append(FilterListItem(tr("平滑化フィルタ (5x5 平均)"), tr("1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1"), 25, false));
    filterList.append(FilterListItem(tr("鮮鋭化フィルタ (4近傍)"), tr("0 -1 0\n-1 5 -1\n0 -1 0"), 1, false));
    filterList.append(FilterListItem(tr("鮮鋭化フィルタ (8近傍)"), tr("-1 -1 -1\n-1 9 -1\n-1 -1 -1"), 1, false));
    filterList.append(FilterListItem(tr("微分フィルタ (横)"), tr("0 -1 1"), 1, true));
    filterList.append(FilterListItem(tr("微分フィルタ (縦)"), tr("0\n-1\n1"), 1, true));
    filterList.append(FilterListItem(tr("ラプラシアンフィルタ (4近傍)"), tr("0 1 0\n1 -4 1\n0 1 0"), 1, true));
    filterList.append(FilterListItem(tr("ラプラシアンフィルタ (8近傍)"), tr("1 1 1\n1 -8 1\n1 1 1"), 1, true));

    for (auto it = filterList.begin(); it != filterList.end(); ++it) {
        ui->listWidgetFilter->addItem(it->text);
    }
}

void LinearFilterDialog::setAutoByMatrix()
{
    QVector< QVector<int> > matrix(getMatrix());
    if (matrix.isEmpty()) {
        return;
    }
    int sum = 0;
    for (auto lit = matrix.begin(); lit != matrix.end(); ++lit) {
        for (auto it = lit->begin(); it != lit->end(); ++it) {
            sum += *it;
        }
    }
    const int denominator = (sum < 0)
        ? -sum
        : (sum == 0)
            ? 1
            : sum;
    this->ui->lineEditD->setText(QString::number(denominator));
    if (sum == 0) {
        this->ui->radioButtonA->click();
    } else {
        this->ui->radioButtonZ->click();
    }
}

void LinearFilterDialog::setExampleFilter(const int currentRow)
{
    // after
    if (currentRow < 0 || currentRow >= filterList.count()) {
        return;
    }
    const FilterListItem &filter = filterList[currentRow];
    ui->textEditM->setPlainText(filter.matrix);
    ui->lineEditD->setText(QString::number((filter.denominator)));
    if (filter.absolute) {
        ui->radioButtonA->click();
    } else {
        ui->radioButtonZ->click();
    }
}

void LinearFilterDialog::accept()
{
    // 行列のチェック
    const QVector< QVector<int> > matrix(getMatrix());
    if (matrix.empty()) {
        QMessageBox::warning(this, tr("Error"), tr("行列の書式が不正です。"));
        return;
    }
    if (matrix.size() % 2 == 0) {
        QMessageBox::warning(this, tr("Error"), tr("行列の行数を奇数にしてください。"));
        return;
    }
    const int colNum = matrix.first().size();
    if (colNum % 2 == 0) {
        QMessageBox::warning(this, tr("Error"), tr("行列の列数を奇数にしてください。"));
        return;
    }
    for (auto it = matrix.begin(); it != matrix.end(); ++it) {
        if (it->size() != colNum) {
            QMessageBox::warning(this, tr("Error"), tr("各行の列数を統一してください。"));
            return;
        }
    }
    // 分母のチェック
    if (!QRegularExpression(tr("^-?\\d+$")).match(this->ui->lineEditD->text()).hasMatch()) {
        QMessageBox::warning(this, tr("Error"), tr("分母を整数にしてください。"));
        return;
    }
    if (this->ui->lineEditD->text().toInt() == 0) {
        QMessageBox::warning(this, tr("Error"), tr("分母を 0 以外にしてください。"));
        return;
    }

    done(QDialog::Accepted);
}

QVector< QVector<int> > LinearFilterDialog::getMatrix() const
{   // 文字列から行列を得る
    QVector< QVector<int> > result;
    QTextCursor cr = this->ui->textEditM->textCursor();
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
                result.clear(); return result;
            }
            row.append(it->toInt());
        }
        result.append(row);
    }
    return result;
}

int LinearFilterDialog::getDenominator() const
{
    return this->ui->lineEditD->text().toInt();
}

bool LinearFilterDialog::getAbsolute() const
{
    return this->ui->radioButtonA->isChecked();
}
