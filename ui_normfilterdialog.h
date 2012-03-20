/********************************************************************************
** Form generated from reading UI file 'normfilterdialog.ui'
**
** Created: Tue Mar 13 11:11:52 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORMFILTERDIALOG_H
#define UI_NORMFILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NormFilterDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QTextEdit *textEditX;
    QLabel *label_2;
    QTextEdit *textEditY;
    QDialogButtonBox *buttonBox;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListWidget *listWidgetFilter;

    void setupUi(QDialog *NormFilterDialog)
    {
        if (NormFilterDialog->objectName().isEmpty())
            NormFilterDialog->setObjectName(QString::fromUtf8("NormFilterDialog"));
        NormFilterDialog->resize(393, 246);
        horizontalLayout = new QHBoxLayout(NormFilterDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(NormFilterDialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        textEditX = new QTextEdit(NormFilterDialog);
        textEditX->setObjectName(QString::fromUtf8("textEditX"));

        formLayout->setWidget(0, QFormLayout::FieldRole, textEditX);

        label_2 = new QLabel(NormFilterDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        textEditY = new QTextEdit(NormFilterDialog);
        textEditY->setObjectName(QString::fromUtf8("textEditY"));

        formLayout->setWidget(1, QFormLayout::FieldRole, textEditY);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(NormFilterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        horizontalLayout->addLayout(verticalLayout);

        line = new QFrame(NormFilterDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(NormFilterDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        listWidgetFilter = new QListWidget(NormFilterDialog);
        listWidgetFilter->setObjectName(QString::fromUtf8("listWidgetFilter"));

        verticalLayout_2->addWidget(listWidgetFilter);


        horizontalLayout->addLayout(verticalLayout_2);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(textEditX);
        label_2->setBuddy(textEditY);
        label_3->setBuddy(listWidgetFilter);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(textEditX, textEditY);
        QWidget::setTabOrder(textEditY, buttonBox);
        QWidget::setTabOrder(buttonBox, listWidgetFilter);

        retranslateUi(NormFilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NormFilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NormFilterDialog, SLOT(reject()));
        QObject::connect(listWidgetFilter, SIGNAL(doubleClicked(QModelIndex)), NormFilterDialog, SLOT(accept()));
        QObject::connect(listWidgetFilter, SIGNAL(itemClicked(QListWidgetItem*)), NormFilterDialog, SLOT(setExampleFilter(QListWidgetItem*)));

        QMetaObject::connectSlotsByName(NormFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *NormFilterDialog)
    {
        NormFilterDialog->setWindowTitle(QApplication::translate("NormFilterDialog", "\345\213\276\351\205\215\343\203\216\343\203\253\343\203\240\343\203\225\343\202\243\343\203\253\343\202\277", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NormFilterDialog", "\346\250\252\345\276\256\345\210\206\343\203\225\343\202\243\343\203\253\343\202\277(&X):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        textEditX->setWhatsThis(QApplication::translate("NormFilterDialog", "\343\203\225\343\202\243\343\203\253\343\202\277\350\241\214\345\210\227\343\202\222\345\205\245\345\212\233\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("NormFilterDialog", "\347\270\246\345\276\256\345\210\206\343\203\225\343\202\243\343\203\253\343\202\277(&Y):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        textEditY->setWhatsThis(QApplication::translate("NormFilterDialog", "\343\203\225\343\202\243\343\203\253\343\202\277\350\241\214\345\210\227\343\202\222\345\205\245\345\212\233\343\201\227\343\201\276\343\201\231\343\200\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("NormFilterDialog", "\344\276\213:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NormFilterDialog: public Ui_NormFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMFILTERDIALOG_H
