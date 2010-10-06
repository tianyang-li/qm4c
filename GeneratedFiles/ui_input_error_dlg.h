/********************************************************************************
** Form generated from reading UI file 'input_error_dlg.ui'
**
** Created: Wed Oct 6 05:22:42 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_ERROR_DLG_H
#define UI_INPUT_ERROR_DLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InputErrorDlg
{
public:
    QLabel *label;
    QPushButton *okButton;

    void setupUi(QDialog *InputErrorDlg)
    {
        if (InputErrorDlg->objectName().isEmpty())
            InputErrorDlg->setObjectName(QString::fromUtf8("InputErrorDlg"));
        InputErrorDlg->resize(281, 48);
        InputErrorDlg->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        label = new QLabel(InputErrorDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 9, 144, 26));
        label->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        okButton = new QPushButton(InputErrorDlg);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(190, 10, 75, 23));

        retranslateUi(InputErrorDlg);
        QObject::connect(okButton, SIGNAL(clicked()), InputErrorDlg, SLOT(accept()));

        QMetaObject::connectSlotsByName(InputErrorDlg);
    } // setupUi

    void retranslateUi(QDialog *InputErrorDlg)
    {
        InputErrorDlg->setWindowTitle(QApplication::translate("InputErrorDlg", "Input error!", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InputErrorDlg", "Input error detected!\n"
"Please check your input!", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("InputErrorDlg", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InputErrorDlg: public Ui_InputErrorDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_ERROR_DLG_H
