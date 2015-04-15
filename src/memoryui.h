#ifndef MEMORYUI_H
#define MEMORYUI_H

#include <QWidget>
#include <QFile>

namespace Ui {
class MemoryUi;
}

class MemoryUi : public QWidget
{
    Q_OBJECT

public:
    explicit MemoryUi(QWidget *parent = 0);
    ~MemoryUi();
    void newTest(QString primaryWord,QString* primaryList);

private:
    Ui::MemoryUi *ui;


signals:
    void backClicked();
private slots:
    //void on_next_clicked();
};

#endif // MEMORYUI_H
