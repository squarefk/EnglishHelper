#include "settingsui.h"
#include "ui_settingsui.h"

SettingsUi::SettingsUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsUi)
{
    ui->setupUi(this);

    QFile *file = new QFile(":qss/qss/settingsui.qss");
    file->open(QFile::ReadOnly);
    setStyleSheet(file->readAll());
    file->deleteLater();

    connect(ui->back, SIGNAL(clicked()),
            this, SIGNAL(backClicked()));
    connect(ui->about, SIGNAL(clicked()),
            new AboutUi, SLOT(exec()));
}

SettingsUi::~SettingsUi()
{
    delete ui;
}

int SettingsUi::testNumber()
{
    return ui->spinBox->value();
}
