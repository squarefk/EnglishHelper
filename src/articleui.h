#ifndef ARTICLEUI_H
#define ARTICLEUI_H

#include <QWidget>
#include <QFile>
#include <QLabel>
#include <QTextEdit>

namespace Ui {
class ArticleUi;
}

class ArticleUi : public QWidget
{
    Q_OBJECT

public:
    explicit ArticleUi(QWidget *parent = 0);
    ~ArticleUi();

private:
    Ui::ArticleUi *ui;
    QLabel *label;
    QTextEdit *textEdit;

signals:
    void backClicked();
    void analysis(QString);

private slots:
    void analysisClicked();

public slots:
    void analysisResult(QString);

};

#endif // ARTICLEUI_H
