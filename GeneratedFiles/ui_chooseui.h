/********************************************************************************
** Form generated from reading UI file 'chooseui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEUI_H
#define UI_CHOOSEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseUi
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *find;
    QPushButton *memory;
    QPushButton *article;
    QPushButton *settings;
    QPushButton *exit;
    QWidget *logo;

    void setupUi(QWidget *ChooseUi)
    {
        if (ChooseUi->objectName().isEmpty())
            ChooseUi->setObjectName(QStringLiteral("ChooseUi"));
        ChooseUi->resize(400, 500);
        layoutWidget = new QWidget(ChooseUi);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 180, 281, 281));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        find = new QPushButton(layoutWidget);
        find->setObjectName(QStringLiteral("find"));

        verticalLayout->addWidget(find);

        memory = new QPushButton(layoutWidget);
        memory->setObjectName(QStringLiteral("memory"));

        verticalLayout->addWidget(memory);

        article = new QPushButton(layoutWidget);
        article->setObjectName(QStringLiteral("article"));

        verticalLayout->addWidget(article);

        settings = new QPushButton(layoutWidget);
        settings->setObjectName(QStringLiteral("settings"));

        verticalLayout->addWidget(settings);

        exit = new QPushButton(layoutWidget);
        exit->setObjectName(QStringLiteral("exit"));

        verticalLayout->addWidget(exit);

        logo = new QWidget(ChooseUi);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(120, 10, 161, 160));
        logo->setStyleSheet(QStringLiteral(""));

        retranslateUi(ChooseUi);

        QMetaObject::connectSlotsByName(ChooseUi);
    } // setupUi

    void retranslateUi(QWidget *ChooseUi)
    {
        ChooseUi->setWindowTitle(QApplication::translate("ChooseUi", "Form", 0));
        find->setText(QApplication::translate("ChooseUi", "\345\215\225\350\257\215\346\237\245\350\257\242", 0));
        memory->setText(QApplication::translate("ChooseUi", "\350\256\260\350\203\214\345\215\225\350\257\215", 0));
        article->setText(QApplication::translate("ChooseUi", "\351\230\205\350\257\273\345\212\251\346\211\213", 0));
        settings->setText(QApplication::translate("ChooseUi", "\350\256\276\347\275\256", 0));
        exit->setText(QApplication::translate("ChooseUi", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class ChooseUi: public Ui_ChooseUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEUI_H
