#include "includes/table.h"
#include "ui_table.h"
Table::Table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    ui->label_4->setVisible(false);
    ui->tableView->setSortingEnabled(true);
}

void Table::sett(SqlDB db,const QString t, const QString q)
{
    table_name = t;
    table_query = q;
    db.model = new QSqlTableModel (this,db.server);
    db.model->setQuery(q);
    if (t=="Сотрудник")
    {
        ui->label->setText("ФИО:");
        ui->label_2->setText("Должность:");
        ui->comboBox_2->setVisible(false);
        QSize sz(113,24);
        ui->lineEdit_2->size() = sz;
    }
    if (t != "Студия")
    {
        ui->comboBox->hide();
        ui->label_3->hide();
        ui->lineEdit_3->hide();
    }
    else flag_studia = true;
    ui->tableView->setModel(db.model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

Table::~Table()
{
    delete ui;
}

void Table::on_pushButton_clicked()
{
    this->close();
    emit showMain();
}

void Table::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text()=="" && ui->lineEdit_2->text()=="" && ui->lineEdit_3->text() == "")
        ui->label_4->setVisible(true);
    else
    {
        QString name = ui->lineEdit->text();
        QString price = ui->lineEdit_2->text();
        QString size = ui->lineEdit_3->text();
        QString dolzh = price;
        QString sign_ploshad = ui->comboBox->currentText();
        QString query;// Сотрудник СТудия Услуга Доп_Оборудование
        if (table_name=="Сотрудник")
        {
            if(name!="" && dolzh=="")
                query = "SELECT ФИО, Должность, Телефон FROM Сотрудник WHERE ФИО LIKE '%" + name + "%'";
            else if (name=="" && dolzh !="")
                query = "SELECT ФИО, Должность, Телефон FROM Сотрудник WHERE Должность LIKE '%" + dolzh + "%'";
            else
                query = "SELECT ФИО, Должность, Телефон FROM Сотрудник WHERE ФИО LIKE '%" + name + "%' AND ФИО LIKE '%" + name + "%'";
        }
        if (table_name == "Услуга")
        {
            QString sign = ui->comboBox_2->currentText(); // знаки равенства
            if (name!="" && price =="")
                query = "SELECT Название_Услуги as Название, Стоимость AS Цена FROM Услуга WHERE Название_Услуги LIKE '%" + name + "%'";
            else if (name=="" && price !="")
                query = "SELECT Название_Услуги as Название, Стоимость AS Цена FROM Услуга WHERE Стоимость " + sign + " " + price;
            else
                query = "SELECT Название_Услуги as Название, Стоимость AS Цена FROM Услуга WHERE Название_Услуги LIKE '%" + name + "%' AND Стоимость " + sign + " " + price;
        }
        if(table_name == "Доп_Оборудование")
        {
            QString sign = ui->comboBox_2->currentText();
            if (name!="" && price =="")
                query = "SELECT Название, Стоимость FROM Доп_Оборудование WHERE Название LIKE '%" + name + "%'";
            else if (name=="" && price !="")
                query = "SELECT Название, Стоимость FROM Доп_Оборудование WHERE Стоимость " + sign + " " + price;
            else
                query = "SELECT Название, Стоимость FROM Доп_Оборудование WHERE Название LIKE '%" + name + "%' AND Стоимость " + sign + " " + price;
        }
        if(table_name == "Студия")
        {
            query = "SELECT Название_Студии as Студия, Площадь, Адрес, Цена FROM Студия WHERE Название_Студии NOT LIKE '%(удалено)%'";
            QString sign = ui->comboBox_2->currentText();
            QVector <QString> filters,le;
            filters.push_back(" Название_Студии LIKE '%" + name + "%' ");
            filters.push_back(" Цена " + sign + price);
            filters.push_back(" Площадь " + sign_ploshad + size);
            le.push_back(name);
            le.push_back(price);
            le.push_back(size);
            for (int i=0;i!=le.size();i++)
            {
                if (le[i] == "")
                    continue;
                else
                {
                    query += " AND " + filters[i];
                }
            }
        }
        update_table(query);
        qDebug() << query;
    }

}

void Table::order()
{
    table_query += "ORDER BY Название";
    update_table(table_query);
}

void Table::update_table(QString qry)
{
    model = new QSqlTableModel();
    model->setQuery(qry);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}


void Table::on_pushButton_3_clicked()
{
    update_table(table_query);
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
}

