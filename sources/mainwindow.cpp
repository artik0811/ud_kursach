#include "includes/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Foto)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.exec("SELECT ФИО FROM Клиент WHERE Код_Клиента = " + QVariant(SqlDB::id).toString());
    QString name;
    while(query.next())
         name = query.value(0).toString();
    ui->label->setText("Добро пожаловать, " + name + "!");
}

void MainWindow::on_pushButton_clicked()
{
    tableWindow = new Table();
    connect(tableWindow,&Table::showMain,this,&MainWindow::show);
    tableWindow->sett(this->db,"Сотрудник", "SELECT ФИО, Должность, Телефон FROM Сотрудник WHERE ФИО NOT LIKE '%(удалено)%'");
    tableWindow->show();
    this->close();
}


void MainWindow::on_pushButton_4_clicked()
{
    tableWindow = new Table();
    connect(tableWindow,&Table::showMain,this,&MainWindow::show);
    tableWindow->sett(this->db,"Студия", "SELECT Название_Студии as Название, Площадь, Адрес, Цена FROM Студия WHERE Название_Студии NOT LIKE '%(удалено)%'");
    tableWindow->show();
    this->close();
}

void MainWindow::on_pushButton_5_clicked()
{
    tableWindow = new Table();
    connect(tableWindow,&Table::showMain,this,&MainWindow::show);
    tableWindow->sett(this->db,"Услуга", "SELECT Название_Услуги as Название, Стоимость FROM Услуга WHERE Название_Услуги NOT LIKE '%(удалено)%'");
    tableWindow->show();
    this->close();
}

void MainWindow::on_pushButton_6_clicked()
{
    tableWindow = new Table();
    connect(tableWindow,&Table::showMain,this,&MainWindow::show);
    tableWindow->sett(this->db,"Доп_Оборудование", "SELECT Название, Стоимость FROM Доп_Оборудование WHERE Название NOT LIKE '%(удалено)%'");
    tableWindow->show();
    this->close();
}

void MainWindow::on_pushButton_8_clicked()
{
    bronWin = new bron();
    connect(bronWin,&bron::showMain,this,&MainWindow::show);
    bronWin->show();
    this->close();
}

void MainWindow::on_pushButton_9_clicked()
{
    pk = new PersonalAccount();
    connect (pk,&PersonalAccount::showMain,this,&MainWindow::show);
    pk->show();
    this->close();
}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_7_clicked()
{
    this->close();
    emit showAuth();
}

