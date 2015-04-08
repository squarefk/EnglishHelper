#ifndef SETTINGSUI_H
#define SETTINGSUI_H

#include <QWidget>

namespace Ui {
class SettingsUi;
}

class SettingsUi : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsUi(QWidget *parent = 0);
    ~SettingsUi();

private:
    Ui::SettingsUi *ui;

signals:
    void backClicked();
};

#endif // SETTINGSUI_H
