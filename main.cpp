#include <QApplication>
#include <QTextCodec>
#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
	MainWindow w;
	w.show();

	return a.exec();
}
