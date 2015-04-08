#include "control.h"

#include <QApplication>
using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Control control;
    control.show();
    return a.exec();
}
