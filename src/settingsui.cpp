#include "settingsui.h"
#include "ui_settingsui.h"

SettingsUi::SettingsUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsUi)
{
    ui->setupUi(this);

    connect(ui->back, SIGNAL(clicked()),
            this, SIGNAL(backClicked()));
}

SettingsUi::~SettingsUi()
{
    delete ui;
}
