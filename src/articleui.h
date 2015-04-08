#ifndef ARTICLEUI_H
#define ARTICLEUI_H

#include <QWidget>

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

signals:
    void backClicked();
};

#endif // ARTICLEUI_H
