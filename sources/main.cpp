#include "mainwindow.h"
#include "autorization.h"
#include <QApplication>
#include <map>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Autorization aut;
    MainWindow w;
    aut.show();
    return a.exec();
}

