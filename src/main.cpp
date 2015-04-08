#include "ui.h"

#include <cstdio>
#include <cstdlib>
using namespace std;

Ui *ui;

int main() {
	ui = new Ui;
    while (true) {
        system("clear");
        ui->choose();
		switch (getchar())
		{
            case '1': ui->find(); break;
            case '2': ui->memory(); break;
            case '3': ui->article(); break;
            case '4': ui->settings(); break;
			case '0': return 0;
        }
	}
	return 0;
}
