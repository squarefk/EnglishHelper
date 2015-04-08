#ifndef CHOOSEUI_H
#define CHOOSEUI_H

#include <QWidget>
#include <QFile>

namespace Ui {
class ChooseUi;
}

class ChooseUi : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseUi(QWidget *parent = 0);
    ~ChooseUi();

private:
    Ui::ChooseUi *ui;

signals:
    void findClicked();
    void memoryClicked();
    void articleClicked();
    void settingsClicked();
};

#endif // CHOOSEUI_H
