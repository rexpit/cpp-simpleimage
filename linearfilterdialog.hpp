#ifndef LINEARFILTERDIALOG_HPP
#define LINEARFILTERDIALOG_HPP

#include <QDialog>
#include <QList>

namespace Ui {
class LinearFilterDialog;
}

class QListWidgetItem;

class LinearFilterDialog : public QDialog
{
	Q_OBJECT
	
public:
	explicit LinearFilterDialog(QWidget *parent = 0);
	~LinearFilterDialog();
	QVector< QVector<int> > getMatrix() const;	// 失敗時は空リストを返す
	int getDenominator() const;
	bool getAbsolute() const;

private slots:
	void setAutoByMatrix();
	void setExampleFilter(int currentRow);
	void accept();

private:
	struct FilterListItem {
		QString text;
		QString matrix;
		int denominator;
		bool absolute;
		FilterListItem(const QString& text, const QString &matrix, int denominator, bool absolute) :
			text(text), matrix(matrix), denominator(denominator), absolute(absolute) {}
	};
	Ui::LinearFilterDialog *ui;
	QList<FilterListItem> filterList;
	void setup();
};

#endif // LINEARFILTERDIALOG_HPP
