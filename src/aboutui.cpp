#include "aboutui.h"
#include "ui_aboutui.h"

AboutUi::AboutUi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutUi)
{
    ui->setupUi(this);

    QFile *file = new QFile(":qss/qss/aboutui.qss");
    file->open(QFile::ReadOnly);
    setStyleSheet(file->readAll());
    file->deleteLater();

    connect(ui->back, SIGNAL(clicked()),
            this, SLOT(close()));
}

AboutUi::~AboutUi()
{
    delete ui;
}
