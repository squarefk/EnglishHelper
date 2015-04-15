/********************************************************************************
** Form generated from reading UI file 'findui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDUI_H
#define UI_FINDUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindUi
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *word;
    QPushButton *query;
    QLabel *meaning;
    QPushButton *back;

    void setupUi(QWidget *FindUi)
    {
        if (FindUi->objectName().isEmpty())
            FindUi->setObjectName(QStringLiteral("FindUi"));
        FindUi->resize(400, 500);
        widget = new QWidget(FindUi);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 50, 281, 391));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        word = new QLineEdit(widget);
        word->setObjectName(QStringLiteral("word"));

        horizontalLayout->addWidget(word);

        query = new QPushButton(widget);
        query->setObjectName(QStringLiteral("query"));

        horizontalLayout->addWidget(query);


        verticalLayout->addLayout(horizontalLayout);

        meaning = new QLabel(widget);
        meaning->setObjectName(QStringLiteral("meaning"));

        verticalLayout->addWidget(meaning);

        back = new QPushButton(widget);
        back->setObjectName(QStringLiteral("back"));

        verticalLayout->addWidget(back);

        meaning->raise();
        word->raise();
        query->raise();
        meaning->raise();
        back->raise();

        retranslateUi(FindUi);

        QMetaObject::connectSlotsByName(FindUi);
    } // setupUi

    void retranslateUi(QWidget *FindUi)
    {
        FindUi->setWindowTitle(QApplication::translate("FindUi", "Form", 0));
        word->setText(QApplication::translate("FindUi", "square", 0));
        query->setText(QApplication::translate("FindUi", "\346\237\245\350\257\242", 0));
        meaning->setText(QApplication::translate("FindUi", "square\347\232\204\345\256\232\344\271\211\n"
"adjective\n"
"having the shape or approximate shape of a square.\n"
"\"a square table\"\n"
"\345\220\214\344\271\211\350\257\215: quadrilateral, rectangular, oblong, right-angled, at right angles, perpendicular, straight, level, parallel, horizontal, upright, vertical, true, plane\n"
"adverb\n"
"directly; straight.\n"
"\"it hit me square in the forehead\"\n"
"noun\n"
"a plane figure with four equal straight sides and four right angles.\n"
"\"He arranges thin rectangles, squares , triangles and trapezoids in complex patterns on the wall.\"\n"
"verb\n"
"make square or rectangular; give a square or rectangular cross section to.\n"
"\"you can square off the other edge\"", 0));
        back->setText(QApplication::translate("FindUi", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class FindUi: public Ui_FindUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDUI_H
