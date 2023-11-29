#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "conf.h"
#include "sqldb.h"
#include <iostream>
#include "personalaccount.h"
#include "table.h"
#include "bron.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Foto; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();

signals:
    void showPK();

private:
    Ui::Foto *ui;
    Table *tableWindow;
    SqlDB db;
    PersonalAccount *pk;
    bron *bronWin;
};
#endif // MAINWINDOW_H
