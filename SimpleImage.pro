#-------------------------------------------------
#
# Project created by QtCreator 2012-03-06T11:35:41
#
#-------------------------------------------------

QT       += core gui

TARGET = SimpleImage
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imagefilter.cpp \
    to1bitdialog.cpp \
    linearfilterdialog.cpp \
    imagewidget.cpp \
    normfilterdialog.cpp

HEADERS  += mainwindow.hpp \
    imagefilter.hpp \
    to1bitdialog.hpp \
    linearfilterdialog.hpp \
    imagewidget.hpp \
    normfilterdialog.hpp \
    common.hpp

FORMS    += mainwindow.ui \
    to1bitdialog.ui \
    linearfilterdialog.ui \
    normfilterdialog.ui

RESOURCES += \
    resource.qrc

win32:RC_FILE += icon.rc
