/********************************************************************************
** Form generated from reading UI file 'please_wait_dlg.ui'
**
** Created: Mon Oct 4 15:43:44 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLEASE_WAIT_DLG_H
#define UI_PLEASE_WAIT_DLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_PleaseWaitDlg
{
public:
    QLabel *label;

    void setupUi(QDialog *PleaseWaitDlg)
    {
        if (PleaseWaitDlg->objectName().isEmpty())
            PleaseWaitDlg->setObjectName(QString::fromUtf8("PleaseWaitDlg"));
        PleaseWaitDlg->resize(304, 43);
        PleaseWaitDlg->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        PleaseWaitDlg->setModal(true);
        label = new QLabel(PleaseWaitDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 20, 66, 12));

        retranslateUi(PleaseWaitDlg);

        QMetaObject::connectSlotsByName(PleaseWaitDlg);
    } // setupUi

    void retranslateUi(QDialog *PleaseWaitDlg)
    {
        PleaseWaitDlg->setWindowTitle(QApplication::translate("PleaseWaitDlg", "Please wait", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PleaseWaitDlg", "Please wait", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PleaseWaitDlg: public Ui_PleaseWaitDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLEASE_WAIT_DLG_H
