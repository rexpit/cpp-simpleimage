/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Mar 16 13:30:42 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openAct;
    QAction *saveAsAct;
    QAction *closeAct;
    QAction *aboutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *statusBarVisibleAct;
    QAction *aboutQtAct;
    QAction *filterGrayscaleAct;
    QAction *undoAct;
    QAction *redoAct;
    QAction *filterTo1BitAct;
    QAction *linearFilterAct;
    QAction *medianFilterAct;
    QAction *fileToolBarVisibleAct;
    QAction *normFilterAct;
    QAction *filterToolBarVisibleAct;
    QAction *editToolBarVisibleAct;
    QAction *openClipboardAct;
    QAction *tabVisibleAct;
    QAction *zoomToolBarVisibleAct;
    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *zoomFullScaleAct;
    QAction *autoImageResizeAct;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuToolBar;
    QMenu *menuZoom;
    QMenu *menuOperate;
    QMenu *menuOpeColor;
    QMenu *menuOpeFilter;
    QStatusBar *statusBar;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QToolBar *filterToolBar;
    QToolBar *zoomToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(758, 479);
        MainWindow->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon/filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        openAct = new QAction(MainWindow);
        openAct->setObjectName(QString::fromUtf8("openAct"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/icon/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openAct->setIcon(icon1);
        saveAsAct = new QAction(MainWindow);
        saveAsAct->setObjectName(QString::fromUtf8("saveAsAct"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/icon/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveAsAct->setIcon(icon2);
        closeAct = new QAction(MainWindow);
        closeAct->setObjectName(QString::fromUtf8("closeAct"));
        aboutAct = new QAction(MainWindow);
        aboutAct->setObjectName(QString::fromUtf8("aboutAct"));
        copyAct = new QAction(MainWindow);
        copyAct->setObjectName(QString::fromUtf8("copyAct"));
        copyAct->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/icon/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        copyAct->setIcon(icon3);
        pasteAct = new QAction(MainWindow);
        pasteAct->setObjectName(QString::fromUtf8("pasteAct"));
        pasteAct->setEnabled(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/icon/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        pasteAct->setIcon(icon4);
        statusBarVisibleAct = new QAction(MainWindow);
        statusBarVisibleAct->setObjectName(QString::fromUtf8("statusBarVisibleAct"));
        statusBarVisibleAct->setCheckable(true);
        statusBarVisibleAct->setChecked(true);
        aboutQtAct = new QAction(MainWindow);
        aboutQtAct->setObjectName(QString::fromUtf8("aboutQtAct"));
        filterGrayscaleAct = new QAction(MainWindow);
        filterGrayscaleAct->setObjectName(QString::fromUtf8("filterGrayscaleAct"));
        undoAct = new QAction(MainWindow);
        undoAct->setObjectName(QString::fromUtf8("undoAct"));
        undoAct->setEnabled(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/icon/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        undoAct->setIcon(icon5);
        redoAct = new QAction(MainWindow);
        redoAct->setObjectName(QString::fromUtf8("redoAct"));
        redoAct->setEnabled(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/icon/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        redoAct->setIcon(icon6);
        filterTo1BitAct = new QAction(MainWindow);
        filterTo1BitAct->setObjectName(QString::fromUtf8("filterTo1BitAct"));
        linearFilterAct = new QAction(MainWindow);
        linearFilterAct->setObjectName(QString::fromUtf8("linearFilterAct"));
        linearFilterAct->setIcon(icon);
        medianFilterAct = new QAction(MainWindow);
        medianFilterAct->setObjectName(QString::fromUtf8("medianFilterAct"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/icon/median.png"), QSize(), QIcon::Normal, QIcon::Off);
        medianFilterAct->setIcon(icon7);
        fileToolBarVisibleAct = new QAction(MainWindow);
        fileToolBarVisibleAct->setObjectName(QString::fromUtf8("fileToolBarVisibleAct"));
        fileToolBarVisibleAct->setCheckable(true);
        fileToolBarVisibleAct->setChecked(true);
        normFilterAct = new QAction(MainWindow);
        normFilterAct->setObjectName(QString::fromUtf8("normFilterAct"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/icon/norm.png"), QSize(), QIcon::Normal, QIcon::Off);
        normFilterAct->setIcon(icon8);
        filterToolBarVisibleAct = new QAction(MainWindow);
        filterToolBarVisibleAct->setObjectName(QString::fromUtf8("filterToolBarVisibleAct"));
        filterToolBarVisibleAct->setCheckable(true);
        editToolBarVisibleAct = new QAction(MainWindow);
        editToolBarVisibleAct->setObjectName(QString::fromUtf8("editToolBarVisibleAct"));
        editToolBarVisibleAct->setCheckable(true);
        openClipboardAct = new QAction(MainWindow);
        openClipboardAct->setObjectName(QString::fromUtf8("openClipboardAct"));
        tabVisibleAct = new QAction(MainWindow);
        tabVisibleAct->setObjectName(QString::fromUtf8("tabVisibleAct"));
        tabVisibleAct->setCheckable(true);
        zoomToolBarVisibleAct = new QAction(MainWindow);
        zoomToolBarVisibleAct->setObjectName(QString::fromUtf8("zoomToolBarVisibleAct"));
        zoomToolBarVisibleAct->setCheckable(true);
        zoomInAct = new QAction(MainWindow);
        zoomInAct->setObjectName(QString::fromUtf8("zoomInAct"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/icon/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomInAct->setIcon(icon9);
        zoomOutAct = new QAction(MainWindow);
        zoomOutAct->setObjectName(QString::fromUtf8("zoomOutAct"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icon/icon/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomOutAct->setIcon(icon10);
        zoomFullScaleAct = new QAction(MainWindow);
        zoomFullScaleAct->setObjectName(QString::fromUtf8("zoomFullScaleAct"));
        autoImageResizeAct = new QAction(MainWindow);
        autoImageResizeAct->setObjectName(QString::fromUtf8("autoImageResizeAct"));
        autoImageResizeAct->setCheckable(true);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 758, 24));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuEdit->setEnabled(true);
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuToolBar = new QMenu(menuView);
        menuToolBar->setObjectName(QString::fromUtf8("menuToolBar"));
        menuZoom = new QMenu(menuView);
        menuZoom->setObjectName(QString::fromUtf8("menuZoom"));
        menuOperate = new QMenu(menuBar);
        menuOperate->setObjectName(QString::fromUtf8("menuOperate"));
        menuOpeColor = new QMenu(menuOperate);
        menuOpeColor->setObjectName(QString::fromUtf8("menuOpeColor"));
        menuOpeFilter = new QMenu(menuOperate);
        menuOpeFilter->setObjectName(QString::fromUtf8("menuOpeFilter"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setAutoFillBackground(true);
        MainWindow->setStatusBar(statusBar);
        fileToolBar = new QToolBar(MainWindow);
        fileToolBar->setObjectName(QString::fromUtf8("fileToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, fileToolBar);
        editToolBar = new QToolBar(MainWindow);
        editToolBar->setObjectName(QString::fromUtf8("editToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, editToolBar);
        filterToolBar = new QToolBar(MainWindow);
        filterToolBar->setObjectName(QString::fromUtf8("filterToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, filterToolBar);
        zoomToolBar = new QToolBar(MainWindow);
        zoomToolBar->setObjectName(QString::fromUtf8("zoomToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, zoomToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuOperate->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(openAct);
        menuFile->addAction(openClipboardAct);
        menuFile->addAction(saveAsAct);
        menuFile->addSeparator();
        menuFile->addAction(closeAct);
        menuHelp->addAction(aboutAct);
        menuHelp->addAction(aboutQtAct);
        menuEdit->addAction(undoAct);
        menuEdit->addAction(redoAct);
        menuEdit->addSeparator();
        menuEdit->addAction(copyAct);
        menuEdit->addAction(pasteAct);
        menuView->addAction(menuZoom->menuAction());
        menuView->addSeparator();
        menuView->addAction(menuToolBar->menuAction());
        menuView->addAction(statusBarVisibleAct);
        menuView->addAction(tabVisibleAct);
        menuToolBar->addAction(fileToolBarVisibleAct);
        menuToolBar->addAction(editToolBarVisibleAct);
        menuToolBar->addAction(filterToolBarVisibleAct);
        menuToolBar->addAction(zoomToolBarVisibleAct);
        menuZoom->addAction(zoomFullScaleAct);
        menuZoom->addAction(autoImageResizeAct);
        menuZoom->addAction(zoomInAct);
        menuZoom->addAction(zoomOutAct);
        menuOperate->addAction(menuOpeColor->menuAction());
        menuOperate->addAction(menuOpeFilter->menuAction());
        menuOpeColor->addAction(filterGrayscaleAct);
        menuOpeColor->addAction(filterTo1BitAct);
        menuOpeFilter->addAction(linearFilterAct);
        menuOpeFilter->addAction(medianFilterAct);
        menuOpeFilter->addAction(normFilterAct);
        fileToolBar->addAction(openAct);
        fileToolBar->addAction(saveAsAct);
        editToolBar->addAction(undoAct);
        editToolBar->addAction(redoAct);
        editToolBar->addSeparator();
        editToolBar->addAction(copyAct);
        editToolBar->addAction(pasteAct);
        filterToolBar->addAction(linearFilterAct);
        filterToolBar->addAction(medianFilterAct);
        filterToolBar->addAction(normFilterAct);
        zoomToolBar->addAction(zoomInAct);
        zoomToolBar->addAction(zoomOutAct);

        retranslateUi(MainWindow);
        QObject::connect(closeAct, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(aboutAct, SIGNAL(triggered()), MainWindow, SLOT(about()));
        QObject::connect(aboutQtAct, SIGNAL(triggered()), MainWindow, SLOT(aboutQt()));
        QObject::connect(openAct, SIGNAL(triggered()), MainWindow, SLOT(open()));
        QObject::connect(saveAsAct, SIGNAL(triggered()), MainWindow, SLOT(saveAs()));
        QObject::connect(statusBarVisibleAct, SIGNAL(triggered(bool)), statusBar, SLOT(setVisible(bool)));
        QObject::connect(copyAct, SIGNAL(triggered()), MainWindow, SLOT(copy()));
        QObject::connect(pasteAct, SIGNAL(triggered()), MainWindow, SLOT(paste()));
        QObject::connect(fileToolBarVisibleAct, SIGNAL(triggered(bool)), fileToolBar, SLOT(setVisible(bool)));
        QObject::connect(fileToolBar, SIGNAL(visibilityChanged(bool)), fileToolBarVisibleAct, SLOT(setChecked(bool)));
        QObject::connect(filterToolBarVisibleAct, SIGNAL(triggered(bool)), filterToolBar, SLOT(setVisible(bool)));
        QObject::connect(filterToolBar, SIGNAL(visibilityChanged(bool)), filterToolBarVisibleAct, SLOT(setChecked(bool)));
        QObject::connect(editToolBarVisibleAct, SIGNAL(triggered(bool)), editToolBar, SLOT(setVisible(bool)));
        QObject::connect(editToolBar, SIGNAL(visibilityChanged(bool)), editToolBarVisibleAct, SLOT(setChecked(bool)));
        QObject::connect(filterGrayscaleAct, SIGNAL(triggered()), MainWindow, SLOT(filterGrayscale()));
        QObject::connect(filterTo1BitAct, SIGNAL(triggered()), MainWindow, SLOT(filterTo1Bit()));
        QObject::connect(linearFilterAct, SIGNAL(triggered()), MainWindow, SLOT(linearFilter()));
        QObject::connect(medianFilterAct, SIGNAL(triggered()), MainWindow, SLOT(medianFilter()));
        QObject::connect(normFilterAct, SIGNAL(triggered()), MainWindow, SLOT(normFilter()));
        QObject::connect(undoAct, SIGNAL(triggered()), MainWindow, SLOT(undo()));
        QObject::connect(redoAct, SIGNAL(triggered()), MainWindow, SLOT(redo()));
        QObject::connect(openClipboardAct, SIGNAL(triggered()), MainWindow, SLOT(openClipboard()));
        QObject::connect(tabVisibleAct, SIGNAL(triggered(bool)), MainWindow, SLOT(setTabVisible(bool)));
        QObject::connect(zoomToolBarVisibleAct, SIGNAL(triggered(bool)), zoomToolBar, SLOT(setVisible(bool)));
        QObject::connect(zoomToolBar, SIGNAL(visibilityChanged(bool)), zoomToolBarVisibleAct, SLOT(setChecked(bool)));
        QObject::connect(zoomInAct, SIGNAL(triggered()), MainWindow, SLOT(zoomIn()));
        QObject::connect(zoomOutAct, SIGNAL(triggered()), MainWindow, SLOT(zoomOut()));
        QObject::connect(zoomFullScaleAct, SIGNAL(triggered()), MainWindow, SLOT(zoomFullScale()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Simple Image", 0, QApplication::UnicodeUTF8));
        openAct->setText(QApplication::translate("MainWindow", "\351\226\213\343\201\217(&O)...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        openAct->setStatusTip(QApplication::translate("MainWindow", "\343\203\225\343\202\241\343\202\244\343\203\253\343\202\222\351\226\213\343\201\215\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        openAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        saveAsAct->setText(QApplication::translate("MainWindow", "\345\220\215\345\211\215\343\202\222\344\273\230\343\201\221\343\201\246\344\277\235\345\255\230(&A)...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        saveAsAct->setToolTip(QApplication::translate("MainWindow", "\345\220\215\345\211\215\343\202\222\344\273\230\343\201\221\343\201\246\344\277\235\345\255\230(A)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        saveAsAct->setStatusTip(QApplication::translate("MainWindow", "\343\203\225\343\202\241\343\202\244\343\203\253\343\201\253\344\277\235\345\255\230\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        saveAsAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        closeAct->setText(QApplication::translate("MainWindow", "\351\226\211\343\201\230\343\202\213(&X)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        closeAct->setStatusTip(QApplication::translate("MainWindow", "\343\203\227\343\203\255\343\202\260\343\203\251\343\203\240\343\202\222\347\265\202\344\272\206\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        aboutAct->setText(QApplication::translate("MainWindow", "\343\203\220\343\203\274\343\202\270\343\203\247\343\203\263\346\203\205\345\240\261(&A)", 0, QApplication::UnicodeUTF8));
        copyAct->setText(QApplication::translate("MainWindow", "\343\202\263\343\203\224\343\203\274(&C)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        copyAct->setStatusTip(QApplication::translate("MainWindow", "\347\267\250\351\233\206\344\270\255\343\201\256\347\224\273\345\203\217\343\202\222\343\202\257\343\203\252\343\203\203\343\203\227\343\203\234\343\203\274\343\203\211\343\201\253\343\202\263\343\203\224\343\203\274\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        copyAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        pasteAct->setText(QApplication::translate("MainWindow", "\350\262\274\343\202\212\344\273\230\343\201\221(&P)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        pasteAct->setStatusTip(QApplication::translate("MainWindow", "\343\202\257\343\203\252\343\203\203\343\203\227\343\203\234\343\203\274\343\203\211\343\201\256\347\224\273\345\203\217\343\202\222\350\262\274\343\202\212\344\273\230\343\201\221\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pasteAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        statusBarVisibleAct->setText(QApplication::translate("MainWindow", "\343\202\271\343\203\206\343\203\274\343\202\277\343\202\271\343\203\220\343\203\274(&S)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        statusBarVisibleAct->setStatusTip(QApplication::translate("MainWindow", "\343\202\271\343\203\206\343\203\274\343\202\277\343\202\271\343\203\220\343\203\274\343\202\222\351\232\240\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        aboutQtAct->setText(QApplication::translate("MainWindow", "About &Qt", 0, QApplication::UnicodeUTF8));
        filterGrayscaleAct->setText(QApplication::translate("MainWindow", "\343\202\260\343\203\254\343\203\274\343\202\271\343\202\261\343\203\274\343\203\253\345\214\226(&G)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        filterGrayscaleAct->setStatusTip(QApplication::translate("MainWindow", "\343\202\253\343\203\251\343\203\274\347\224\273\345\203\217\343\202\222\350\274\235\345\272\246\345\200\244\343\201\213\343\202\211\343\202\260\343\203\254\343\203\274\343\202\271\343\202\261\343\203\274\343\203\253\343\201\253\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        undoAct->setText(QApplication::translate("MainWindow", "\345\205\203\343\201\253\346\210\273\343\201\231(&Z)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        undoAct->setStatusTip(QApplication::translate("MainWindow", "\345\211\215\343\201\256\346\223\215\344\275\234\343\201\253\346\210\273\343\202\212\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        undoAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        redoAct->setText(QApplication::translate("MainWindow", "\343\202\204\343\202\212\347\233\264\343\201\227(&Y)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        redoAct->setStatusTip(QApplication::translate("MainWindow", "\345\205\203\343\201\253\346\210\273\343\201\227\343\201\237\346\223\215\344\275\234\343\202\222\343\202\204\343\202\212\347\233\264\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        redoAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        filterTo1BitAct->setText(QApplication::translate("MainWindow", "2\345\200\244\345\214\226(&B)...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        filterTo1BitAct->setStatusTip(QApplication::translate("MainWindow", "\345\244\232\345\200\244\347\224\273\345\203\217\343\202\222\347\231\275\343\201\250\351\273\222\343\201\2562\345\200\244\347\224\273\345\203\217\343\201\253\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        linearFilterAct->setText(QApplication::translate("MainWindow", "\347\267\232\345\275\242\343\203\225\343\202\243\343\203\253\343\202\277(&L)...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        linearFilterAct->setStatusTip(QApplication::translate("MainWindow", "\350\277\221\345\202\215\347\224\273\347\264\240\343\201\253\344\277\202\346\225\260\343\202\222\343\201\213\343\201\221\343\201\237\347\267\217\345\222\214\343\202\222\347\224\273\347\264\240\345\200\244\343\201\253\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        medianFilterAct->setText(QApplication::translate("MainWindow", "\343\203\241\343\203\207\343\202\243\343\202\242\343\203\263\343\203\225\343\202\243\343\203\253\343\202\277(&M)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        medianFilterAct->setStatusTip(QApplication::translate("MainWindow", "\350\277\221\345\202\215 3x3 \347\224\273\347\264\240\343\201\256\344\270\255\345\244\256\345\200\244\343\202\222\346\226\260\343\201\237\343\201\252\347\224\273\347\264\240\345\200\244\343\201\253\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        fileToolBarVisibleAct->setText(QApplication::translate("MainWindow", "\343\203\225\343\202\241\343\202\244\343\203\253(&F)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        fileToolBarVisibleAct->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        normFilterAct->setText(QApplication::translate("MainWindow", "\345\213\276\351\205\215\343\203\216\343\203\253\343\203\240\343\203\225\343\202\243\343\203\253\343\202\277(&G)...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        normFilterAct->setStatusTip(QApplication::translate("MainWindow", "\345\213\276\351\205\215 (gradient) \343\201\256\343\203\216\343\203\253\343\203\240\343\202\222\350\250\210\347\256\227\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        filterToolBarVisibleAct->setText(QApplication::translate("MainWindow", "\343\203\225\343\202\243\343\203\253\343\202\277(&T)", 0, QApplication::UnicodeUTF8));
        editToolBarVisibleAct->setText(QApplication::translate("MainWindow", "\347\267\250\351\233\206(&E)", 0, QApplication::UnicodeUTF8));
        openClipboardAct->setText(QApplication::translate("MainWindow", "\343\202\257\343\203\252\343\203\203\343\203\227\343\203\234\343\203\274\343\203\211\343\201\213\343\202\211\351\226\213\343\201\217(&C)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        openClipboardAct->setStatusTip(QApplication::translate("MainWindow", "\343\202\257\343\203\252\343\203\203\343\203\227\343\203\234\343\203\274\343\203\211\343\201\256\347\224\273\345\203\217\343\202\222\351\226\213\343\201\215\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        tabVisibleAct->setText(QApplication::translate("MainWindow", "\343\202\277\343\203\226(&T)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        tabVisibleAct->setStatusTip(QApplication::translate("MainWindow", "\347\224\273\345\203\217\343\202\222\343\202\277\343\203\226\343\201\247\351\201\270\343\201\271\343\202\213\343\202\210\343\201\206\343\201\253\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        zoomToolBarVisibleAct->setText(QApplication::translate("MainWindow", "\343\202\272\343\203\274\343\203\240(&Z)", 0, QApplication::UnicodeUTF8));
        zoomInAct->setText(QApplication::translate("MainWindow", "\343\202\272\343\203\274\343\203\240\343\202\244\343\203\263(&I)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        zoomInAct->setStatusTip(QApplication::translate("MainWindow", "\346\213\241\345\244\247\350\241\250\347\244\272\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        zoomInAct->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        zoomOutAct->setText(QApplication::translate("MainWindow", "\343\202\272\343\203\274\343\203\240\343\202\242\343\202\246\343\203\210(&O)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        zoomOutAct->setStatusTip(QApplication::translate("MainWindow", "\347\270\256\345\260\217\350\241\250\347\244\272\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        zoomOutAct->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        zoomFullScaleAct->setText(QApplication::translate("MainWindow", "\345\216\237\345\257\270\345\244\247(&F)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        zoomFullScaleAct->setStatusTip(QApplication::translate("MainWindow", "\347\224\273\345\203\217\343\201\256\343\202\265\343\202\244\343\202\272\343\201\247\350\241\250\347\244\272\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        autoImageResizeAct->setText(QApplication::translate("MainWindow", "\347\224\273\351\235\242\343\201\253\345\220\210\343\202\217\343\201\233\343\202\213(&A)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        autoImageResizeAct->setStatusTip(QApplication::translate("MainWindow", "\347\224\273\351\235\242\343\202\265\343\202\244\343\202\272\343\201\253\345\220\210\343\202\217\343\201\233\343\201\246\347\224\273\345\203\217\343\202\265\343\202\244\343\202\272\343\202\222\345\244\211\346\233\264\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        menuFile->setTitle(QApplication::translate("MainWindow", "\343\203\225\343\202\241\343\202\244\343\203\253(&F)", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\343\203\230\343\203\253\343\203\227(&H)", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "\347\267\250\351\233\206(&E)", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "\350\241\250\347\244\272(&V)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        menuToolBar->setStatusTip(QApplication::translate("MainWindow", "\343\203\204\343\203\274\343\203\253\343\203\220\343\203\274\343\201\256\350\241\250\347\244\272/\351\235\236\350\241\250\347\244\272\343\202\222\345\210\207\343\202\212\346\233\277\343\201\210\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        menuToolBar->setTitle(QApplication::translate("MainWindow", "\343\203\204\343\203\274\343\203\253\343\203\220\343\203\274(&B)", 0, QApplication::UnicodeUTF8));
        menuZoom->setTitle(QApplication::translate("MainWindow", "\343\202\272\343\203\274\343\203\240(&Z)", 0, QApplication::UnicodeUTF8));
        menuOperate->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234(&O)", 0, QApplication::UnicodeUTF8));
        menuOpeColor->setTitle(QApplication::translate("MainWindow", "\350\211\262(&C)", 0, QApplication::UnicodeUTF8));
        menuOpeFilter->setTitle(QApplication::translate("MainWindow", "\343\203\225\343\202\243\343\203\253\343\202\277(&F)", 0, QApplication::UnicodeUTF8));
        fileToolBar->setWindowTitle(QApplication::translate("MainWindow", "\343\203\225\343\202\241\343\202\244\343\203\253", 0, QApplication::UnicodeUTF8));
        editToolBar->setWindowTitle(QApplication::translate("MainWindow", "\347\267\250\351\233\206", 0, QApplication::UnicodeUTF8));
        filterToolBar->setWindowTitle(QApplication::translate("MainWindow", "\343\203\225\343\202\243\343\203\253\343\202\277", 0, QApplication::UnicodeUTF8));
        zoomToolBar->setWindowTitle(QApplication::translate("MainWindow", "\343\202\272\343\203\274\343\203\240", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
