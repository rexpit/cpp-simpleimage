#-------------------------------------------------
#
# Project created by QtCreator 2012-03-06T11:35:41
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleImage
TEMPLATE = app


SOURCES += main.cpp\
	mainwindow.cpp \
	imagefilter.cpp \
	to1bitdialog.cpp \
	linearfilterdialog.cpp \
	imagewidget.cpp \
	normfilterdialog.cpp \
    insertrandomnoisedialog.cpp

HEADERS  += mainwindow.hpp \
	imagefilter.hpp \
	to1bitdialog.hpp \
	linearfilterdialog.hpp \
	imagewidget.hpp \
	normfilterdialog.hpp \
	common.hpp \
    insertrandomnoisedialog.hpp

FORMS    += mainwindow.ui \
	to1bitdialog.ui \
	linearfilterdialog.ui \
	normfilterdialog.ui \
    insertrandomnoisedialog.ui

RESOURCES += \
	resource.qrc

win32:RC_FILE += icon.rc
