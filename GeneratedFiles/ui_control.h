/********************************************************************************
** Form generated from reading UI file 'control.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_H
#define UI_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Control
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Control)
    {
        if (Control->objectName().isEmpty())
            Control->setObjectName(QStringLiteral("Control"));
        Control->resize(400, 500);
        centralwidget = new QWidget(Control);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Control->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Control);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 22));
        Control->setMenuBar(menubar);
        statusbar = new QStatusBar(Control);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Control->setStatusBar(statusbar);

        retranslateUi(Control);

        QMetaObject::connectSlotsByName(Control);
    } // setupUi

    void retranslateUi(QMainWindow *Control)
    {
        Control->setWindowTitle(QApplication::translate("Control", "EnglishHelper", 0));
    } // retranslateUi

};

namespace Ui {
    class Control: public Ui_Control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_H
