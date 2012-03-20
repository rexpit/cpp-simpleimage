#include "linearfilterdialog.hpp"
#include "ui_linearfilterdialog.h"
#include <QTextBlock>
#include <QMessageBox>

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
	QStringList keyList;
	keyList.append(tr("�������t�B���^ (3x3 ���d����)")); filterHash.insert(keyList.last(), FilterListItem(tr("1 2 1\n2 4 2\n1 2 1"), 16, false));
	keyList.append(tr("�������t�B���^ (3x3 ����)")); filterHash.insert(keyList.last(), FilterListItem(tr("1 1 1\n1 1 1\n1 1 1"), 9, false));
	keyList.append(tr("�������t�B���^ (5x5 ����)")); filterHash.insert(keyList.last(), FilterListItem(tr("1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1\n1 1 1 1 1"), 25, false));
	keyList.append(tr("�N�s���t�B���^ (4�ߖT)")); filterHash.insert(keyList.last(), FilterListItem(tr("0 -1 0\n-1 5 -1\n0 -1 0"), 1, false));
	keyList.append(tr("�N�s���t�B���^ (8�ߖT)")); filterHash.insert(keyList.last(), FilterListItem(tr("-1 -1 -1\n-1 9 -1\n-1 -1 -1"), 1, false));
	keyList.append(tr("�����t�B���^ (��)")); filterHash.insert(keyList.last(), FilterListItem(tr("0 -1 1"), 1, true));
	keyList.append(tr("�����t�B���^ (�c)")); filterHash.insert(keyList.last(), FilterListItem(tr("0\n-1\n1"), 1, true));
	keyList.append(tr("���v���V�A���t�B���^ (4�ߖT)")); filterHash.insert(keyList.last(), FilterListItem(tr("0 1 0\n1 -4 1\n0 1 0"), 1, true));
	keyList.append(tr("���v���V�A���t�B���^ (8�ߖT)")); filterHash.insert(keyList.last(), FilterListItem(tr("1 1 1\n1 -8 1\n1 1 1"), 1, true));

	for (QList<QString>::iterator it = keyList.begin(); it != keyList.end(); ++it) {
		ui->listWidgetFilter->addItem(*it);
	}
}

void LinearFilterDialog::setAutoByMatrix()
{
	QVector< QVector<int> > matrix(getMatrix());
	if (matrix.isEmpty()) { return; }
	int sum = 0;
	for (QVector< QVector<int> >::iterator lit = matrix.begin(); lit != matrix.end(); ++lit) {
		for (QVector<int>::iterator it = lit->begin(); it != lit->end(); ++it) {
			sum += *it;
		}
	}
	const int denominator = (sum < 0) ? -sum : (sum == 0) ? 1 : sum;
	this->ui->lineEditD->setText(QString::number(denominator));
	if (sum == 0) {
		this->ui->radioButtonA->click();
	} else {
		this->ui->radioButtonZ->click();
	}
}

void LinearFilterDialog::setExampleFilter(QListWidgetItem *listItem)
{
	QHash<QString, FilterListItem>::iterator it = filterHash.find(listItem->text());
	if (it == filterHash.end()) { return; }
	ui->textEditM->setPlainText(it->matrix);
	ui->lineEditD->setText(QString::number(it->denominator));
	if (it->absolute) {
		ui->radioButtonA->click();
	} else {
		ui->radioButtonZ->click();
	}
}

void LinearFilterDialog::accept()
{
	// �s��̃`�F�b�N
	const QVector< QVector<int> > matrix(getMatrix());
	if (matrix.empty()) {
		QMessageBox::warning(this, tr("Error"), tr("�s��̏������s���ł��B"));
		return;
	}
	if (matrix.size() % 2 == 0) {
		QMessageBox::warning(this, tr("Error"), tr("�s��̍s������ɂ��Ă��������B"));
		return;
	}
	const int colNum = matrix.first().size();
	if (colNum % 2 == 0) {
		QMessageBox::warning(this, tr("Error"), tr("�s��̗񐔂���ɂ��Ă��������B"));
		return;
	}
	for (QVector< QVector<int> >::const_iterator it = matrix.begin(); it != matrix.end(); ++it) {
		if (it->size() != colNum) {
			QMessageBox::warning(this, tr("Error"), tr("�e�s�̗񐔂𓝈ꂵ�Ă��������B"));
			return;
		}
	}
	// ����̃`�F�b�N
	if (!QRegExp(tr("^-?\\d+$")).exactMatch(this->ui->lineEditD->text())) {
		QMessageBox::warning(this, tr("Error"), tr("����𐮐��ɂ��Ă��������B"));
		return;
	}
	if (this->ui->lineEditD->text().toInt() == 0) {
		QMessageBox::warning(this, tr("Error"), tr("����� 0 �ȊO�ɂ��Ă��������B"));
		return;
	}

	done(QDialog::Accepted);
}

QVector< QVector<int> > LinearFilterDialog::getMatrix() const
{	// �����񂩂�s��𓾂�
	QVector< QVector<int> > result;
	QTextCursor cr = this->ui->textEditM->textCursor();
	cr.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
	for (QTextBlock block = cr.block(); block.isValid(); block = block.next()) {	// �s�̑���
		const QString line = block.text();
		const QRegExp regExpSpTab(tr("[ \\t]+"));
		QStringList tokens = line.split(regExpSpTab);	// �X�y�[�X�Ńg�[�N������
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

int LinearFilterDialog::getDenominator() const
{
	return this->ui->lineEditD->text().toInt();
}

bool LinearFilterDialog::getAbsolute() const
{
	return this->ui->radioButtonA->isChecked();
}
