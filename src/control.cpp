#include "control.h"
#include "ui_control.h"

#include <QDebug>

Control::Control(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Control)
{
    ui->setupUi(this);

    chooseUi = new ChooseUi;
    findUi = new FindUi;
    memoryUi = new MemoryUi;
    articleUi = new ArticleUi;
    settingsUi = new SettingsUi;
    func = new Func;

    stack = new QStackedWidget;
    stack->addWidget(chooseUi);
    stack->addWidget(findUi);
    stack->addWidget(memoryUi);
    stack->addWidget(articleUi);
    stack->addWidget(settingsUi);

    setCentralWidget(stack);

    connect(chooseUi, SIGNAL(findClicked()),
            this, SLOT(showFind()));
    connect(findUi, SIGNAL(backClicked()),
            this, SLOT(showChoose()));
    connect(chooseUi, SIGNAL(memoryClicked()),
            this, SLOT(showMemory()));
    connect(memoryUi, SIGNAL(backClicked()),
            this, SLOT(showChoose()));
    connect(chooseUi, SIGNAL(articleClicked()),
            this, SLOT(showArticle()));
    connect(articleUi, SIGNAL(backClicked()),
            this, SLOT(showChoose()));
    connect(chooseUi, SIGNAL(settingsClicked()),
            this, SLOT(showSettings()));
    connect(settingsUi, SIGNAL(backClicked()),
            this, SLOT(showChoose()));

    connect(findUi, SIGNAL(query(QString)),
            this, SLOT(query(QString)));
}

Control::~Control()
{
    delete ui;
}

void Control::showChoose()
{
    //qDebug() << "showChoose";
    stack->setCurrentWidget(chooseUi);
}

void Control::showFind()
{
    stack->setCurrentWidget(findUi);
}

void Control::showMemory()
{
    stack->setCurrentWidget(memoryUi);
   // QString primaryWord=func->getWord();
    //memoryUi->newTest(primaryWord,func->findSimilar(primaryWord));
}

void Control::showArticle()
{
    stack->setCurrentWidget(articleUi);
}

void Control::showSettings()
{
    stack->setCurrentWidget(settingsUi);
}

void Control::query(QString word)
{
    //findUi->queryResult(func->query(word));
}

