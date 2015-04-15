/********************************************************************************
** Form generated from reading UI file 'settingsui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSUI_H
#define UI_SETTINGSUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsUi
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *back;

    void setupUi(QWidget *SettingsUi)
    {
        if (SettingsUi->objectName().isEmpty())
            SettingsUi->setObjectName(QStringLiteral("SettingsUi"));
        SettingsUi->resize(400, 500);
        widget = new QWidget(SettingsUi);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 40, 291, 421));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        back = new QPushButton(widget);
        back->setObjectName(QStringLiteral("back"));

        horizontalLayout->addWidget(back);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SettingsUi);

        QMetaObject::connectSlotsByName(SettingsUi);
    } // setupUi

    void retranslateUi(QWidget *SettingsUi)
    {
        SettingsUi->setWindowTitle(QApplication::translate("SettingsUi", "Form", 0));
        label_2->setText(QApplication::translate("SettingsUi", "\350\256\260\350\203\214\345\215\225\350\257\215", 0));
        lineEdit->setText(QApplication::translate("SettingsUi", "20", 0));
        label_3->setText(QApplication::translate("SettingsUi", "\344\270\252/\345\244\251", 0));
        label_4->setText(QApplication::translate("SettingsUi", "\350\256\260\350\203\214\346\250\241\345\274\217", 0));
        label->setText(QApplication::translate("SettingsUi", "\345\257\274\345\205\245\345\255\227\345\205\270", 0));
        pushButton->setText(QApplication::translate("SettingsUi", "\351\200\211\346\213\251\346\226\207\344\273\266", 0));
        back->setText(QApplication::translate("SettingsUi", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsUi: public Ui_SettingsUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSUI_H
