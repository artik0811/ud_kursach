#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Foto)
{
    ui->setupUi(this);

}

void MainWindow::on_pushButton_clicked()
{
    tableWindow = new Table();
    connect(tableWindow,&Table::showMain,this,&MainWindow::show);
    tableWindow->sett(this->db,"Сотрудник");
    tableWindow->show();
    this->close();
}
void MainWindow::on_pushButton_2_clicked()
{
    tableWindow = new Table();
    connect(tableWindow,&Table::showMain,this,&MainWindow::show);
    tableWindow->sett(this->db,"Клиент");
    tableWindow->show();
    this->close();
}
void MainWindow::on_pushButton_3_clicked()
{
    tableWindow = new Table();
    connect(tableWindow,&Table::showMain,this,&MainWindow::show);
    tableWindow->sett(this->db,"Заказ");
    tableWindow->show();
    this->close();
}

void MainWindow::on_pushButton_4_clicked()
{
    tableWindow = new Table();
    connect(tableWindow,&Table::showMain,this,&MainWindow::show);
    tableWindow->sett(this->db,"Студия");
    tableWindow->show();
    this->close();
}

void MainWindow::on_pushButton_5_clicked()
{
    tableWindow = new Table();
    connect(tableWindow,&Table::showMain,this,&MainWindow::show);
    tableWindow->sett(this->db,"Услуга");
    tableWindow->show();
    this->close();
}

void MainWindow::on_pushButton_6_clicked()
{
    tableWindow = new Table();
    connect(tableWindow,&Table::showMain,this,&MainWindow::show);
    tableWindow->sett(this->db,"Доп_Оборудование");
    tableWindow->show();
    this->close();
}

void MainWindow::on_pushButton_7_clicked()
{
    tableWindow = new Table();
    connect(tableWindow,&Table::showMain,this,&MainWindow::show);
    tableWindow->sett(this->db,"Бронь_оборудавния");
    tableWindow->show();
    this->close();

}

void MainWindow::on_pushButton_8_clicked()
{
    tableWindow = new Table();
    connect(tableWindow,&Table::showMain,this,&MainWindow::show);
    tableWindow->sett(this->db,"Бронь");
    tableWindow->show();
    this->close();
}



MainWindow::~MainWindow()
{
    delete ui;
}


