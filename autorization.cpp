#include "autorization.h"
#include "ui_autorization.h"
#include <cstdlib>
#include <QSqlError>

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

void Autorization::auth()
{
    QSqlQuery query;
    QString login;
    QString password;
    QString pdb;
    login = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    query.exec("SELECT * FROM dbo.Логин WHERE Phone =" + login);
    if( query.first())
    {
        if(query.value(1).toString()==password)
        {
            flag = true;
            QSqlQuery q("SELECT Код_Клиента FROM Клиент WHERE Телефон = " + login);
            q.first();
            SqlDB::id = q.value(0).toLongLong();
        }
        else
            flag = false;
    }
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
    auth();
        if (flag)
        {
            m = new MainWindow();
            connect(m,&MainWindow::showAuth,this,&Autorization::show);
            m->show();
            this->close();
            ui->lineEdit->setText("Логин");
            ui->lineEdit_2->setText("Пароль");
        }
        else
        {
            ui->label_2->setVisible(true);
        }
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
