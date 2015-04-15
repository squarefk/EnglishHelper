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

    //
}

MemoryUi::~MemoryUi()
{
    delete ui;
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
