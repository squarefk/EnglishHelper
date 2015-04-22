#include "articleui.h"
#include "ui_articleui.h"

ArticleUi::ArticleUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArticleUi)
{
    ui->setupUi(this);

    QFile *file = new QFile(":qss/qss/articleui.qss");
    file->open(QFile::ReadOnly);
    setStyleSheet(file->readAll());
    file->deleteLater();

    label = new QLabel;
    label->setWordWrap(true);
    ui->scrollArea_2->setWidget(label);

    textEdit = new QTextEdit;
    ui->scrollArea->setWidget(textEdit);

    connect(ui->back, SIGNAL(clicked()),
            this, SIGNAL(backClicked()));
    connect(ui->analysis, SIGNAL(clicked()),
            this, SLOT(analysisClicked()));
}

ArticleUi::~ArticleUi()
{
    delete ui;
}

void ArticleUi::analysisResult(QString result)
{
    label->setText(result);
}

void ArticleUi::analysisClicked()
{
    emit analysis(textEdit->toPlainText());
}
