QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp\
    mainwindow.cpp \
    imagefilter.cpp \
    to1bitdialog.cpp \
    linearfilterdialog.cpp \
    imagewidget.cpp \
    normfilterdialog.cpp \
    insertrandomnoisedialog.cpp

HEADERS  += \
    common.h \
    imagefilter.h \
    imagewidget.h \
    insertrandomnoisedialog.h \
    linearfilterdialog.h \
    mainwindow.h \
    normfilterdialog.h \
    to1bitdialog.h

FORMS    += mainwindow.ui \
    to1bitdialog.ui \
    linearfilterdialog.ui \
    normfilterdialog.ui \
    insertrandomnoisedialog.ui

RESOURCES += \
    resource.qrc

win32:RC_FILE += icon.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
