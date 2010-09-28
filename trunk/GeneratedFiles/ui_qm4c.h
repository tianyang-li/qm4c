/********************************************************************************
** Form generated from reading UI file 'qm4c.ui'
**
** Created: Tue Sep 28 23:47:22 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QM4C_H
#define UI_QM4C_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QM4CClass
{
public:
    QAction *actionQM4C_Help;
    QAction *actionQM4C_Help_2;
    QAction *actionAbout_QM4C;
    QAction *actionQM4C_Help_3;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QM4CClass)
    {
        if (QM4CClass->objectName().isEmpty())
            QM4CClass->setObjectName(QString::fromUtf8("QM4CClass"));
        QM4CClass->resize(720, 563);
        actionQM4C_Help = new QAction(QM4CClass);
        actionQM4C_Help->setObjectName(QString::fromUtf8("actionQM4C_Help"));
        actionQM4C_Help_2 = new QAction(QM4CClass);
        actionQM4C_Help_2->setObjectName(QString::fromUtf8("actionQM4C_Help_2"));
        actionAbout_QM4C = new QAction(QM4CClass);
        actionAbout_QM4C->setObjectName(QString::fromUtf8("actionAbout_QM4C"));
        actionQM4C_Help_3 = new QAction(QM4CClass);
        actionQM4C_Help_3->setObjectName(QString::fromUtf8("actionQM4C_Help_3"));
        centralWidget = new QWidget(QM4CClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(91, 16));
        label->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 0, 1, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 2, 1, 1, 1);

        QM4CClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QM4CClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 720, 23));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        QM4CClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QM4CClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QM4CClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QM4CClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QM4CClass->setStatusBar(statusBar);

        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout_QM4C);
        menuHelp->addSeparator();
        menuHelp->addAction(actionQM4C_Help_3);

        retranslateUi(QM4CClass);

        QMetaObject::connectSlotsByName(QM4CClass);
    } // setupUi

    void retranslateUi(QMainWindow *QM4CClass)
    {
        QM4CClass->setWindowTitle(QApplication::translate("QM4CClass", "QM4C", 0, QApplication::UnicodeUTF8));
        actionQM4C_Help->setText(QApplication::translate("QM4CClass", "QM4C Help", 0, QApplication::UnicodeUTF8));
        actionQM4C_Help_2->setText(QApplication::translate("QM4CClass", "QM4C Help", 0, QApplication::UnicodeUTF8));
        actionAbout_QM4C->setText(QApplication::translate("QM4CClass", "About QM4C", 0, QApplication::UnicodeUTF8));
        actionQM4C_Help_3->setText(QApplication::translate("QM4CClass", "QM4C Help", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QM4CClass", "Enter boolean\n"
"expression to\n"
"simplify", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QM4CClass", "Simplify", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QM4CClass", "Simplified\n"
"boolean\n"
"expresion", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("QM4CClass", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QM4CClass: public Ui_QM4CClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QM4C_H
