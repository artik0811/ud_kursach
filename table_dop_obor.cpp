#include "table_dop_obor.h"
#include "ui_table_dop_obor.h"

table_dop_obor::table_dop_obor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table_dop_obor),
    id_valid(QRegularExpression("^\\d{7}$")),
    count_valid(QRegularExpression("^\\d{7}$"))
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator(&id_valid);
    ui->lineEdit_price->setValidator(&count_valid);
    QSqlQuery query("SELECT * FROM Доп_Оборудование WHERE Название NOT LIKE '%(удалено)%'");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

table_dop_obor::~table_dop_obor()
{
    delete ui;
}

void table_dop_obor::on_pushButton_back_clicked()
{
    emit showMain();
    this->close();
}

void table_dop_obor::update_table(QString qry)
{
    QSqlQuery query(qry);
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

void table_dop_obor::reset_table()
{
    QSqlQuery query("SELECT * FROM Доп_Оборудование WHERE Название NOT LIKE '%(удалено)%'");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}


void table_dop_obor::on_pushButton_find_clicked() // поиск
{
    QString name = ui->lineEdit_name->text();
    QString price = ui->lineEdit_price->text();
    QString id = ui->lineEdit_id->text();
    QString sign_price = ui->comboBox->currentText();
    QString query("SELECT * FROM Доп_Оборудование WHERE ");
    if (name == "" && price == "" && id == "")
    {
        QMessageBox::warning(this,"Ошибка","Введите хотя бы 1 значение!");
        return;
    }
    QVector <QString> filters,le;
    filters.push_back(" Название LIKE '%" + name + "%'");
    filters.push_back(" Стоимость " + sign_price + " " + price);
    filters.push_back(" Код_Оборудования = " + id);
    le.push_back(name);
    le.push_back(id);
    le.push_back(price);
    int k =0;
    for(int i=0;i!=le.size();i++)
    {
        if(le[i]=="")
            continue;
        else{
            k++;
            if(k>1)
                query += " AND " + filters[i];
            else
                query += filters[i] + " ";
        }
    }
    update_table(query);
}


void table_dop_obor::on_pushButton_reset_clicked()
{
    reset_table();
    ui->lineEdit_id->setText("");
    ui->lineEdit_name->setText("");
    ui->lineEdit_price->setText("");
}


void table_dop_obor::on_pushButton_clicked() // добавление
{
    QString name = ui->lineEdit_name->text();
    QString price = ui->lineEdit_price->text();
    QSqlQuery query;
    if(name =="" && price =="")
    {
        QMessageBox::warning(this,"Ошибка","Заполните все поля!");
        return;
    }
    query.prepare("INSERT INTO Доп_Оборудование VALUES (NEXT VALUE FOR NumOborud,?,?)");
    query.bindValue(0,name);
    query.bindValue(1,price);
    query.exec();
    reset_table();
}

void table_dop_obor::on_pushButton_change_clicked() //изменения
{
    QString name = ui->lineEdit_name->text();
    QString price = ui->lineEdit_price->text();
    QString id = ui->lineEdit_id->text();
    if(id =="")
    {
        QMessageBox::warning(this,"Ошибка","Введите ID оборудования!");
        return;
    }
    QString query("UPDATE Доп_Оборудование SET ");
    QVector <QString> filters,le;
    filters.push_back("Название = '" + name + "'");
    filters.push_back("Стоимость = " + price);
    filters.push_back("Код_Оборудования = " + id);
    le.push_back(name);
    le.push_back(id);
    le.push_back(price);
    int k =0;
    for(int i=0;i!=le.size();i++)
    {
        if(le[i]=="")
            continue;
        else
        {
            k++;
            if(k>1)
                query += ", " + filters[i];
            else
                query += filters[i] + " ";
        }
    }
    query += " WHERE Код_Оборудования = " + id;
    QSqlQuery q(query);
    reset_table();
}


void table_dop_obor::on_pushButton_delete_clicked()
{
    QString id = ui->lineEdit_id->text();
    QString name = ui->lineEdit_name->text();
    if(id =="")
    {
        QMessageBox::warning(this,"Ошибка","Введите ID оборудования!");
        return;
    }
    QSqlQuery query;
    query.exec("SELECT Название FROM Доп_Оборудование WHERE Код_Оборудования = " + id);
    while(query.next())
    {
        name = query.value(0).toString();
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Удаление записи","Вы уверены что хотите удалить запись?", QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        query.exec("INSERT INTO Журнал_удалений VALUES ('" + name + "', 'Доп_Оборудование',SYSDATETIME())");
        query.exec("UPDATE Доп_Оборудование SET Название = '" + name + "(удалено)' WHERE Код_Оборудования = " + id);
    }
    reset_table();
}

