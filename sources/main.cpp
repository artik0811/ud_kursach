#include "includes/mainwindow.h"
#include "includes/autorization.h"
#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Autorization aut;
    MainWindow w;
    aut.show();
    return a.exec();
}

