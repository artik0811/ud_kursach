#include "table_zakaz.h"
#include "ui_table_zakaz.h"

table_zakaz::table_zakaz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table_zakaz),
    price_valid(QRegularExpression("^\\d{7}$")),
    id_valid(QRegularExpression("^\\d{7}$")),
    count_valid(QRegularExpression("^\\d{7}$"))
{
    ui->setupUi(this);
    ui->toolButton->setToolTip("Рассчитать сумму");
    ui->lineEdit_count->setValidator(&count_valid);
    ui->lineEdit_idzakaz->setValidator(&id_valid);
    ui->lineEdit_sum_price->setValidator(&price_valid);
    QSqlQuery query;
    query.exec("SELECT Номер_Заказа, c.ФИО as [ФИО клиента], u.Название_Услуги as [Услуга], z.Количество,z.Общая_Стоимость,z.Ссылка,z.Комментарии, e.ФИО as [ФИО сотрудника],s.Название_Студии as [Студия],z.Дата_Выполнения"
                      " FROM Заказ as z"
                      " inner join Клиент as c on z.Код_Клиента = c.Код_Клиента"
                      " inner join Сотрудник as e on z.Сотрудник = e.Код_Сотрудника"
                      " inner join Студия as s on z.Номер_Студии = s.Номер_Студии"
                      " inner join Услуга as u on z.Код_Услуги = u.Код_Услуги");
    model =  new QSqlTableModel();
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
    ui->dateEdit_last->setVisible(false);
    ui->label->setVisible(false);
    ui->label_8->setText("Дата");

    QSqlQuery sotr,stud,client,usluga;
    sotr.exec("SELECT ФИО FROM Сотрудник WHERE ФИО NOT LIKE '%(удалено)%' AND (Должность = 'Менеджер' OR Должность = 'Директор')");
    qDebug() << sotr.lastError();
    stud.exec("SELECT Название_Студии FROM Студия WHERE Название_Студии NOT LIKE '%(удалено)%'");
    client.exec("SELECT ФИО FROM Клиент WHERE ФИО NOT LIKE '%(удалено)%'");
    usluga.exec("SELECT Название_Услуги FROM Услуга WHERE Название_Услуги NOT LIKE '%(удалено)%'");
    ui->comboBox_sotr->addItem("---");
    ui->comboBox_studia->addItem("---");
    ui->comboBox_client->addItem("---");
    ui->comboBox_uslug->addItem("---");
    while(sotr.next())
        ui->comboBox_sotr->addItem(sotr.value(0).toString());
    while(stud.next())
        ui->comboBox_studia->addItem(stud.value(0).toString());
    while(client.next())
        ui->comboBox_client->addItem(client.value(0).toString());
    while(usluga.next())
        ui->comboBox_uslug->addItem(usluga.value(0).toString());
    ui->dateEdit_first->setDate(QDate::currentDate());
    ui->dateEdit_last->setDate(QDate::currentDate());
}

table_zakaz::~table_zakaz()
{
    delete ui;
}

void table_zakaz::on_pushButton_clicked()
{
    emit showMain();
    this->close();
}

void table_zakaz::update_table(QString qry)
{
    model =  new QSqlTableModel();
    model->setQuery(qry);
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());

}

void table_zakaz::reset_table()
{
    model =  new QSqlTableModel();
    model->setQuery("SELECT Номер_Заказа, c.ФИО as [ФИО клиента], u.Название_Услуги as [Услуга], z.Количество,z.Общая_Стоимость,z.Ссылка,z.Комментарии, e.ФИО as [ФИО сотрудника],s.Название_Студии as [Студия],z.Дата_Выполнения"
                           " FROM Заказ as z"
                           " inner join Клиент as c on z.Код_Клиента = c.Код_Клиента"
                           " inner join Сотрудник as e on z.Сотрудник = e.Код_Сотрудника"
                           " inner join Студия as s on z.Номер_Студии = s.Номер_Студии"
                           " inner join Услуга as u on z.Код_Услуги = u.Код_Услуги");
    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
}

