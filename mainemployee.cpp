#include "mainemployee.h"
#include "ui_mainemployee.h"
#include "sqldb.h"
mainEmployee::mainEmployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainEmployee)
{
    ui->setupUi(this);
    ui->label_2->setText("Ваш ID: " + QVariant(SqlDB::id).toString());
    if(SqlDB::role == "Admin")
        ui->label->setText("Администратор");
}

mainEmployee::~mainEmployee()
{
    delete ui;
}

void mainEmployee::on_pushButton_2_clicked()
{
    table = new table_employee();
    connect(table,&table_employee::showMain,this,&mainEmployee::show);
    table->show();
    this->close();
}


void mainEmployee::on_pushButton_3_clicked()
{
    table_usl = new table_usluga();
    connect(table_usl,&table_usluga::showMain,this,&mainEmployee::show);
    table_usl->show();
    this->close();
}

void mainEmployee::on_pushButton_4_clicked()
{
    table_sotr = new table_sotrudnik();
    connect(table_sotr,&table_sotrudnik::showMain,this,&mainEmployee::show);
    table_sotr->show();
    this->close();
}


void mainEmployee::on_pushButton_clicked()
{
    emit showAuth();
    this->close();
}


void mainEmployee::on_pushButton_11_clicked()
{
    journal = new journal_delete();
    connect(journal,&journal_delete::showMain,this,&mainEmployee::show);
    journal->show();
    this->close();
}


void mainEmployee::on_pushButton_5_clicked()
{
    table_log = new table_login();
    connect(table_log,&table_login::showMain,this,&mainEmployee::show);
    table_log->show();
    this->close();
}

