#include "findui.h"
#include "ui_findui.h"

FindUi::FindUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindUi)
{
    ui->setupUi(this);

    connect(ui->back, SIGNAL(clicked()),
            this, SIGNAL(backClicked()));
    connect(ui->query, SIGNAL(clicked()),
            this, SLOT(queryClicked()));
}

FindUi::~FindUi()
{
    delete ui;
}

void FindUi::queryClicked()
{
    emit query(ui->word->text());
}

void FindUi::queryResult(QString meaning)
{
    ui->meaning->setText(meaning);
}