void table_zakaz::on_pushButton_reset_clicked()
{
    reset_table();
    ui->lineEdit_comment->setText("");
    ui->lineEdit_count->setText("");
    ui->lineEdit_idzakaz->setText("");
    ui->lineEdit_link->setText("");
    ui->lineEdit_sum_price->setText("");
    ui->comboBox_client->setCurrentIndex(0);
    ui->comboBox_sotr->setCurrentIndex(0);
    ui->comboBox_studia->setCurrentIndex(0);
    ui->comboBox_uslug->setCurrentIndex(0);
}


void table_zakaz::on_pushButton_find_clicked() // поиск
{
    QString zakaz = ui->lineEdit_idzakaz->text();
    QString client = ui->comboBox_client->currentText();
    QString sotr = ui->comboBox_sotr->currentText();
    QString stud = ui->comboBox_studia->currentText();
    QString usluga = ui->comboBox_uslug->currentText();
    QString comment = ui->lineEdit_comment->text();
    QString count = ui->lineEdit_count->text();
    QString sum = ui->lineEdit_sum_price->text();
    QString link = ui->lineEdit_link->text();
    QString sign_sum = ui->comboBox_sum->currentText();
    QString sign_count = ui->comboBox->currentText();
    QString date_first = ui->dateEdit_first->date().toString("yyyy-MM-dd");
    QString date_last = ui->dateEdit_last->date().toString("yyyy-MM-dd");
    bool date = ui->checkBox->isChecked();
    QVector <QString> filters,le;
    QString query;
    le.push_back(zakaz);
    le.push_back(client);
    le.push_back(sotr);
    le.push_back(stud);
    le.push_back(usluga);
    le.push_back(comment);
    le.push_back(count);
    le.push_back(sum);
    le.push_back(link);
    query = ("SELECT Номер_Заказа, c.ФИО as [ФИО клиента], u.Название_Услуги as [Услуга], z.Количество,z.Общая_Стоимость,z.Ссылка,z.Комментарии, e.ФИО as [ФИО сотрудника],s.Название_Студии as [Студия],z.Дата_Выполнения"
              " FROM Заказ as z"
              " inner join Клиент as c on z.Код_Клиента = c.Код_Клиента"
              " inner join Сотрудник as e on z.Сотрудник = e.Код_Сотрудника"
              " inner join Студия as s on z.Номер_Студии = s.Номер_Студии"
              " inner join Услуга as u on z.Код_Услуги = u.Код_Услуги WHERE");
        filters.push_back(" Номер_Заказа = " + zakaz);
        filters.push_back(" c.Фио LIKE '%" + client + "%' ");
        filters.push_back(" e.Фио LIKE '%" + sotr + "%' ");
        filters.push_back(" s.Название_Студии LIKE '%" + stud + "%'");
        filters.push_back(" u.Название_Услуги LIKE '%" + usluga + "%'");
    filters.push_back(" Комментарии LIKE %'" + comment + "%'");
    filters.push_back(" Количество " + sign_count + count);
    filters.push_back(" Общая_Стоимость " + sign_sum + sum);
    filters.push_back(" Ссылка LIKE '%" + link + "%'");
    if(date)
    {
        filters.push_back(" Дата_Выполнения BETWEEN '" + date_first + "' AND '" + date_last + "' ");
        le.push_back(date_first);
    }
    int k = 0;
    bool flag = true;
    for(int i=0;i!=filters.size();i++)
    {
        if(le[i]=="" || le[i]=="---")
            continue;
        else
        {
            k++;
            flag = false;
            if(k>1)
                query += " AND " + filters[i];
            else
                query += filters[i];
        }
    }
    if(flag)
    {
        QMessageBox::warning(this,"Ошибка","Введите хотя бы 1 значение!");
    }
    else
    {
        update_table(query);
    }
}


