#include "personalaccount.h"
#include "ui_personalaccount.h"
#include <iostream>

PersonalAccount::PersonalAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonalAccount),
    phone_valid(QRegularExpression("^\\d{11}$")),
    mail_valid(QRegularExpression("^[\\w-]+@([\\w-]+\\.)+[\\w-]+$")),
    fio_valid(QRegularExpression("^[A-Za-z|А-Яа-я]{1,}\\s[A-Z|А-Я][.][A-Z|А-Я][.]$"))
    //fio_valid(QRegularExpression("^[A-Z|А-Я]{1}[A-Za-z 0-9-]{1,12}$"))
{
    ui->setupUi(this);
    ui->PhoneLine->setValidator(&phone_valid);
    ui->FioLine->setValidator(&fio_valid);
    ui->MailLine->setValidator(&mail_valid);
    ui->FioLine->setToolTip("пр.: Иванов И.И.");
    ui->PhoneLine->setToolTip("пр. 88005553535");
    ui->label_6->setVisible(false);
    ui->label_8->setVisible(false);
    ui->label_7->setText("Ваш ID: " + QVariant(SqlDB::id).toString());
    QSqlQuery query("SELECT * FROM Клиент WHERE Код_Клиента = " + QVariant(SqlDB::id).toString());
    query.next();
    ui->FioLine->setText(QVariant(query.value(1)).toString());
    ui->PhoneLine->setText(QVariant(query.value(2)).toString());
    ui->MailLine->setText(QVariant(query.value(3)).toString());
    if (QVariant(query.value(4)).toString() == "м")
        ui->comboBox->setCurrentIndex(1);
    else
        ui->comboBox->setCurrentIndex(0);
}

PersonalAccount::~PersonalAccount()
{
    delete ui;
}

void PersonalAccount::on_pushButton_clicked()
{
    this->close();
    emit showMain();
}

void PersonalAccount::on_pushButton_2_clicked()
{
    QSqlQuery query;
    QString fio;
    QString phone;
    QString sex;
    QString mail;
    QString idd;
    idd = QVariant(SqlDB::id).toString();
    if (ui->FioLine->text()!="" && ui->MailLine->text()!="" && ui->PhoneLine->text()!="")
    {
        QString idd;
        idd = QVariant(SqlDB::id).toString();
        fio = ui->FioLine->text();
        sex = ui->comboBox->currentText();
        phone = ui->PhoneLine->text();
        mail = ui->MailLine->text();
        qDebug() << fio << phone << mail << idd;
        query.exec("UPDATE Клиент SET Фио = '" + fio + "', Телефон = " + phone + ", Почта = '" + mail + "' WHERE Код_Клиента = " + idd);
        qDebug() << query.lastError();
        ui->label_8->setVisible(true);
    }
    else
    {
        ui->label_6->setVisible(true);
    }
}
