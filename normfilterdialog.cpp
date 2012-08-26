#include "normfilterdialog.hpp"
#include "ui_normfilterdialog.h"
#include <QTextBlock>
#include <QMessageBox>

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
	QStringList keyList;
	keyList.append(tr("勾配 (gradient)")); filterHash.insert(keyList.last(), FilterListItem(tr("0 -1 1"), tr("0\n-1\n1")));
	keyList.append(tr("Roberts")); filterHash.insert(keyList.last(), FilterListItem(tr("0 0 0\n0 -1 0\n0 0 1"), tr("0 0 0\n0 0 1\n0 -1 0")));
	keyList.append(tr("Prewitt")); filterHash.insert(keyList.last(), FilterListItem(tr("-1 0 1\n-1 0 1\n-1 0 1"), tr("-1 -1 -1\n0 0 0\n1 1 1")));
	keyList.append(tr("Sobel")); filterHash.insert(keyList.last(), FilterListItem(tr("-1 0 1\n-2 0 2\n-1 0 1"), tr("-1 -2 -1\n0 0 0\n1 2 1")));

	for (QList<QString>::iterator it = keyList.begin(); it != keyList.end(); ++it) {
		ui->listWidgetFilter->addItem(*it);
	}
}

void NormFilterDialog::setExampleFilter(QListWidgetItem *listItem)
{
	QHash<QString, FilterListItem>::iterator it = filterHash.find(listItem->text());
	if (it == filterHash.end()) { return; }
	ui->textEditX->setPlainText(it->matrixX);
	ui->textEditY->setPlainText(it->matrixY);
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
{	// 文字列から行列を得る
	QVector< QVector<int> > result;
	QTextCursor cr = edit->textCursor();
	cr.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
	for (QTextBlock block = cr.block(); block.isValid(); block = block.next()) {	// 行の走査
		const QString line = block.text();
		const QRegExp regExpSpTab(tr("[ \\t]+"));
		QStringList tokens = line.split(regExpSpTab);	// スペースでトークン分割
		if (!tokens.isEmpty() && tokens.first().isEmpty()) { tokens.removeFirst(); }
		if (!tokens.isEmpty() && tokens.last().isEmpty()) { tokens.removeLast(); }
		if (tokens.isEmpty()) { continue; }

		const QRegExp regExpInt(tr("^-?\\d+$"));
		QVector<int> row;
		for (QStringList::Iterator it = tokens.begin(); it != tokens.end(); ++it) {
			if (!regExpInt.exactMatch(*it)) { result.clear(); return result; }
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
