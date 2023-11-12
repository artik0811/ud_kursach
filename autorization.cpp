#include "autorization.h"
#include "ui_autorization.h"

Autorization::Autorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Autorization)
{
    ui->setupUi(this);

            //{"admin","admin"},{"guest","123"}
    logins.insert({"admin","admin"});
}

Autorization::~Autorization()
{
    delete ui;
}

bool Autorization::auth()
{
    QString login;
    QString password;
    login = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    std::map<QString,QString>::iterator iter;
    for (auto lp = logins.begin();lp!=logins.end();++lp)
    {
        if(login==lp->first)
        {
            if(password==lp->second)
            {
                return true;
                break;
            }
            else
                continue;
        }
        iter = lp;
        if(lp == logins.end())
            return false;
    }
}

void Autorization::on_pushButton_clicked()
{
    if(auth())
    {

    }
}
