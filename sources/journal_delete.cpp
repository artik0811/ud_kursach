#include "journal_delete.h"
#include "ui_journal_delete.h"
#include <QSqlError>
journal_delete::journal_delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::journal_delete)
{
    ui->setupUi(this);
    QSqlQuery query("SELECT * FROM Журнал_удалений");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

journal_delete::~journal_delete()
{
    delete ui;
}

void journal_delete::on_pushButton_clicked()
{
    emit showMain();
    this->close();
}


void journal_delete::on_pushButton_2_clicked()
{
    QMap <QString,QString> tables_name; // мапа хранящая названия столбцов имен таблиц
    tables_name["Доп_Оборудование"] = "Название";
    tables_name["Клиент"] = "ФИО";
    tables_name["Сотрудник"] = "ФИО";
    tables_name["Студия"] = "Название_Студии";
    tables_name["Услуга"] = "Название_Услуги";
    QSqlQuery query;
    QString table;
    QString name = ui->lineEdit->text();
    query.exec("SELECT * FROM Журнал_удалений WHERE Имя = '" + name + "'");
    while(query.next())
    {
        table = query.value(1).toString();
    }
    query.exec("UPDATE " + table + " SET " + tables_name[table] + " = '" + name + "' WHERE " + tables_name[table] + " = '" + name + "(удалено)'");
    qDebug() << '\n' << query.lastQuery() << '\n' << query.lastError();
    query.exec("DELETE FROM Журнал_удалений WHERE Имя = '" + name + "'");
    QSqlQuery qry("SELECT * FROM Журнал_удалений");
    model =  new QSqlTableModel();
    model->setQuery(qry);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