void table_zakaz::on_pushButton_add_clicked() // добавление
{
    QString client = ui->comboBox_client->currentText();
    QString sotr = ui->comboBox_sotr->currentText();
    QString stud = ui->comboBox_studia->currentText();
    QString usluga = ui->comboBox_uslug->currentText();
    if(client == "---" || sotr == "---"  || usluga == "---")
    {
        QMessageBox::warning(this,"Ошибка","Выберите все поля из выпадающих списков!");
        return;
    }
    // ------------вытягиваем id через фио и названия
    QSqlQuery id_client_query,id_sotr_query,id_stud_query,id_usluga_query;
    id_client_query.exec("SELECT Код_Клиента FROM Клиент WHERE ФИО = '" + client + "'");
    id_sotr_query.exec("SELECT Код_Сотрудника from Сотрудник where ФИО = '" + sotr + "'");
    id_usluga_query.exec("SELECT Код_Услуги FROM Услуга WHERE Название_Услуги = '" + usluga + "'");
    id_stud_query.exec("SELECT Номер_Студии FROM Студия WHERE Название_Студии = '" + stud + "'");
    id_client_query.first();
    id_sotr_query.first();
    id_stud_query.first();
    id_usluga_query.first();
    QString id_client = id_client_query.value(0).toString();
    QString id_sotr = id_sotr_query.value(0).toString();
    QString id_stud = id_stud_query.value(0).toString();
    QString id_usluga = id_usluga_query.value(0).toString();
    // -----------------------------------------------
    QString comment = ui->lineEdit_comment->text();
    QString count = ui->lineEdit_count->text();
    QString sum = ui->lineEdit_sum_price->text();
    QString link = ui->lineEdit_link->text();
    QString date = ui->dateEdit_first->date().toString("yyyy-MM-dd");
    if(count == "" || sum == "")
    {
        QMessageBox::warning(this,"Ошибка","Поля Количество и Стоимость должны быть заполнены!");
        return;
    }
    QString query_string;
    QSqlQuery q;
    q.prepare("INSERT INTO Заказ VALUES (NEXT VALUE FOR NumOrder,?,?,?,?,?,?,?,?,?)");
    q.bindValue(0,id_client);
    q.bindValue(1,id_usluga);
    q.bindValue(2,date);
    q.bindValue(3,count);
    q.bindValue(4,sum);
    q.bindValue(7,id_sotr);
    if(link != "")
        q.bindValue(5,link);
    else
        q.bindValue(5," ");

    if(comment != "")
        q.bindValue(6,comment);
    else
        q.bindValue(6," ");

    if(stud != "---")
        q.bindValue(8,id_stud);
    else
        q.bindValue(8,"   ");

    q.exec();
    QSqlQuery query(query_string);
    reset_table();
    qDebug() << q.lastQuery() << '\n' << q.lastError() << '\n' << stud;
}


void table_zakaz::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked())
    {
        ui->dateEdit_last->setVisible(true);
        ui->label->setVisible(true);
        ui->label_8->setText("Дата           с");
    }
    else
    {
        ui->dateEdit_last->setVisible(false);
        ui->label->setVisible(false);
        ui->label_8->setText("Дата");
    }
}


void table_zakaz::on_comboBox_client_currentIndexChanged(int index)
{
    QSqlQuery query("SELECT Код_Клиента FROM Клиент WHERE ФИО = '" + ui->comboBox_client->currentText() + "'");
    query.first();
    ui->label_3->setText("ID:  " + query.value(0).toString());
}


void table_zakaz::on_comboBox_sotr_currentTextChanged(const QString &arg1)
{
    QSqlQuery query("SELECT Код_Сотрудника FROM Сотрудник WHERE ФИО = '" + ui->comboBox_sotr->currentText() + "'");
    query.first();
    ui->label_4->setText("ID:  " + query.value(0).toString());
}


void table_zakaz::on_comboBox_studia_currentTextChanged(const QString &arg1)
{
    QSqlQuery query("SELECT Номер_Студии FROM Студия WHERE Название_Студии = '" + ui->comboBox_studia->currentText() + "'");
    query.first();
    ui->label_10->setText("ID:  " + query.value(0).toString());
}


void table_zakaz::on_comboBox_uslug_currentTextChanged(const QString &arg1)
{
    QSqlQuery query("SELECT Код_Услуги FROM Услуга WHERE Название_Услуги = '" + ui->comboBox_uslug->currentText() + "'");
    query.first();
    ui->label_9->setText("ID:  " + query.value(0).toString());
}


