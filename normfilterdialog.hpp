#ifndef NORMFILTERDIALOG_HPP
#define NORMFILTERDIALOG_HPP

#include <QDialog>
#include <QList>

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
	QVector< QVector<int> > getMatrixX() const;	// 失敗時は空リストを返す
	QVector< QVector<int> > getMatrixY() const;	// 失敗時は空リストを返す

private slots:
	void setExampleFilter(int currentRow);
	void accept();

private:
	Ui::NormFilterDialog *ui;
	void setup();
	struct FilterListItem {
		QString text;
		QString matrixX, matrixY;
		FilterListItem(const QString& a_text, const QString& a_matrixX, const QString &a_matrixY) :
			text(a_text), matrixX(a_matrixX), matrixY(a_matrixY) {}
	};
	QList<FilterListItem> filterList;
	QVector< QVector<int> > getMatrixFromLineEdit(QTextEdit *edit) const;
};

#endif // NORMFILTERDIALOG_HPP
