#include "table_usluga.h"
#include "ui_table_usluga.h"
#include <QSqlError>
table_usluga::table_usluga(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table_usluga),
    id_valid(QRegularExpression("^\\d{7}$")),
    price_valid(QRegularExpression("^\\d{7}$"))
{
    ui->setupUi(this);
    QSqlQuery query("SELECT * FROM Услуга where Название_Услуги not like '%удалено%'");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
    ui->lineEdit->setValidator(&id_valid);
    ui->lineEdit_3->setValidator(&price_valid);
    if(SqlDB::role == "Employee")
    {
        ui->pushButton_6->hide();
        ui->pushButton_3->hide();
        ui->pushButton_4->hide();
    }
}

table_usluga::~table_usluga()
{
    delete ui;
}

void table_usluga::on_pushButton_clicked()
{
    emit showMain();
    this->close();
}


void table_usluga::on_pushButton_2_clicked() // поиск записи
{
    QString name = ui->lineEdit_2->text();
    QString id = ui->lineEdit->text();
    QString price = ui->lineEdit_3->text();
    QString sign_price = ui->comboBox->currentText();
    QString qry("SELECT * FROM Услуга WHERE ");
    if(name == "" && price == "" && id == "")
        QMessageBox::warning(this,"Ошибка","Введите значения");
    else
    {
    if(name != "" && price != "")
        qry += "Название_Услуги LIKE '%" + name + "%' AND Стоимость " + sign_price + price;
    else if(name!="" && price == "")
        qry += "Название_Услуги LIKE '%" + name + "%'";
    else if (name == "" && price !="")
        qry += "Стоимость " + sign_price + price;
    else if(id!="")
        qry += "Код_Услуги =" + id;
    update_table(qry);
    }
}

void table_usluga::update_table(QString qry)
{
    model =  new QSqlTableModel();
    model->setQuery(qry);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

void table_usluga::reset_table()
{
    model =  new QSqlTableModel();
    model->setQuery("SELECT * FROM Услуга where Название_Услуги not like '%удалено%'");
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}


void table_usluga::on_pushButton_5_clicked() // сброс фильтров
{
    reset_table();
}


void table_usluga::on_pushButton_3_clicked() // добавление записи
{
    QString name = ui->lineEdit_2->text();
    QString id = ui->lineEdit->text();
    QString price = ui->lineEdit_3->text();
    QString qry;
    QSqlQuery query;
    if(name == "" && price == "")
    {
        QMessageBox::warning(this,"Ошибка","Введите значения");
    }
    else
    {
        qry = "INSERT INTO Услуга VALUES (NEXT VALUE FOR NumUsluga,'" + name + "'," + price + ")";
        query.exec(qry);
        reset_table();
        qDebug() << query.lastError();
    }
}


void table_usluga::on_pushButton_6_clicked() // изменение записи
{
    QString name = ui->lineEdit_2->text();
    QString id = ui->lineEdit->text();
    QString price = ui->lineEdit_3->text();
    QString qry = "UPDATE Услуга SET ";
    QSqlQuery query;
    if(name == "" && price =="")
        QMessageBox::warning(this,"Ошибка","Введите значения");
    else
    {
        if(name!= "" && price =="")
            qry += "Название_Услуги = '" + name + "' WHERE Код_Услуги = " + id;
        else if (name =="" && price !="")
            qry += "Стоимость = '" + price + "' WHERE Код_Услуги = " + id;
        else if (name !="" && price !="")
            qry += "Название_Услуги = '" + name + "', Стоимость = " + price + " WHERE Код_Услуги = " + id;
    }
    query.exec(qry);
    reset_table();
}


void table_usluga::on_pushButton_4_clicked() //удалени записи
{
    QString name;
    QString id = ui->lineEdit->text();
    QSqlQuery query;
    query.exec("SELECT Название_Услуги FROM Услуга WHERE Код_Услуги = " + id);
    while(query.next())
    {
        name = query.value(0).toString();
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Удаление записи","Вы уверены что хотите удалить запись?", QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        query.exec("INSERT INTO Журнал_удалений VALUES ('" + name + "', 'Услуга',SYSDATETIME())");
        query.exec("UPDATE Услуга SET Название_Услуги = '" + name + "(удалено)' WHERE Код_Услуги = " + id);
    }
    reset_table();
}

