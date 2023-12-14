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
    if(SqlDB::role == "Employee")
    {
        ui->pushButton_11->setVisible(false);
        ui->pushButton_5->setVisible(false);
    }
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


void mainEmployee::on_pushButton_6_clicked()
{
    table_clnt = new table_client();
    connect(table_clnt,&table_client::showMain,this,&mainEmployee::show);
    table_clnt->show();
    this->close();
}


void mainEmployee::on_pushButton_7_clicked()
{
    table_zkz = new table_zakaz();
    connect (table_zkz,&table_zakaz::showMain,this,&mainEmployee::show);
    table_zkz->show();
    this->close();
}


void mainEmployee::on_pushButton_8_clicked()
{
    table_obor = new table_dop_obor();
    connect(table_obor,&table_dop_obor::showMain,this,&mainEmployee::show);
    table_obor->show();
    this->close();
}


void mainEmployee::on_pushButton_9_clicked()
{
    table_brbr = new table_bron_obor();
    connect(table_brbr,&table_bron_obor::showMain,this,&mainEmployee::show);
    table_brbr->show();
    this->close();
}


void mainEmployee::on_pushButton_10_clicked()
{
    table_bron = new table_brron();
    connect(table_bron,&table_brron::showMain,this,&mainEmployee::show);
    table_bron->show();
    this->close();
}

