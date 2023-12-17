#include "includes/table_bron_obor.h"
#include "ui_table_bron_obor.h"

table_bron_obor::table_bron_obor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table_bron_obor)
{
    ui->setupUi(this);
    QSqlQuery query("SELECT b.Номер_Брони, d.Название FROM Бронь_оборудования as b inner join Доп_Оборудование as d on d.Код_Оборудования = b.Код_Оборудования");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

table_bron_obor::~table_bron_obor()
{
    delete ui;
}

void table_bron_obor::on_pushButton_back_clicked()
{
    emit showMain();
    this->close();
}


void table_bron_obor::on_pushButton_reset_clicked()
{
    reset_table();
    ui->lineEdit_id->setText("");
    ui->lineEdit_name->setText("");
}

void table_bron_obor::update_table(QString qry)
{
    QSqlQuery query(qry);
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

void table_bron_obor::reset_table()
{
    QSqlQuery query("SELECT b.Номер_Брони, d.Название FROM Бронь_оборудования as b inner join Доп_Оборудование as d on d.Код_Оборудования = b.Код_Оборудования");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}


void table_bron_obor::on_pushButton_find_clicked()
{
    QString id = ui->lineEdit_id->text();
    QString name = ui->lineEdit_name->text();
    QString query_string = "SELECT b.Номер_Брони, d.Название FROM Бронь_оборудования as b inner join Доп_Оборудование as d on d.Код_Оборудования = b.Код_Оборудования WHERE ";
    if(id=="" && name == "")
    {
        QMessageBox::warning(this,"Ошибка","Заполните хотя бы 1 поле!");
        return;
    }
    if(id!="" && name == "")
        query_string += " b.Номер_Брони = " + id + " ";
    else if (id=="" && name != "")
        query_string += " d.Название LIKE '%" + name + "%'";
    else if(id != "" && name !="")
        query_string += " d.Название LIKE '%" + name + "%' AND b.Номер_Брони = " + id + " ";
    update_table(query_string);
}

