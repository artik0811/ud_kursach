#include "personalaccount.h"
#include "ui_personalaccount.h"
#include <iostream>

PersonalAccount::PersonalAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonalAccount),
    phone_valid(QRegularExpression("^\\d{11}$")),
    mail_valid(QRegularExpression("^[\\w-]+@([\\w-]+\\.)+[\\w-]+$")),
    fio_valid(QRegularExpression("^[A-Za-z|А-Яа-я]{1,}\\s[A-Z|А-Я][.][A-Z|А-Я][.]$"))
{
    ui->setupUi(this);
    ui->PhoneLine->setValidator(&phone_valid);
    ui->FioLine->setValidator(&fio_valid);
    ui->MailLine->setValidator(&mail_valid);
    ui->FioLine->setToolTip("пример: Иванов И.И.");
    ui->PhoneLine->setToolTip("пример: 88005553535");
    ui->MailLine->setToolTip("пример: petyapupkin123@mail.ru");
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
        query.exec("UPDATE Клиент SET Фио = '" + fio + "', Телефон = " + phone + ", Почта = '" + mail + "', Пол = '" + sex + "' WHERE Код_Клиента = " + idd);
        qDebug() << query.lastError();
        ui->label_8->setVisible(true);
    }
    else
    {
        ui->label_6->setVisible(true);
    }
}

void PersonalAccount::on_pushButton_3_clicked()
{
    QSqlQuery query;
    query.exec("SELECT z.Номер_Заказа AS [Номер Заказа],Название_Услуги as Услуга,Количество,Ссылка,Дата_Выполнения AS Дата,s.ФИО AS Сотрудник,Общая_Стоимость AS [Общая Стоимость] FROM Заказ AS z INNER JOIN Клиент AS k ON z.Код_Клиента = k.Код_Клиента INNER JOIN Услуга AS u ON z.Код_Услуги = u.Код_Услуги INNER JOIN Сотрудник AS s ON z.Сотрудник = s.Код_Сотрудника WHERE z.Код_Клиента = " + QString::fromStdString(std::to_string(SqlDB::id)));
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}


void PersonalAccount::on_pushButton_4_clicked()
{
    QSqlQuery query;
    query.exec("select Номер_Брони, Время_Начала,Время_Конца, Номер_Студии, Статус, Дата from бронь where Код_Клиента= " + QString::fromStdString(std::to_string(SqlDB::id)));
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

