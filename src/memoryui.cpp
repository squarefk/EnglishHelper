#include "memoryui.h"
#include "ui_memoryui.h"
#include "control.h"
#include <QMessageBox>
#include <QPushButton>
#include <QDebug>


void MemoryUi::newTest(QString primaryword,QString* similarList)
{
    ui->A->setText(similarList[0]);
    ui->B->setText(similarList[1]);
    ui->C->setText(similarList[2]);
    ui->D->setText(similarList[3]);

}

MemoryUi::MemoryUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemoryUi)
{
    ui->setupUi(this);

    QFile *file = new QFile(":qss/qss/memoryui.qss");
    file->open(QFile::ReadOnly);
    setStyleSheet(file->readAll());
    file->deleteLater();

    connect(ui->back, SIGNAL(clicked()),
            this, SIGNAL(backClicked()));
    connect(ui->next, SIGNAL(clicked()),
            this, SLOT(nextButton()));
    connect(ui->A, SIGNAL(clicked()),
            this, SLOT(aButton()));
    connect(ui->B, SIGNAL(clicked()),
            this, SLOT(bButton()));
    connect(ui->C, SIGNAL(clicked()),
            this, SLOT(cButton()));
    connect(ui->D, SIGNAL(clicked()),
            this, SLOT(dButton()));
}

MemoryUi::~MemoryUi()
{
    delete ui;
}

void MemoryUi::setBack(bool flag)
{
    ui->back->setEnabled(flag);
}

void MemoryUi::setNext(bool flag)
{
    ui->next->setEnabled(flag);
}

void MemoryUi::setChoice(bool flag)
{
    ui->A->setEnabled(flag);
    ui->B->setEnabled(flag);
    ui->C->setEnabled(flag);
    ui->D->setEnabled(flag);
}

void MemoryUi::showQuestion(QString problem, QString A, QString B, QString C, QString D)
{
    ui->question->setText(problem);
    ui->A->setText(A);
    ui->B->setText(B);
    ui->C->setText(C);
    ui->D->setText(D);
}

void MemoryUi::showAnswer(int userAnswer,int answer)
{
    if (answer==0) ui->t0->show();
    if (answer==1) ui->t1->show();
    if (answer==2) ui->t2->show();
    if (answer==3) ui->t3->show();
    if (userAnswer!=answer)
    {
        if (userAnswer==0) ui->f0->show();
        if (userAnswer==1) ui->f1->show();
        if (userAnswer==2) ui->f2->show();
        if (userAnswer==3) ui->f3->show();
    }
}

void MemoryUi::hideAnswer()
{
    ui->t0->hide();
    ui->t1->hide();
    ui->t2->hide();
    ui->t3->hide();
    ui->f0->hide();
    ui->f1->hide();
    ui->f2->hide();
    ui->f3->hide();
}

void MemoryUi::nextButton()
{
    emit nextClicked();
}

void MemoryUi::aButton()
{
    emit choiceClicked(0);
}

void MemoryUi::bButton()
{
    emit choiceClicked(1);
}

void MemoryUi::cButton()
{
    emit choiceClicked(2);
}

void MemoryUi::dButton()
{
    emit choiceClicked(3);
}

/*void MemoryUi::buttonClicked()
{
    qDebug() << "buttonClicked()";

    QPushButton *button = static_cast<QPushButton*>(sender());

    if(button == NULL)return;

    qDebug() << button->text();
}*/

/*void MemoryUi::on_next_clicked()
{
    ui->C->setText("hahahaha");
}*/
