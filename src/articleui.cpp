#include "articleui.h"
#include "ui_articleui.h"

ArticleUi::ArticleUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArticleUi)
{
    ui->setupUi(this);

    connect(ui->back, SIGNAL(clicked()),
            this, SIGNAL(backClicked()));
}

ArticleUi::~ArticleUi()
{
    delete ui;
}
