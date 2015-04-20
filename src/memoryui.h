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
    void setBack(bool);
    void setNext(bool);
    void setChoice(bool);
    void showQuestion(QString,QString,QString,QString,QString);
    void showAnswer(int,int);
    void hideAnswer();

private:
    Ui::MemoryUi *ui;

signals:
    void backClicked();
    void nextClicked();
    void choiceClicked(int);

private slots:
    void nextButton();
    void aButton();
    void bButton();
    void cButton();
    void dButton();
    //void on_next_clicked();
};

#endif // MEMORYUI_H
