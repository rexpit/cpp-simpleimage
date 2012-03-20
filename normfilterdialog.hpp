#ifndef NORMFILTERDIALOG_HPP
#define NORMFILTERDIALOG_HPP

#include <QDialog>
#include <QHash>

namespace Ui {
class NormFilterDialog;
}

class QListWidgetItem;
class QTextEdit;

class NormFilterDialog : public QDialog
{
	Q_OBJECT
	
public:
	explicit NormFilterDialog(QWidget *parent = 0);
	~NormFilterDialog();
	QVector< QVector<int> > getMatrixX() const;	// ���s���͋󃊃X�g��Ԃ�
	QVector< QVector<int> > getMatrixY() const;	// ���s���͋󃊃X�g��Ԃ�

private slots:
	void setExampleFilter(QListWidgetItem *listItem);
	void accept();

private:
	Ui::NormFilterDialog *ui;
	struct FilterListItem {
		QString matrixX, matrixY;
		FilterListItem(const QString &a_matrixX, const QString &a_matrixY) :
			matrixX(a_matrixX), matrixY(a_matrixY) {}
	};
	QHash<QString, FilterListItem> filterHash;
	void setup();
	QVector< QVector<int> > getMatrixFromLineEdit(QTextEdit *edit) const;
};

#endif // NORMFILTERDIALOG_HPP
