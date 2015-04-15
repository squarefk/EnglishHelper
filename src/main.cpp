#include "control.h"
#include <iostream>
#include <QApplication>
#include <QDebug>
using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //qDebug()<<QString(argv[0]);
    Control control;
    control.show();
    return a.exec();
}
