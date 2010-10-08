/********************************************************************************
** Form generated from reading UI file 'QM4C_help_dlg.ui'
**
** Created: Fri Oct 8 21:31:22 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QM4C_HELP_DLG_H
#define UI_QM4C_HELP_DLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_QM4CHelpDlg
{
public:
    QLabel *label;

    void setupUi(QDialog *QM4CHelpDlg)
    {
        if (QM4CHelpDlg->objectName().isEmpty())
            QM4CHelpDlg->setObjectName(QString::fromUtf8("QM4CHelpDlg"));
        QM4CHelpDlg->resize(400, 300);
        label = new QLabel(QM4CHelpDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 30, 234, 240));
        label->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        retranslateUi(QM4CHelpDlg);

        QMetaObject::connectSlotsByName(QM4CHelpDlg);
    } // setupUi

    void retranslateUi(QDialog *QM4CHelpDlg)
    {
        QM4CHelpDlg->setWindowTitle(QApplication::translate("QM4CHelpDlg", "QM4C Help", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QM4CHelpDlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\">QM4C takes input boolean expressions </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\">written in C and simplifies it.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; "
                        "color:#000000;\">For example, the output of</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\">~a || a</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\">would be</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\">1</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\"></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-"
                        "right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\">See </span><a href=\"http://code.google.com/p/qm4c\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">http://code.google.com/p/qm4c</span></a><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\"> </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\">for more information</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QM4CHelpDlg: public Ui_QM4CHelpDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QM4C_HELP_DLG_H
