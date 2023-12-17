#include "table_client.h"
#include "ui_table_client.h"
#include <QMessageBox>

table_client::table_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table_client),
    phone_valid(QRegularExpression("^\\d{11}$")),
    mail_valid(QRegularExpression("^[\\w-]+@([\\w-]+\\.)+[\\w-]+$")),
    fio_valid(QRegularExpression("^[A-Za-z|А-Яа-я]{1,}\\s[A-Z|А-Я][.][A-Z|А-Я][.]$"))
{
    ui->setupUi(this);
    QSqlQuery query("SELECT * FROM Клиент WHERE Фио NOT LIKE '%(удалено)%'");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
    ui->lineEdit_fio->setValidator(&fio_valid);
    ui->lineEdit_id->setValidator(&phone_valid);
    ui->lineEdit_mail->setValidator(&mail_valid);
    ui->lineEdit_phone->setValidator(&phone_valid);
}

table_client::~table_client()
{
    delete ui;
}

void table_client::on_pushButton_back_clicked()
{
    emit showMain();
    this->close();
}


void table_client::on_pushButton_find_clicked() //поиск
{
    QString id = ui->lineEdit_id->text();
    QString fio = ui->lineEdit_fio->text();
    QString phone = ui->lineEdit_phone->text();
    QString mail = ui->lineEdit_mail->text();
    QString sex = ui->comboBox_sex->currentText();
    QString query_string = "SELECT * FROM Клиент WHERE ";
    QVector<QString> filters,le;
    bool sex_checkbox = ui->checkBox->isChecked();
    filters.push_back("Код_Клиента = " + id + " ");
    filters.push_back("ФИО LIKE '%" + fio + "%' ");
    filters.push_back("Телефон = " + phone);
    filters.push_back("Почта LIKE '%" + mail + "%' ");
    le.push_back(id);
    le.push_back(fio);
    le.push_back(phone);
    le.push_back(mail);
    if(sex_checkbox)
    {
        le.push_back(sex);
        filters.push_back("Пол = '" + sex + "' ");
    }
    int k = 0;
    bool isnull = true;
    for (int i=0;i!=le.size();i++)
    {
        if(le[i]=="")
            continue;
        else
        {
            isnull = false;
            k++;
            if(k>1)
                query_string += "AND " + filters[i];
            else
                query_string += filters[i];
        }
    }
    if(!isnull)
        update_table(query_string);
    else
        QMessageBox::warning(this,"Ошибка","Заполните хотя бы 1 поле!");
}

void table_client::update_table(QString qry)
{
    QSqlQuery query(qry);
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

void table_client::reset_table()
{
    QSqlQuery query("SELECT * FROM Клиент WHERE Фио NOT LIKE '%(удалено)%'");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}


void table_client::on_pushButton_reset_clicked()
{
    reset_table();
}


void table_client::on_pushButton_add_clicked() // добавление
{
    QString id = ui->lineEdit_id->text();
    QString fio = ui->lineEdit_fio->text();
    QString phone = ui->lineEdit_phone->text();
    QString mail = ui->lineEdit_mail->text();
    QString sex = ui->comboBox_sex->currentText();
    QSqlQuery qry ("SELECT Телефон FROM Клиент WHERE Телефон = " + phone);
    if(qry.next())
    {
        QMessageBox::warning(this,"Ошибка","Клиент с таким телефоном уже существует!");
        return;
    }
    if (fio == "" && phone == "" && mail == "" && sex == "")
        QMessageBox::warning(this,"Ошибка","Заполните все поля!");
    else
    {
        QSqlQuery query ("INSERT INTO Клиент VALUES (NEXT VALUE FOR NumClient,'" + fio + "'," + phone + ",'" + mail + "','" + sex + "')");
        reset_table();
    }
}


void table_client::on_pushButton_change_clicked() //изменение
{
    QString id = ui->lineEdit_id->text();
    QString fio = ui->lineEdit_fio->text();
    QString phone = ui->lineEdit_phone->text();
    QString mail = ui->lineEdit_mail->text();
    QString sex = ui->comboBox_sex->currentText();
    QString query_string = "UPDATE Клиент SET ";
    QVector<QString> filters,le;
    filters.push_back("ФИО = '" + fio + "' ");
    filters.push_back("Телефон = " + phone);
    filters.push_back("Почта = '" + mail + "' ");
    filters.push_back("Пол = '" + sex + "' ");
    le.push_back(fio);
    le.push_back(phone);
    le.push_back(mail);
    int k = 0;
    bool isnull = true;
    for (int i=0;i!=le.size();i++)
    {
        if(le[i]=="")
            continue;
        else
        {
            isnull = false;
            k++;
            if(k>1)
                query_string += ", " + filters[i];
            else
                query_string += filters[i];
        }
    }
    if(id != "")
    {
        if(!isnull)
        {
            query_string += " WHERE Код_Клиента = " + id;
            QSqlQuery query(query_string);
            qDebug() << query.lastError() << '\n' << query.lastQuery();
            reset_table();
        }
        else
            QMessageBox::warning(this,"Ошибка","Заполните хотя бы 1 поле!");
    }
    else
        QMessageBox::warning(this,"Ошибка","Введите ID клиента!");
}


void table_client::on_pushButton_delete_clicked()
{
    QString fio;
    QString id = ui->lineEdit_id->text();
    QSqlQuery query("SELECT Фио from Клиент where Код_Клиента = " + id);
    query.first();
    fio = query.value(0).toString();
    query.exec("INSERT INTO Журнал_удалений VALUES ('" + fio + "','Клиент',SYSDATETIME())");
    qDebug() << query.lastQuery() << '\n' << query.lastError();
    query.exec("UPDATE Клиент SET Фио = '" + fio + "(удалено)' WHERE Код_Клиента = " + id);
    reset_table();
}

