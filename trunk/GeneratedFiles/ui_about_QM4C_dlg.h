/********************************************************************************
** Form generated from reading UI file 'about_QM4C_dlg.ui'
**
** Created: Mon Oct 4 15:43:44 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_QM4C_DLG_H
#define UI_ABOUT_QM4C_DLG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutQM4CDlg
{
public:
    QLabel *label;

    void setupUi(QDialog *AboutQM4CDlg)
    {
        if (AboutQM4CDlg->objectName().isEmpty())
            AboutQM4CDlg->setObjectName(QString::fromUtf8("AboutQM4CDlg"));
        AboutQM4CDlg->resize(400, 300);
        label = new QLabel(AboutQM4CDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 30, 239, 216));
        label->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        retranslateUi(AboutQM4CDlg);

        QMetaObject::connectSlotsByName(AboutQM4CDlg);
    } // setupUi

    void retranslateUi(QDialog *AboutQM4CDlg)
    {
        AboutQM4CDlg->setWindowTitle(QApplication::translate("AboutQM4CDlg", "About QM4C", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AboutQM4CDlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman'; font-size:12pt; font-weight:600;\">QM4C</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Times New Roman'; font-size:12pt; font-weight:600;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\">Implementation of Quine\342\200\223McCluskey </spa"
                        "n></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\">algorithm for C like boolean expressions. </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\">Developed using Qt4.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\"><br />QM4C is lincenced under</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\">the GNU GPL version 3.0</span></p>\n"
"<p style=\"-qt-paragraph-type:em"
                        "pty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\">Copyright (C) 2010 Tianyang Li</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\">See </span><a href=\"http://code.google.com/p/qm4c/\"><span style=\" font-family:'Times New Roman'; font-size:10pt; text-decoration: underline; color:#0000ff;\">http://code."
                        "google.com/p/qm4c/</span></a><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'arial,sans-serif'; font-size:10pt; color:#000000;\">for more information.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutQM4CDlg: public Ui_AboutQM4CDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_QM4C_DLG_H
