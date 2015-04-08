#ifndef MEMORYUI_H
#define MEMORYUI_H

#include <QWidget>

namespace Ui {
class MemoryUi;
}

class MemoryUi : public QWidget
{
    Q_OBJECT

public:
    explicit MemoryUi(QWidget *parent = 0);
    ~MemoryUi();

private:
    Ui::MemoryUi *ui;

signals:
    void backClicked();
};

#endif // MEMORYUI_H
