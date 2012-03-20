#ifndef LINEARFILTERDIALOG_HPP
#define LINEARFILTERDIALOG_HPP

#include <QDialog>
#include <QHash>

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
	QVector< QVector<int> > getMatrix() const;	// Ž¸”sŽž‚Í‹óƒŠƒXƒg‚ð•Ô‚·
	int getDenominator() const;
	bool getAbsolute() const;

private slots:
	void setAutoByMatrix();
	void setExampleFilter(QListWidgetItem *listItem);
	void accept();

private:
	struct FilterListItem {
		QString matrix;
		int denominator;
		bool absolute;
		FilterListItem(const QString &matrix, int denominator, bool absolute) :
			matrix(matrix), denominator(denominator), absolute(absolute) {}
	};
	Ui::LinearFilterDialog *ui;
	QHash<QString, FilterListItem> filterHash;
	void setup();
};

#endif // LINEARFILTERDIALOG_HPP
