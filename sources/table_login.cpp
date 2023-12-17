#include "includes/table_login.h"
#include "ui_table_login.h"
#include <QMessageBox>
table_login::table_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table_login),
    phone_valid(QRegularExpression("^\\d{15}$"))
{
    ui->setupUi(this);
    QSqlQuery query;
    query.exec("SELECT * FROM Логин");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
    if(SqlDB::role != "Admin")
        ui->changeButton->hide(); // скрытие кнопки изменить для не админов
    ui->lineEdit_login->setValidator(&phone_valid);
}

table_login::~table_login()
{
    delete ui;
}

void table_login::on_backButton_clicked()
{
    emit showMain();
    this->close();
}


void table_login::on_findButton_clicked() // поиск
{
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    QString role = ui->lineEdit_role->text();
    QString query = "SELECT * FROM Логин WHERE ";
    QVector <QString> filters,le;
    filters.push_back("Phone = " + login);
    filters.push_back("Password LIKE '%" + password + "%'");
    filters.push_back("Role LIKE '%" + role + "%'");
    le.push_back(login);
    le.push_back(password);
    le.push_back(role);
    int k =0;
    if(login != "" && password != "" && role != "")
    {
        for (int i=0;i!=le.size();i++)
        {
            if(le[i]=="")
                continue;
            else
            {
                k++;
                if(k>1)
                    query += " AND " + filters[i] + " ";
                else
                    query += filters[i];
            }
        }
        update_table(query);
        }
    else
        QMessageBox::warning(this,"Ошибка","Введите значения");
}

void table_login::update_table(QString qry)
{
    model =  new QSqlTableModel();
    model->setQuery(qry);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

void table_login::reset_table()
{
    model =  new QSqlTableModel();
    model->setQuery("SELECT * FROM Логин");
    reset_lineedits();
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

void table_login::reset_lineedits()
{
    ui->lineEdit_login->setText("");
    ui->lineEdit_password->setText("");
    ui->lineEdit_role->setText("");
}


void table_login::on_pushButton_clicked()
{
    reset_table();
}



void table_login::on_changeButton_clicked() // изменить
{
    QString password = ui->lineEdit_password->text();
    QString role = ui->lineEdit_role->text();
    QString query("UPDATE Логин SET ");
    QString phone = ui->lineEdit_login->text();
    if(phone == "")
    {
        QMessageBox::warning(this,"Ошибка","Введите телефон пользователя");
        return;
    }
    if(role !="Employee" && role != "Admin" && role != "Client")
    {
        QMessageBox::warning(this,"Ошибка","Роль может быть только Admin, Client или Employee");
        return;
    }
    if(role == "" && password == "")
    {
        QMessageBox::warning(this,"Ошибка","Введите значения");
        return;
    }
    else
    {
        if(role!= "" && password == "")
        {
            query += "Role = '" + role + "'";
        }
        else if(role == "" && password != "")
            query += "Password = '" + password + "'";
        else
            query += "Password = '" + password + "',Role = '" + role = "'";
        query += "WHERE Phone = " + phone;
        QSqlQuery qry(query);
        reset_table();
    }
}

