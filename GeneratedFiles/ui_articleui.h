/********************************************************************************
** Form generated from reading UI file 'articleui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLEUI_H
#define UI_ARTICLEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArticleUi
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *analysis;
    QPushButton *back;

    void setupUi(QWidget *ArticleUi)
    {
        if (ArticleUi->objectName().isEmpty())
            ArticleUi->setObjectName(QStringLiteral("ArticleUi"));
        ArticleUi->resize(400, 500);
        widget = new QWidget(ArticleUi);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 30, 351, 451));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 200));
        lineEdit->setMaximumSize(QSize(16777215, 200));

        verticalLayout->addWidget(lineEdit);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        analysis = new QPushButton(widget);
        analysis->setObjectName(QStringLiteral("analysis"));

        horizontalLayout->addWidget(analysis);

        back = new QPushButton(widget);
        back->setObjectName(QStringLiteral("back"));

        horizontalLayout->addWidget(back);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ArticleUi);

        QMetaObject::connectSlotsByName(ArticleUi);
    } // setupUi

    void retranslateUi(QWidget *ArticleUi)
    {
        ArticleUi->setWindowTitle(QApplication::translate("ArticleUi", "Form", 0));
        label->setText(QApplication::translate("ArticleUi", "TextLabel", 0));
        analysis->setText(QApplication::translate("ArticleUi", "\347\224\237\350\257\215\345\210\206\346\236\220", 0));
        back->setText(QApplication::translate("ArticleUi", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class ArticleUi: public Ui_ArticleUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEUI_H
