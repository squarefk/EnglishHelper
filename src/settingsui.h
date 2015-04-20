#ifndef SETTINGSUI_H
#define SETTINGSUI_H

#include "aboutui.h"

#include <QWidget>
#include <QFile>

namespace Ui {
class SettingsUi;
}

class SettingsUi : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsUi(QWidget *parent = 0);
    ~SettingsUi();
    int testNumber();

private:
    Ui::SettingsUi *ui;

signals:
    void backClicked();
};

#endif // SETTINGSUI_H
