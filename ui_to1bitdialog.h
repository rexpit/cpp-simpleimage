/********************************************************************************
** Form generated from reading UI file 'to1bitdialog.ui'
**
** Created: Sat Mar 10 21:48:51 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TO1BITDIALOG_H
#define UI_TO1BITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_To1BitDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonB;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSlider *sliderT;
    QSpinBox *spinBoxT;
    QSpacerItem *verticalSpacer;
    QRadioButton *radioButtonE;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *To1BitDialog)
    {
        if (To1BitDialog->objectName().isEmpty())
            To1BitDialog->setObjectName(QString::fromUtf8("To1BitDialog"));
        To1BitDialog->resize(255, 211);
        To1BitDialog->setSizeGripEnabled(false);
        To1BitDialog->setModal(true);
        verticalLayout_2 = new QVBoxLayout(To1BitDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(To1BitDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButtonB = new QRadioButton(groupBox);
        radioButtonB->setObjectName(QString::fromUtf8("radioButtonB"));
        radioButtonB->setEnabled(true);
        radioButtonB->setChecked(true);

        verticalLayout->addWidget(radioButtonB);

        frame = new QFrame(groupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setEnabled(true);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sliderT = new QSlider(frame);
        sliderT->setObjectName(QString::fromUtf8("sliderT"));
        sliderT->setFocusPolicy(Qt::ClickFocus);
        sliderT->setMaximum(256);
        sliderT->setValue(128);
        sliderT->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sliderT);

        spinBoxT = new QSpinBox(frame);
        spinBoxT->setObjectName(QString::fromUtf8("spinBoxT"));
        spinBoxT->setMaximum(256);
        spinBoxT->setValue(128);

        horizontalLayout->addWidget(spinBoxT);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        radioButtonE = new QRadioButton(groupBox);
        radioButtonE->setObjectName(QString::fromUtf8("radioButtonE"));

        verticalLayout->addWidget(radioButtonE);


        verticalLayout_2->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(To1BitDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(spinBoxT);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(radioButtonB, sliderT);
        QWidget::setTabOrder(sliderT, spinBoxT);
        QWidget::setTabOrder(spinBoxT, radioButtonE);
        QWidget::setTabOrder(radioButtonE, buttonBox);

        retranslateUi(To1BitDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), To1BitDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), To1BitDialog, SLOT(reject()));
        QObject::connect(radioButtonB, SIGNAL(toggled(bool)), frame, SLOT(setEnabled(bool)));
        QObject::connect(sliderT, SIGNAL(valueChanged(int)), spinBoxT, SLOT(setValue(int)));
        QObject::connect(spinBoxT, SIGNAL(valueChanged(int)), sliderT, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(To1BitDialog);
    } // setupUi

    void retranslateUi(QDialog *To1BitDialog)
    {
        To1BitDialog->setWindowTitle(QApplication::translate("To1BitDialog", "2\345\200\244\345\214\226", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("To1BitDialog", "2\345\200\244\345\214\226\346\263\225", 0, QApplication::UnicodeUTF8));
        radioButtonB->setText(QApplication::translate("To1BitDialog", "\343\201\227\343\201\215\343\201\204\345\200\244\346\263\225(&B)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("To1BitDialog", "\343\201\227\343\201\215\343\201\204\345\200\244(&T):", 0, QApplication::UnicodeUTF8));
        radioButtonE->setText(QApplication::translate("To1BitDialog", "\350\252\244\345\267\256\346\213\241\346\225\243\346\263\225(&E)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class To1BitDialog: public Ui_To1BitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TO1BITDIALOG_H
