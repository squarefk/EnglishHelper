#ifndef ABOUTUI_H
#define ABOUTUI_H

#include <QDialog>
#include <QFile>

namespace Ui {
class AboutUi;
}

class AboutUi : public QDialog
{
    Q_OBJECT

public:
    explicit AboutUi(QWidget *parent = 0);
    ~AboutUi();

private:
    Ui::AboutUi *ui;
};

#endif // ABOUTUI_H
