#include "table_brron.h"
#include "ui_table_brron.h"

table_brron::table_brron(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table_brron)
{
    ui->setupUi(this);
    QSqlQuery query("select bron.Номер_Брони,client.ФИО,Время_Начала,Время_Конца, studia.Название_Студии as [Студия], Статус, Дата "
                    "from Бронь as bron "
                    "inner join Клиент as client on bron.Код_Клиента = client.Код_Клиента "
                    "inner join Студия as studia on bron.Номер_Студии = studia.Номер_Студии ");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
    ui->dateEdit->setDate(QDate::currentDate());
    ui->checkBox_actualBroni->setCheckState(Qt::Checked);
    query.exec("SELECT Название_Студии FROM Студия WHERE Название_Студии NOT LIKE '%(удалено)%'");
    while(query.next())
    {
        ui->comboBox_studia->addItem(query.value(0).toString());
    }
}

table_brron::~table_brron()
{
    delete ui;
}

void table_brron::on_pushButton_back_clicked()
{
    emit showMain();
    this->close();
}


void table_brron::on_checkBox_actualBroni_stateChanged(int arg1)
{
    check_actual_broni = !check_actual_broni;
    QSqlQuery query;
    if(!check_actual_broni)
        query.exec("select bron.Номер_Брони,client.ФИО,Время_Начала,Время_Конца, studia.Название_Студии as [Студия], Статус, Дата "
                    "from Бронь as bron "
                    "inner join Клиент as client on bron.Код_Клиента = client.Код_Клиента "
                    "inner join Студия as studia on bron.Номер_Студии = studia.Номер_Студии "
                    "WHERE Дата > SYSDATETIME()");
    else
        query.exec("select bron.Номер_Брони,client.ФИО,Время_Начала,Время_Конца, studia.Название_Студии as [Студия], Статус, Дата "
                    "from Бронь as bron "
                    "inner join Клиент as client on bron.Код_Клиента = client.Код_Клиента "
                    "inner join Студия as studia on bron.Номер_Студии = studia.Номер_Студии ");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}


void table_brron::on_pushButton_clicked()
{
    table_brbr = new table_bron_obor();
    table_brbr->show();
}


void table_brron::on_pushButton_add_clicked()
{
    bro = new bron();
    bro->show();
}


void table_brron::on_pushButton_find_clicked()
{
    QString id = ui->lineEdit_id_bron->text();
    QString fio_client = ui->lineEdit_fio->text();
    QString date_start = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString date_end = ui->dateEdit_2->date().toString("yyyy-MM-dd");
    QString studia = ui->comboBox_studia->currentText();
    QString status = ui->comboBox_status->currentText();
    bool flag = false;
    QString query;
    if(!check_actual_broni)
        query = ("select bron.Номер_Брони,client.ФИО,Время_Начала,Время_Конца, studia.Название_Студии as [Студия], Статус, Дата "
                   "from Бронь as bron "
                   "inner join Клиент as client on bron.Код_Клиента = client.Код_Клиента "
                   "inner join Студия as studia on bron.Номер_Студии = studia.Номер_Студии "
                   "WHERE Дата > SYSDATETIME() AND ");
    else
        query = ("select bron.Номер_Брони,client.ФИО,Время_Начала,Время_Конца, studia.Название_Студии as [Студия], Статус, Дата "
                   "from Бронь as bron "
                   "inner join Клиент as client on bron.Код_Клиента = client.Код_Клиента "
                   "inner join Студия as studia on bron.Номер_Студии = studia.Номер_Студии WHERE ");
    QVector <QString> filters,le;
    filters.push_back(" bron.Номер_Брони = " + id);
    filters.push_back(" client.ФИО like '%" + fio_client + "%'");
    le.push_back(id);
    le.push_back(fio_client);
    if(ui->checkBox->isChecked())
    {
        filters.push_back(" Дата BETWEEN '" + date_start + "' AND '" + date_end + "'");
        le.push_back(date_start);
    }
    if(studia != "---")
    {
        filters.push_back(" studia.Название_Студии = '" + studia + "'");
        le.push_back(studia);
    }
    if(status != "---")
    {
        filters.push_back(" bron.Статус = '" + status + "'");
        le.push_back(status);
    }

    int k=0;
    for(int i=0;i!=filters.size();i++)
    {
        if(le[i]== "")
            continue;
        else
        {
            flag = true;
            k++;
            if(k>1)
                query += " AND " + filters[i];
            else
                query += filters[i];
        }
    }
    if(!flag)
    {
        QMessageBox::warning(this,"Ошибка","Заполните хотя бы 1 фильтр!");
        return;
    }
    update_table(query);
}

void table_brron::update_table(QString qry)
{
    model =  new QSqlTableModel();
    qDebug() << qry;
    model->setQuery(qry);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
    ui->dateEdit->setDate(QDate::currentDate());
}

void table_brron::reset_table()
{
    QSqlQuery query;
    if(!check_actual_broni)
        query.exec("select bron.Номер_Брони,client.ФИО,Время_Начала,Время_Конца, studia.Название_Студии as [Студия], Статус, Дата "
                   "from Бронь as bron "
                   "inner join Клиент as client on bron.Код_Клиента = client.Код_Клиента "
                   "inner join Студия as studia on bron.Номер_Студии = studia.Номер_Студии "
                   "WHERE Дата > SYSDATETIME() ");
    else
        query.exec("select bron.Номер_Брони,client.ФИО,Время_Начала,Время_Конца, studia.Название_Студии as [Студия], Статус, Дата "
                   "from Бронь as bron "
                   "inner join Клиент as client on bron.Код_Клиента = client.Код_Клиента "
                   "inner join Студия as studia on bron.Номер_Студии = studia.Номер_Студии ");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}


void table_brron::on_pushButton_reset_clicked()
{
    reset_table();
}


void table_brron::on_pushButton_change_clicked()
{
    QString id = ui->lineEdit_id_bron->text();
    QSqlQuery q("SELECT Статус FROM Бронь WHERE Номер_Брони = " + id);
    q.first();
    if(q.value(0).toString() == "Не Завершен")
    {
        QString status = ui->comboBox_status->currentText();
        if(status == "Завершен" || status == "Отменено")
        {
            q.exec("UPDATE Бронь SET Статус = '" + status + "' WHERE Номер_Брони = " + id);
        }
    }
    else
        QMessageBox::warning(this,"Ошибка","Изменить статус можно только с 'Не Завершен' на 'Завершен' или 'Отменено'!");
    reset_table();
}

