#include "memoryui.h"
#include "ui_memoryui.h"

MemoryUi::MemoryUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemoryUi)
{
    ui->setupUi(this);

    connect(ui->back, SIGNAL(clicked()),
            this, SIGNAL(backClicked()));
}

MemoryUi::~MemoryUi()
{
    delete ui;
}
