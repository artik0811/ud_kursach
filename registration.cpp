#include "registration.h"
#include "ui_registration.h"
Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration),
    phone_valid(QRegularExpression("^\\d{11}$")),
    mail_valid(QRegularExpression("^[\\w-]+@([\\w-]+\\.)+[\\w-]+$")),
    fio_valid(QRegularExpression("^[A-Za-z|А-Яа-я]{1,}\\s[A-Z|А-Я][.][A-Z|А-Я][.]$"))
{
    ui->setupUi(this);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_11->setVisible(false);
    ui->lineEdit_mail->setValidator(&mail_valid);
    ui->lineEdit->setValidator(&fio_valid);
    ui->loginEdit->setValidator(&phone_valid);
    ui->lineEdit_mail->setToolTip("пример: petyapupkin123@mail.ru");
    ui->lineEdit->setToolTip("пример: Иванов И.И.");
    ui->loginEdit->setToolTip("пример: 88005553535");
}

Registration::~Registration()
{
    delete ui;
}

bool Registration::verif_member(QString login,QString pass,QString pass2,QString mail,QString fio,QString sex)
{
    if(ui->lineEdit->text()!="" || ui->lineEdit_mail->text()!="" || ui->loginEdit->text() !="" || ui->pass1Edit->text()!="")
    {
        QSqlQuery query("SELECT * FROM Клиент WHERE Phone =" + login);
        query.first();
        if(login == query.value(0))
        {
            ui->label_4->setVisible(true);
            return false;
        }
        else if (pass!=pass2)
        {
            ui->label_5->setVisible(true);
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        ui->label_11->setVisible(true);
        return false;
    }
}

void Registration::on_pushButton_clicked()
{
    QString l = ui->loginEdit->text();
    QString p = ui->pass1Edit->text();
    QString p2 = ui->passEdit2->text();
    QString mail = ui->lineEdit_mail->text();
    QString fio = ui->lineEdit->text();
    QString sex;
    QSqlQuery query;
    if(ui->comboBox->currentText() == "Муж.")
        sex = "м";
    else
        sex = "ж";
    if(verif_member(l,p,p2,mail,fio,sex))
    {   //addclient @phone bigint,@pass varchar(100),@fio varchar(50),@mail varchar(30),@sex char(1)
        query.exec("EXEC addclient " + l + ",'" + p + "','" + fio + "','" + mail + "','" + sex + "'");
        ui->label_6->setVisible(true);
    }
}

void Registration::on_pushButton_2_clicked()
{
    this->close();
    emit showAuth();
}
