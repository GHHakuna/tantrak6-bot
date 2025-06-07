/********************************************************************************
** Form generated from reading UI file 'NxHK6PM.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NXHK6PM_H
#define UI_NXHK6PM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NxHK6PMClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NxHK6PMClass)
    {
        if (NxHK6PMClass->objectName().isEmpty())
            NxHK6PMClass->setObjectName("NxHK6PMClass");
        NxHK6PMClass->resize(600, 400);
        menuBar = new QMenuBar(NxHK6PMClass);
        menuBar->setObjectName("menuBar");
        NxHK6PMClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NxHK6PMClass);
        mainToolBar->setObjectName("mainToolBar");
        NxHK6PMClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(NxHK6PMClass);
        centralWidget->setObjectName("centralWidget");
        NxHK6PMClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(NxHK6PMClass);
        statusBar->setObjectName("statusBar");
        NxHK6PMClass->setStatusBar(statusBar);

        retranslateUi(NxHK6PMClass);

        QMetaObject::connectSlotsByName(NxHK6PMClass);
    } // setupUi

    void retranslateUi(QMainWindow *NxHK6PMClass)
    {
        NxHK6PMClass->setWindowTitle(QCoreApplication::translate("NxHK6PMClass", "NxHK6PM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NxHK6PMClass: public Ui_NxHK6PMClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NXHK6PM_H
