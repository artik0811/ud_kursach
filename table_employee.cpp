#include "table_employee.h"
#include "ui_table_employee.h"
#include <QModelIndex>
#include <QSqlError>
#include <QMessageBox>
#include "sqldb.h"
table_employee::table_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table_employee),
    id_valid(QRegularExpression("^\\d{15}$")),
    ploshad_valid(QRegularExpression("^\\d{1,}\\,{1}\\d{2}$")),
    price_valid(QRegularExpression("^\\d{10}$"))
{
    ui->setupUi(this);
    QSqlQuery query("SELECT * FROM Студия WHERE Название_Студии not like '%удалено%'");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
    ui->lineEdit->setValidator(&id_valid);
    ui->lineEdit_3->setValidator(&price_valid);
    ui->lineEdit_5->setValidator(&ploshad_valid);
    if(SqlDB::role == "Employee")
    {
        ui->pushButton_5->hide();
        ui->pushButton_2->hide();
        ui->pushButton_4->hide();
    }
}


table_employee::~table_employee()
{
    delete ui;
}

void table_employee::update_table(QString qry)
{
    QSqlQuery query(qry);
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

void table_employee::reset_table()
{
    QSqlQuery query("SELECT * FROM Студия WHERE Название_Студии not like '%удалено%'");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}


void table_employee::on_pushButton_clicked()
{
    this->close();
    emit showMain();
}


void table_employee::on_pushButton_2_clicked() // добавление записи
{
    QString name = ui->lineEdit_2->text();
    QString price = ui->lineEdit_3->text();
    QString id = ui->lineEdit->text();
    QString ploshad = ui->lineEdit_5->text();
    QString address = ui->lineEdit_4->text();
    if(name != "" && price != "" && ploshad != "" && address !="")
    {
        QSqlQuery query("INSERT INTO Студия values (NEXT VALUE FOR NumStud,'" + name + "'," + ploshad + ",'" + address + "'," + price + ")" );
        query.exec();
        reset_table();
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Введите значения");
    }
}


void table_employee::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}


void table_employee::on_pushButton_5_clicked() // удаление записи
{
    QString id = ui->lineEdit->text();
    QString name;
    QSqlQuery query;
    query.exec("SELECT Название_Студии FROM Студия WHERE Номер_Студии = " + id);
    while(query.next())
    {
        name = query.value(0).toString();
    }
    if(id == "")
        QMessageBox::warning(this,"Ошибка","Введите id студии");
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Удаление записи","Вы уверены что хотите удалить запись?", QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        query.exec("INSERT INTO Журнал_удалений VALUES ('" + name + "', 'Студия',SYSDATETIME())");
        query.exec("UPDATE Студия SET Название_Студии = '" + name + "(удалено)' WHERE Номер_Студии = " + id);
    }
    reset_table();
}


void table_employee::on_pushButton_3_clicked() // поиск записи
{
    QString name = ui->lineEdit_2->text();
    QString price = ui->lineEdit_3->text();
    QString id = ui->lineEdit->text();
    QString ploshad = ui->lineEdit_5->text();
    QString address = ui->lineEdit_4->text();
    QString sign = ui->comboBox->currentText();
    QString sign_ploshad = ui->comboBox_2->currentText();
    QString qry;
    QVector <QString> v1,v2;
    v2.push_back(name);
    v2.push_back(price);
    v2.push_back(ploshad);
    v2.push_back(address);
    v1.push_back("Название_Студии LIKE '%" + name + "%' ");
    v1.push_back("Цена" +sign + price + " ");
    v1.push_back("Площадь" + sign_ploshad + ploshad + " ");
    v1.push_back("Адрес LIKE '%" + address + "%' ");
    qry = "SELECT * FROM Студия WHERE ";
    int k =0;
    for(int i=0;i!=v1.size();i++)
    {
        if(v2[i]=="")
            continue;
        else
        {
            k++;
            if(i!=0 && k>1)
                qry +=" AND " + v1[i];
            else
                qry +=v1[i];
        }
    }
    if(name != "" || price != "" || ploshad != "" || address !="")
        update_table(qry);
    else
        QMessageBox::warning(this,"Ошибка","Введите значения");
}


void table_employee::on_pushButton_6_clicked() // перезагрузка таблицы
{
    reset_table();
    ui->lineEdit->text()="";
    ui->lineEdit_2->text()="";
    ui->lineEdit_3->text()="";
    ui->lineEdit_4->text()="";
    ui->lineEdit_5->text()="";
}




void table_employee::on_pushButton_4_clicked() // изменение записи
{
    QString name = ui->lineEdit_2->text();
    QString price = ui->lineEdit_3->text();
    QString id = ui->lineEdit->text();
    QString ploshad = ui->lineEdit_5->text();
    QString address = ui->lineEdit_4->text();
    QString qry = "UPDATE Студия SET ";
    QVector <QString> v2,v1;
    v1.push_back("Название_Студии = '" + name + "' ");
    v1.push_back("Цена = " + price + " ");
    v1.push_back("Площадь = " + ploshad + " ");
    v1.push_back("Адрес = '" + address + "' ");
    v2.push_back(name);
    v2.push_back(price);
    v2.push_back(ploshad);
    v2.push_back(address);
    int k =0;
    if(id=="")
        QMessageBox::warning(this,"Ошибка","Введите id студии");
    else
    {
        for(int i=0;i!=v2.size();i++)
        {
            if(v2[i]=="")
                continue;
            else
            {
                k++;
                if(i!=0 && k>1)
                    qry +=", " + v1[i];
                else
                    qry +=v1[i];
            }
        }
        qry += " WHERE Номер_Студии = " + id;
    }
    qDebug() << qry;
    QSqlQuery query;
    query.lastError();
    query.exec(qry);
    reset_table();
}

