#include "control.h"
#include "ui_control.h"
#include "func.h"

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
    connect(articleUi, SIGNAL(analysis(QString)),
            this, SLOT(analysis(QString)));
    connect(chooseUi, SIGNAL(memoryClicked()),
            this, SLOT(memoryStart()));
    connect(memoryUi, SIGNAL(nextClicked()),
            this, SLOT(memoryNextClicked()));
    connect(memoryUi, SIGNAL(choiceClicked(int)),
            this, SLOT(memoryChoiceClicked(int)));
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
    Func::QueryPair *result=func->query(word);
    findUi->queryResult(result->first);
    for (int i=0;result->second[i]!="###";i++)
    {
        qDebug()<<result->second[i];
    }
}

void Control::analysis(QString article)
{
    articleUi->analysisResult(func->analysisArticle(article));
}

void Control::memoryStart()
{
    memoryUi->setBack(false);
//    totalQuestions=settingsUi->testNumber();
    totalQuestions=3;
    nowQuestions=0;
    questions=func->startTest(totalQuestions);
    memoryNextClicked();
}

void Control::memoryChoiceClicked(int userAnswer)
{
    memoryUi->setNext(true);
    memoryUi->setChoice(false);
    memoryUi->showAnswer(userAnswer, questions[nowQuestions-1].third);
    if (userAnswer==questions[nowQuestions-1].third)
        func->answerForTest(nowQuestions-1, Yes);
    else
        func->answerForTest(nowQuestions-1, No);
}

void Control::memoryNextClicked()
{
    memoryUi->hideAnswer();
    ++nowQuestions;
    if (nowQuestions>totalQuestions)
    {
        memoryUi->setNext(false);
        memoryUi->setChoice(false);
        memoryUi->setBack(true);
        func->endTest();
    } else {
        memoryUi->setNext(false);
        memoryUi->setChoice(true);
        memoryUi->showQuestion( questions[nowQuestions-1].first,
                                questions[nowQuestions-1].second[0],
                                questions[nowQuestions-1].second[1],
                                questions[nowQuestions-1].second[2],
                                questions[nowQuestions-1].second[3]);
    }

}