void table_zakaz::on_toolButton_clicked()
{
    QString sum_itog;
    QString count = ui->lineEdit_count->text();
    QString price;
    QString name = ui->comboBox_uslug->currentText();
    QSqlQuery query("SELECT Стоимость FROM Услуга WHERE Название_Услуги = '" + name + "'");
    query.first();
    price = query.value(0).toString();
    sum_itog = QVariant(price.toInt() * count.toInt()).toString();
    ui->lineEdit_sum_price->setText(sum_itog);
}


void table_zakaz::on_pushButton_change_clicked()
{
    QString zakaz = ui->lineEdit_idzakaz->text();
    QString client = ui->comboBox_client->currentText();
    QString sotr = ui->comboBox_sotr->currentText();
    QString stud = ui->comboBox_studia->currentText();
    QString usluga = ui->comboBox_uslug->currentText();
    QString comment = ui->lineEdit_comment->text();
    QString count = ui->lineEdit_count->text();
    QString sum = ui->lineEdit_sum_price->text();
    QString link = ui->lineEdit_link->text();
    QString sign_sum = ui->comboBox_sum->currentText();
    QString sign_count = ui->comboBox->currentText();
    QString date_first = ui->dateEdit_first->date().toString("yyyy-MM-dd");
    QString date_last = ui->dateEdit_last->date().toString("yyyy-MM-dd");
    if(zakaz == "")
    {
        QMessageBox::warning(this,"Ошибка","Введите номер заказа!");
        return;
    }
    //------------------------------------
    QSqlQuery id_client_query,id_sotr_query,id_stud_query,id_usluga_query;
    id_client_query.exec("SELECT Код_Клиента FROM Клиент WHERE ФИО = '" + client + "'");
    id_sotr_query.exec("SELECT Код_Сотрудника from Сотрудник where ФИО = '" + sotr + "'");
    id_usluga_query.exec("SELECT Код_Услуги FROM Услуга WHERE Название_Услуги = '" + usluga + "'");
    id_stud_query.exec("SELECT Номер_Студии FROM Студия WHERE Название_Студии = '" + stud + "'");
    id_client_query.first();
    id_sotr_query.first();
    id_stud_query.first();
    id_usluga_query.first();
    QString id_client = id_client_query.value(0).toString();
    QString id_sotr = id_sotr_query.value(0).toString();
    QString id_stud = id_stud_query.value(0).toString();
    QString id_usluga = id_usluga_query.value(0).toString();
    //___________________________________-
    bool date = ui->checkBox->isChecked();
    QVector <QString> filters,le;
    QString query;
    le.push_back(id_client);
    le.push_back(id_sotr);
    le.push_back(id_stud);
    le.push_back(id_usluga);
    le.push_back(comment);
    le.push_back(count);
    le.push_back(sum);
    le.push_back(link);
    query = ("UPDATE Заказ SET ");
    filters.push_back(" Код_Клиента = " + id_client + " ");
    filters.push_back(" Сотрудник = " + id_sotr + " ");
    filters.push_back(" Номер_Студии = " + id_stud + "");
    filters.push_back(" Код_Услуги = " + id_usluga + " ");
    filters.push_back(" Комментарии = '" + comment + "' ");
    filters.push_back(" Количество  = " + count);
    filters.push_back(" Общая_Стоимость = " + sum);
    filters.push_back(" Ссылка = '" + link + "' ");
    if(date)
    {
        filters.push_back(" Дата_Выполнения = '" + date_first + "' ");
        le.push_back(date_first);
    }
    int k = 0;
    bool flag = true;
    for(int i=0;i!=filters.size();i++)
    {
        if(le[i]=="" || le[i]=="---")
            continue;
        else
        {
            k++;
            flag = false;
            if(k>1)
                query += ", " + filters[i];
            else
                query += filters[i];
        }
    }
    query += " WHERE Номер_Заказа = " + zakaz;
    if(flag)
    {
        QMessageBox::warning(this,"Ошибка","Введите хотя бы 1 значение!");
    }
    else
    {

        QSqlQuery q(query);
        qDebug() << q.lastQuery() << '\n' << q.lastError() << '\n' << id_client;
        reset_table();
    }
}

