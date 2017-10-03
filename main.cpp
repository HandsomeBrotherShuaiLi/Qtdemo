#include "mainwindow.h"
#include <QApplication>
#include<graphlei.h>
extern int c[6][6];
extern int lowcost[6];
extern int closest[6];
extern bool s[6];

extern node suzu[5];
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
     w.show();

    return a.exec();
}
