#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::addMember()
{
    bool ok;
    QString l = ui->loginEdit->text();
    l.QString::toLong(&ok,10);
    QString p = ui->pass1Edit->text();
    QString p2 = ui->passEdit2->text();
    QSqlQuery query("SELECT * FROM dbo.Логин WHERE Phone =" + l);
    query.first();
    if(l == query.value(0))
    {
        ui->label_4->setVisible(true);
    }
    else if (p!=p2)
    {
        ui->label_5->setVisible(true);
    }
    else if(ok)
    {
        {
            query.exec("INSERT INTO Логин Values (" + l + ",'" + p + "')");
            ui->label_6->setVisible(true);
        }
    }
    else
        ui->label_7->setVisible(true);
}


void Registration::on_pushButton_clicked()
{
    addMember();
}

void Registration::on_pushButton_2_clicked()
{
    this->close();
    emit showAuth();
}
