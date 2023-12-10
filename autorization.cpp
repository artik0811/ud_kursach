#include "autorization.h"
#include "ui_autorization.h"
#include <cstdlib>
#include <QMessageBox>
Autorization::Autorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Autorization)
{
    ui->setupUi(this);
    ui->label_2->setVisible(false);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    connect(ui->radioButton,&QRadioButton::clicked,this,&Autorization::showPassword);
}

Autorization::~Autorization()
{
    delete ui;
}

bool Autorization::auth()
{
    QSqlQuery query;
    QString login;
    QString password;
    QString pdb;
    login = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    query.exec("SELECT * FROM dbo.Логин WHERE Phone =" + login);
    query.first();
    if(query.value(0).toString()==login) // первая строка ответа на запрос
    {
        if(query.value(1).toString()==password)
        {
            QSqlQuery qrole("SELECT Role FROM Логин WHERE Phone = " + login);
            qrole.first();
            SqlDB::role = qrole.value(0).toString();
            QSqlQuery q("SELECT Код_Клиента FROM Клиент WHERE Телефон = " + login);
            if(q.next())
            {
                SqlDB::id = q.value(0).toLongLong();
                flag = true;
                return true;
            }
            else
            {
                q.exec("SELECT Код_Сотрудника FROM Сотрудник WHERE Телефон = " + login);
                q.first();
                SqlDB::id = q.value(0).toLongLong();
                flag = true;
                return true;
            }
        }
        else
        {
            flag = false;
            return false;
        }
    }
    else
        return false;
}

void Autorization::showPassword()
{
    if(ui->lineEdit_2->echoMode() == QLineEdit::Password)
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    else
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}


void Autorization::on_pushButton_clicked()
{
        if (auth())
        {
        if(SqlDB::role == "Employee" || SqlDB::role == "Admin")
            {

                mainEmployeeForm = new mainEmployee();
                connect(mainEmployeeForm,&mainEmployee::showAuth,this,&Autorization::show);
                mainEmployeeForm->show();
                this->close();
            }
            else
            {
                m = new MainWindow();
                connect(m,&MainWindow::showAuth,this,&Autorization::show);
                m->show();
                this->close();
                ui->lineEdit->setText("Логин");
                ui->lineEdit_2->setText("Пароль");
            }
        }
        else
        {
            ui->label_2->setVisible(true);
        }
        qDebug() << SqlDB::role;
}

void Autorization::on_pushButton_2_clicked()
{
        ui->lineEdit->setText("Логин");
        ui->lineEdit_2->setText("Пароль");
        r = new Registration();
        connect(r,&Registration::showAuth,this,&Autorization::show);
        r->show();
        this->close();
}



