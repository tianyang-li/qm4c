/********************************************************************************
** Form generated from reading UI file 'qm4c.ui'
**
** Created: Sat Oct 2 14:20:24 2010
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
    QAction *actionAbout_QM4C;
    QAction *actionQM4C_Help;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPlainTextEdit *boolExprInput;
    QPushButton *simplifyButton;
    QLabel *label_2;
    QTextBrowser *boolExprOutput;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QM4CClass)
    {
        if (QM4CClass->objectName().isEmpty())
            QM4CClass->setObjectName(QString::fromUtf8("QM4CClass"));
        QM4CClass->resize(720, 563);
        actionAbout_QM4C = new QAction(QM4CClass);
        actionAbout_QM4C->setObjectName(QString::fromUtf8("actionAbout_QM4C"));
        actionQM4C_Help = new QAction(QM4CClass);
        actionQM4C_Help->setObjectName(QString::fromUtf8("actionQM4C_Help"));
        centralWidget = new QWidget(QM4CClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        boolExprInput = new QPlainTextEdit(centralWidget);
        boolExprInput->setObjectName(QString::fromUtf8("boolExprInput"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        boolExprInput->setFont(font);
        boolExprInput->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        boolExprInput->setTabChangesFocus(true);
        boolExprInput->setLineWrapMode(QPlainTextEdit::WidgetWidth);

        gridLayout->addWidget(boolExprInput, 0, 1, 1, 1);

        simplifyButton = new QPushButton(centralWidget);
        simplifyButton->setObjectName(QString::fromUtf8("simplifyButton"));
        simplifyButton->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        simplifyButton->setAutoDefault(false);
        simplifyButton->setDefault(true);

        gridLayout->addWidget(simplifyButton, 1, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        boolExprOutput = new QTextBrowser(centralWidget);
        boolExprOutput->setObjectName(QString::fromUtf8("boolExprOutput"));
        boolExprOutput->setFont(font);
        boolExprOutput->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout->addWidget(boolExprOutput, 2, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(91, 16));
        label->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout->addWidget(label, 0, 0, 1, 1);

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
        menuHelp->addAction(actionQM4C_Help);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout_QM4C);

        retranslateUi(QM4CClass);

        QMetaObject::connectSlotsByName(QM4CClass);
    } // setupUi

    void retranslateUi(QMainWindow *QM4CClass)
    {
        QM4CClass->setWindowTitle(QApplication::translate("QM4CClass", "QM4C", 0, QApplication::UnicodeUTF8));
        actionAbout_QM4C->setText(QApplication::translate("QM4CClass", "About QM4C", 0, QApplication::UnicodeUTF8));
        actionQM4C_Help->setText(QApplication::translate("QM4CClass", "QM4C Help", 0, QApplication::UnicodeUTF8));
        simplifyButton->setText(QApplication::translate("QM4CClass", "Simplify", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QM4CClass", "Simplified\n"
"boolean\n"
"expresion", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QM4CClass", "Enter boolean\n"
"expression to\n"
"simplify", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("QM4CClass", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QM4CClass: public Ui_QM4CClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QM4C_H
