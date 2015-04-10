#ifndef FINDUI_H
#define FINDUI_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QFile>

namespace Ui {
class FindUi;
}

class FindUi : public QWidget
{
    Q_OBJECT

public:
    explicit FindUi(QWidget *parent = 0);
    ~FindUi();
    void queryResult(QString);

private:
    QLabel *meaning;
    Ui::FindUi *ui;

signals:
    void backClicked();
    void query(QString);

private slots:
    void queryClicked();
};

#endif // FINDUI_H
