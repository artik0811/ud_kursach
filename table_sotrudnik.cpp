#include "table_sotrudnik.h"
#include "ui_table_sotrudnik.h"
#include "sqldb.h"
table_sotrudnik::table_sotrudnik(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table_sotrudnik),
    phone_valid(QRegularExpression("^\\d{15}$")),
    id_valid(QRegularExpression("^\\d{15}$"))
{
    ui->setupUi(this);
    QSqlQuery query("SELECT * FROM Сотрудник WHERE ФИО not like '%удалено%'");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
    ui->lineEdit->setValidator(&id_valid);
    ui->lineEdit_5->setValidator(&id_valid);
    if(SqlDB::role == "Employee")
    {
        ui->pushButton_5->hide();
        ui->pushButton_2->hide();
        ui->pushButton_4->hide();
    }
}

table_sotrudnik::~table_sotrudnik()
{
    delete ui;
}

void table_sotrudnik::on_pushButton_clicked()
{
    emit showMain();
    this->close();
}

void table_sotrudnik::update_table(QString qry)
{
    model =  new QSqlTableModel();
    model->setQuery(qry);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

void table_sotrudnik::reset_table()
{
    model =  new QSqlTableModel();
    model->setQuery("SELECT * FROM Сотрудник WHERE ФИО not like '%удалено%'");
    reset_lineedits();
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

void table_sotrudnik::reset_lineedits()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
}

bool table_sotrudnik::isHaveMember(QString phone) // проверка имеется ли пользователь с этим номером
{
    QSqlQuery query("SELECT Phone FROM Логин WHERE Phone = " + phone);
    QSqlQuery query2("SELECT Телефон FROM Сотрудник WHERE Телефон = " + phone);
//    qDebug() << query.lastQuery() << '\n' << query.lastError();
//    qDebug() << query2.lastQuery() << '\n' << query.lastError();
    query.first();
    query2.first();
    qDebug() << query2.value(0).toString() << '\n' << query.value(0).toString();
    if(phone == query.value(0).toString())
    {
        QMessageBox::warning(this,"Ошибка","Пользователь с указанным номером уже существует!");
        return true;
    }
    else if(phone == query2.value(0).toString())
    {
        QMessageBox::warning(this,"Ошибка","Сотрудник с указанным номером уже существует!!");
        return true;
    }
    else
        return false;
}


void table_sotrudnik::on_pushButton_6_clicked() // сброс
{
    reset_table();
}


void table_sotrudnik::on_pushButton_3_clicked() // поиск
{
    QString fio = ui->lineEdit_2->text();
    QString dolzh= ui->lineEdit_4->text();
    QString id= ui->lineEdit->text();
    QString phone= ui->lineEdit_5->text();
    QString date = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString qry = "SELECT * FROM Сотрудник WHERE ";
    QVector <QString> filters;
    filters.push_back("Код_Сотрудника = " + id);
    filters.push_back("ФИО LIKE '%" +fio + "%'");
    filters.push_back("Должность LIKE '%" +dolzh + "%'");
    filters.push_back("Телефон = " + phone);
    if(ui->checkBox->isChecked())
        filters.push_back("Дата_приема = " + date);
    QVector <QString> v1;
    v1.push_back(id);
    v1.push_back(fio);
    v1.push_back(dolzh);
    v1.push_back(phone);
    v1.push_back(date);
    int k =0;
    bool flag = false;
    for(int i=0;i!=filters.size();i++)
    {
        if(v1[i]=="")
            continue;
        else
        {
            flag = true;
            k++;
            if(k>1)
                qry+=" AND ";
            qry += filters[i];
        }
    }
    if(flag)
        update_table(qry);
    else
        QMessageBox::warning(this,"Ошибка","Введите значения");
    qDebug() << qry;
}


void table_sotrudnik::on_pushButton_5_clicked() // удаление
{
    QString name;
    QString id = ui->lineEdit->text();
    QSqlQuery query;
    query.exec("SELECT ФИО FROM Сотрудник WHERE Код_Сотрудника = " + id);
    while(query.next())
    {
        name = query.value(0).toString();
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Удаление записи","Вы уверены что хотите удалить запись?", QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        query.exec("INSERT INTO Журнал_удалений VALUES ('" + name + "', 'Сотрудник',SYSDATETIME())");
        query.exec("UPDATE Сотрудник SET ФИО = '" + name + "(удалено)' WHERE Код_Сотрудника = " + id);
    }
    reset_table();
}


void table_sotrudnik::on_pushButton_4_clicked() // изменение
{
    QString fio = ui->lineEdit_2->text();
    QString dolzh= ui->lineEdit_4->text();
    QString id= ui->lineEdit->text();
    QString phone= ui->lineEdit_5->text();
    QString date = ui->dateEdit->date().toString("yyyy-MM-dd");
    bool check_date = ui->checkBox->isChecked();
    QString qry = "UPDATE Сотрудник SET ";
    QVector <QString> v2,v1;
    v1.push_back("ФИО = '" + fio + "' ");
    v1.push_back("Должность = '" + dolzh + "' ");
    v1.push_back("Телефон = " + phone + " ");
    v2.push_back(fio);
    v2.push_back(dolzh);
    v2.push_back(phone);
    if(check_date)
    {
        v2.push_back(date);
        v1.push_back("Дата_приема = '" + date + "' ");
    }
    int k =0;
    if(id=="")
        QMessageBox::warning(this,"Ошибка","Введите id сотрудника");
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
        qry += " WHERE Код_Сотрудника = " + id;
    }
    QSqlQuery query;
    query.exec(qry);
    qDebug() << qry;
    qDebug() << '\n' << query.lastError();
    reset_table();
}


void table_sotrudnik::on_pushButton_2_clicked() // добавление
{
    QString fio = ui->lineEdit_2->text();
    QString dolzh= ui->lineEdit_4->text();
    QString id= ui->lineEdit->text();
    QString phone= ui->lineEdit_5->text();
    QString password = ui->lineEdit_3->text();
    QString date = ui->dateEdit->date().toString("yyyy-MM-dd");
    QSqlQuery query;
    if(!isHaveMember(phone))
    {
        if(fio!="" && dolzh != "" && phone != "" && password != "")
        {
            QString qry = "INSERT INTO Сотрудник VALUES (NEXT VALUE FOR NumSotr,'" + fio + "','" + dolzh + "',"  + phone + ",'" + date + "')";
            query.exec(qry);
            query.exec("INSERT INTO Логин VALUES (" + phone + ",'" + password + "','Employee')");
            reset_table();
        }
        else
            QMessageBox::warning(this,"Ошибка","Заполните все поля для добавления сотрудника!");
    }
}

