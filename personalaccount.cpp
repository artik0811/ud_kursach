#include "personalaccount.h"
#include "ui_personalaccount.h"
#include <iostream>
#include <QMessageBox>

PersonalAccount::PersonalAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonalAccount),
    phone_valid(QRegularExpression("^\\d{11}$")),
    mail_valid(QRegularExpression("^[\\w-]+@([\\w-]+\\.)+[\\w-]+$")),
    fio_valid(QRegularExpression("^[A-Za-z|А-Яа-я]{1,}\\s[A-Z|А-Я][.][A-Z|А-Я][.]$"))
{
    ui->setupUi(this);
    ui->PhoneLine->setValidator(&phone_valid);
    ui->MailLine->setValidator(&mail_valid);
    ui->PhoneLine->setToolTip("пример: 88005553535");
    ui->MailLine->setToolTip("пример: petyapupkin123@mail.ru");
    ui->label_6->setVisible(false);
    ui->label_8->setVisible(false);
    ui->label_7->setText("Ваш ID: " + QVariant(SqlDB::id).toString());
    QSqlQuery query("SELECT * FROM Клиент WHERE Код_Клиента = " + QVariant(SqlDB::id).toString());
    query.next();
    ui->label_10->setText(QVariant(query.value(1)).toString());
    ui->PhoneLine->setText(QVariant(query.value(2)).toString());
    ui->MailLine->setText(QVariant(query.value(3)).toString());
    ui->label_11->setText(QVariant(query.value(4)).toString());
    ui->pushButton_otmena->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->label_12->setVisible(false);
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
    QString phone;
    QString mail;
    QString idd;
    idd = QVariant(SqlDB::id).toString();
    if (ui->MailLine->text()!="" && ui->PhoneLine->text()!="")
    {
        QString idd;
        idd = QVariant(SqlDB::id).toString();
        phone = ui->PhoneLine->text();
        mail = ui->MailLine->text();
        query.exec("UPDATE Клиент SET Телефон = " + phone + ", Почта = '" + mail + "' WHERE Код_Клиента = " + idd);
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
    ui->pushButton_otmena->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->label_12->setVisible(false);
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
    ui->pushButton_otmena->setVisible(true);
    ui->lineEdit->setVisible(true);
    ui->label_12->setVisible(true);
    QSqlQuery query("select bron.Номер_Брони,Время_Начала,Время_Конца, studia.Название_Студии as [Студия], Статус, Дата "
    "from Бронь as bron "
    "inner join Клиент as client on bron.Код_Клиента = client.Код_Клиента "
    "inner join Студия as studia on bron.Номер_Студии = studia.Номер_Студии "
    "WHERE bron.Код_Клиента = " + QVariant(SqlDB::id).toString());
    //query.exec("select Номер_Брони, Время_Начала,Время_Конца, Номер_Студии, Статус, Дата from бронь where Код_Клиента= " + QString::fromStdString(std::to_string(SqlDB::id)));
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}


void PersonalAccount::on_pushButton_otmena_clicked()
{
    QString id = QVariant(SqlDB::id).toString();
    QString bron = ui->lineEdit->text();
    if(bron == "")
        QMessageBox::warning(this,"Ошибка","Введите номер брони!");
    QSqlQuery  qry("SELECT Статус FROM Бронь WHERE Номер_Брони = " + bron);
    qry.first();
    QSqlQuery query;
    if(qry.value(0)=="Не Завершен")
        query.exec("UPDATE Бронь SET Статус = 'Отменено' WHERE Номер_Брони = " + bron + " AND Код_Клиента = " + id);
    else
        QMessageBox::warning(this,"Ошибка","Отменить можно только предстоящую бронь!");
    qDebug() << query.lastError() << '\n' << query.lastQuery();
    query.exec("select bron.Номер_Брони,Время_Начала,Время_Конца, studia.Название_Студии as [Студия], Статус, Дата "
    "from Бронь as bron "
    "inner join Клиент as client on bron.Код_Клиента = client.Код_Клиента "
    "inner join Студия as studia on bron.Номер_Студии = studia.Номер_Студии "
    "WHERE bron.Код_Клиента = " + QVariant(SqlDB::id).toString());
    //query.exec("select Номер_Брони, Время_Начала,Время_Конца, Номер_Студии, Статус, Дата from бронь where Код_Клиента= " + QString::fromStdString(std::to_string(SqlDB::id)));
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

