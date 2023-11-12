#include "mainwindow.h"
#include "autorization.h"
#include <QApplication>
#include <map>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Autorization aut;
    MainWindow w;
    aut.show();
    if(aut.auth())
        w.show();
    else
        aut.show();
    return a.exec();
}

