/********************************************************************************
** Form generated from reading UI file 'Task3GUI.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK3GUI_H
#define UI_TASK3GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task3GUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Task3GUIClass)
    {
        if (Task3GUIClass->objectName().isEmpty())
            Task3GUIClass->setObjectName("Task3GUIClass");
        Task3GUIClass->resize(600, 400);
        menuBar = new QMenuBar(Task3GUIClass);
        menuBar->setObjectName("menuBar");
        Task3GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Task3GUIClass);
        mainToolBar->setObjectName("mainToolBar");
        Task3GUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Task3GUIClass);
        centralWidget->setObjectName("centralWidget");
        Task3GUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Task3GUIClass);
        statusBar->setObjectName("statusBar");
        Task3GUIClass->setStatusBar(statusBar);

        retranslateUi(Task3GUIClass);

        QMetaObject::connectSlotsByName(Task3GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *Task3GUIClass)
    {
        Task3GUIClass->setWindowTitle(QCoreApplication::translate("Task3GUIClass", "Task3GUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Task3GUIClass: public Ui_Task3GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK3GUI_H
