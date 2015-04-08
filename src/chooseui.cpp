#include "chooseui.h"
#include "ui_chooseui.h"

ChooseUi::ChooseUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseUi)
{
    ui->setupUi(this);

    QFile *file = new QFile(":qss/qss/chooseui.qss");
    file->open(QFile::ReadOnly);
    setStyleSheet(file->readAll());
    file->deleteLater();

    connect(ui->find, SIGNAL(clicked()),
            this, SIGNAL(findClicked()));
    connect(ui->memory, SIGNAL(clicked()),
            this, SIGNAL(memoryClicked()));
    connect(ui->article, SIGNAL(clicked()),
            this, SIGNAL(articleClicked()));
    connect(ui->settings, SIGNAL(clicked()),
            this, SIGNAL(settingsClicked()));
    connect(ui->exit, SIGNAL(clicked()),
            qApp, SLOT(quit()));
}

ChooseUi::~ChooseUi()
{
    delete ui;
}
