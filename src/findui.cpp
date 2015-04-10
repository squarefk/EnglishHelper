#include "findui.h"
#include "ui_findui.h"

FindUi::FindUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindUi)
{
    ui->setupUi(this);

    QFile *file = new QFile(":qss/qss/findui.qss");
    file->open(QFile::ReadOnly);
    setStyleSheet(file->readAll());
    file->deleteLater();

    meaning = new QLabel;
    meaning->setWordWrap(true);
    ui->word->setFocus();
    ui->scrollArea->setWidget(meaning);

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

void FindUi::queryResult(QString content)
{
    meaning->setText(content);
}
