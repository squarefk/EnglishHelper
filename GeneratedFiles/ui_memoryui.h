/********************************************************************************
** Form generated from reading UI file 'memoryui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORYUI_H
#define UI_MEMORYUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemoryUi
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *question;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *A;
    QPushButton *B;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *C;
    QPushButton *D;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *next;
    QPushButton *back;

    void setupUi(QWidget *MemoryUi)
    {
        if (MemoryUi->objectName().isEmpty())
            MemoryUi->setObjectName(QStringLiteral("MemoryUi"));
        MemoryUi->resize(400, 500);
        widget = new QWidget(MemoryUi);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(51, 31, 301, 431));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        question = new QLabel(widget);
        question->setObjectName(QStringLiteral("question"));

        verticalLayout_2->addWidget(question);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        A = new QPushButton(widget);
        A->setObjectName(QStringLiteral("A"));

        horizontalLayout_3->addWidget(A);

        B = new QPushButton(widget);
        B->setObjectName(QStringLiteral("B"));

        horizontalLayout_3->addWidget(B);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        C = new QPushButton(widget);
        C->setObjectName(QStringLiteral("C"));

        horizontalLayout_2->addWidget(C);

        D = new QPushButton(widget);
        D->setObjectName(QStringLiteral("D"));

        horizontalLayout_2->addWidget(D);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        next = new QPushButton(widget);
        next->setObjectName(QStringLiteral("next"));

        horizontalLayout->addWidget(next);

        back = new QPushButton(widget);
        back->setObjectName(QStringLiteral("back"));

        horizontalLayout->addWidget(back);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(MemoryUi);

        QMetaObject::connectSlotsByName(MemoryUi);
    } // setupUi

    void retranslateUi(QWidget *MemoryUi)
    {
        MemoryUi->setWindowTitle(QApplication::translate("MemoryUi", "Form", 0));
        question->setText(QApplication::translate("MemoryUi", "TextLabel", 0));
        A->setText(QApplication::translate("MemoryUi", "A", 0));
        B->setText(QApplication::translate("MemoryUi", "B", 0));
        C->setText(QApplication::translate("MemoryUi", "C", 0));
        D->setText(QApplication::translate("MemoryUi", "D", 0));
        next->setText(QApplication::translate("MemoryUi", "\344\270\213\344\270\200\344\270\252", 0));
        back->setText(QApplication::translate("MemoryUi", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class MemoryUi: public Ui_MemoryUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORYUI_H
