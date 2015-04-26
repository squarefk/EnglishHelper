#ifndef CONTROL_H
#define CONTROL_H

#include "chooseui.h"
#include "findui.h"
#include "memoryui.h"
#include "articleui.h"
#include "settingsui.h"
#include "func.h"

#include <QMainWindow>
#include <QStackedWidget>
#include <QMessageBox>

namespace Ui {
class Control;
}

class Control : public QMainWindow
{
    Q_OBJECT

public:
    explicit Control(QWidget *parent = 0);
    ~Control();

private:
    Ui::Control *ui;
    QStackedWidget *stack;
    ChooseUi *chooseUi;
    FindUi *findUi;
    MemoryUi *memoryUi;
    ArticleUi *articleUi;
    SettingsUi *settingsUi;
    Func *func;
    Func::TestPair* questions;
    int totalQuestions,nowQuestions,correctQuestions;

private slots:
    void showChoose();
    void showFind();
    void showMemory();
    void showArticle();
    void showSettings();
    void query(QString);
    void analysis(QString);
    void memoryStart();
    void memoryChoiceClicked(int);
    void memoryNextClicked();
    void loadXML(QString);
};

#endif // CONTROL_H
