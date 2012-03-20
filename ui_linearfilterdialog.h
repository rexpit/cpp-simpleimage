/********************************************************************************
** Form generated from reading UI file 'linearfilterdialog.ui'
**
** Created: Sat Mar 10 21:48:51 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEARFILTERDIALOG_H
#define UI_LINEARFILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LinearFilterDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QPlainTextEdit *textEditM;
    QLabel *label_2;
    QLineEdit *lineEditD;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonZ;
    QRadioButton *radioButtonA;
    QDialogButtonBox *buttonBox;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListWidget *listWidgetFilter;

    void setupUi(QDialog *LinearFilterDialog)
    {
        if (LinearFilterDialog->objectName().isEmpty())
            LinearFilterDialog->setObjectName(QString::fromUtf8("LinearFilterDialog"));
        LinearFilterDialog->resize(618, 380);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon/filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        LinearFilterDialog->setWindowIcon(icon);
        horizontalLayout_2 = new QHBoxLayout(LinearFilterDialog);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(LinearFilterDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        textEditM = new QPlainTextEdit(groupBox);
        textEditM->setObjectName(QString::fromUtf8("textEditM"));

        formLayout->setWidget(0, QFormLayout::FieldRole, textEditM);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEditD = new QLineEdit(groupBox);
        lineEditD->setObjectName(QString::fromUtf8("lineEditD"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditD);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(LinearFilterDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButtonZ = new QRadioButton(groupBox_2);
        radioButtonZ->setObjectName(QString::fromUtf8("radioButtonZ"));
        radioButtonZ->setChecked(true);

        verticalLayout->addWidget(radioButtonZ);

        radioButtonA = new QRadioButton(groupBox_2);
        radioButtonA->setObjectName(QString::fromUtf8("radioButtonA"));

        verticalLayout->addWidget(radioButtonA);


        verticalLayout_3->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(LinearFilterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        horizontalLayout_2->addLayout(verticalLayout_3);

        line = new QFrame(LinearFilterDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(LinearFilterDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        listWidgetFilter = new QListWidget(LinearFilterDialog);
        listWidgetFilter->setObjectName(QString::fromUtf8("listWidgetFilter"));
        listWidgetFilter->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(listWidgetFilter);


        horizontalLayout_2->addLayout(verticalLayout_2);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(textEditM);
        label_2->setBuddy(lineEditD);
        label_3->setBuddy(listWidgetFilter);
#endif // QT_NO_SHORTCUT

        retranslateUi(LinearFilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LinearFilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LinearFilterDialog, SLOT(reject()));
        QObject::connect(textEditM, SIGNAL(textChanged()), LinearFilterDialog, SLOT(setAutoByMatrix()));
        QObject::connect(listWidgetFilter, SIGNAL(itemClicked(QListWidgetItem*)), LinearFilterDialog, SLOT(setExampleFilter(QListWidgetItem*)));
        QObject::connect(listWidgetFilter, SIGNAL(itemDoubleClicked(QListWidgetItem*)), LinearFilterDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(LinearFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *LinearFilterDialog)
    {
        LinearFilterDialog->setWindowTitle(QApplication::translate("LinearFilterDialog", "\347\267\232\345\275\242\343\203\225\343\202\243\343\203\253\343\202\277", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("LinearFilterDialog", "\343\203\225\343\202\243\343\203\253\343\202\277\344\277\202\346\225\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LinearFilterDialog", "\350\241\214\345\210\227(&M):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        textEditM->setWhatsThis(QApplication::translate("LinearFilterDialog", "\343\203\225\343\202\243\343\203\253\343\202\277\343\201\256\344\277\202\346\225\260\350\241\214\345\210\227\343\202\222\346\214\207\345\256\232\343\201\227\343\201\276\343\201\231\343\200\202\n"
"\350\241\214\345\210\227\343\201\257 \345\245\207\346\225\260\350\241\214 \303\227 \345\245\207\346\225\260\345\210\227\343\201\256\346\225\264\346\225\260\343\201\256\350\241\214\345\210\227\343\201\247\343\201\231\343\200\202\n"
"\343\202\271\343\203\232\343\203\274\343\202\271\343\201\247\345\210\227\343\202\222\343\200\201\346\224\271\350\241\214\343\201\247\350\241\214\343\202\222\350\241\250\343\201\227\343\201\246\343\201\217\343\201\240\343\201\225\343\201\204\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        textEditM->setPlainText(QString());
        label_2->setText(QApplication::translate("LinearFilterDialog", "\345\210\206\346\257\215(&D):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        lineEditD->setWhatsThis(QApplication::translate("LinearFilterDialog", "\350\241\214\345\210\227\343\201\256\345\220\204\343\200\205\343\201\256\350\246\201\347\264\240\343\202\222\345\210\206\346\257\215\343\201\247\345\211\262\343\202\212\343\201\276\343\201\231\343\200\202\345\210\206\346\257\215\343\202\222\346\225\264\346\225\260\343\201\247\346\214\207\345\256\232\343\201\227\343\201\246\343\201\217\343\201\240\343\201\225\343\201\204\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        lineEditD->setText(QString());
        groupBox_2->setTitle(QApplication::translate("LinearFilterDialog", "\345\276\214\345\207\246\347\220\206", 0, QApplication::UnicodeUTF8));
        radioButtonZ->setText(QApplication::translate("LinearFilterDialog", "\350\262\240\343\201\256\345\200\244\343\202\222 0 \343\201\253\343\201\231\343\202\213(&Z)", 0, QApplication::UnicodeUTF8));
        radioButtonA->setText(QApplication::translate("LinearFilterDialog", "\350\262\240\343\201\256\345\200\244\343\202\222\347\265\266\345\257\276\345\200\244\343\201\253\343\201\231\343\202\213(&A)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LinearFilterDialog", "\344\276\213:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LinearFilterDialog: public Ui_LinearFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEARFILTERDIALOG_H
