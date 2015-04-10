#include "memoryui.h"
#include "ui_memoryui.h"

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
}

MemoryUi::~MemoryUi()
{
    delete ui;
}
