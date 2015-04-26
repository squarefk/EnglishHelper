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
    connect(ui->init, SIGNAL(clicked()),
            this, SLOT(initClicked()));
    connect(ui->select, SIGNAL(clicked()),
            this, SLOT(selectClicked()));
}

SettingsUi::~SettingsUi()
{
    delete ui;
}

int SettingsUi::testNumber()
{
    return ui->spinBox->value();
}

void SettingsUi::initClicked()
{
    ui->spinBox->setValue(20);
}

void SettingsUi::selectClicked()
{
    QFileDialog* file = new QFileDialog;
    file->setModal( QFileDialog::AnyFile );
    if ( file->exec() == QDialog::Accepted )
        emit loadXML(file->selectedFiles().at(0));
}
