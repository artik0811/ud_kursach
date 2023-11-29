#include "bron.h"
#include "qsqlerror.h"
#include "ui_bron.h"
#include <iostream>

bron::bron(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bron)
{
    ui->setupUi(this);
    d = new QDateTime(QDateTime::currentDateTime());
    ui->dateEdit->setDateTime(*d);
    std::vector<QToolButton> bt;
    for(int i=0;i<24;i++)
        func(i)->setStyleSheet("background-color: green");

    QSqlQuery query;
    query.exec("SELECT Название_Студии FROM Студия");
    while(query.next())
        ui->comboBox->addItem(query.value(0).toString()); // Вытягиваем список студий в comboBox
    query.exec("SELECT Название FROM Доп_Оборудование");
    ui->comboBox_2->addItem("---");
    while(query.next())
        ui->comboBox_2->addItem(query.value(0).toString()); // Вытягиваем список оборудования в comboBox
    connect(ui->comboBox,&QComboBox::currentTextChanged,this,&bron::updateCal);
    connect(ui->dateEdit,&QDateEdit::userDateChanged,this,&bron::updateCal);
    connect(ui->comboBox_2,&QComboBox::currentTextChanged,this,&bron::update_oborud);
    connect(ui->timeEdit,&QTimeEdit::userTimeChanged,this,&bron::raschet);
    connect(ui->timeEdit_2,&QTimeEdit::userTimeChanged,this,&bron::raschet);
    connect(ui->comboBox_2,&QComboBox::currentTextChanged,this,&bron::raschet);
    connect(ui->comboBox,&QComboBox::currentTextChanged,this,&bron::raschet);
    updateCal();
    QDate date = QDate::currentDate();
    ui->label_34->setText("0");
}

QToolButton* bron::func(int i)
{
    switch(i)
    {
    case 0: return this->ui->toolButton_24;
    case 1: return this->ui->toolButton;
    case 2: return this->ui->toolButton_2;
    case 3: return this->ui->toolButton_3;
    case 4: return this->ui->toolButton_4;
    case 5: return this->ui->toolButton_5;
    case 6: return this->ui->toolButton_6;
    case 7: return this->ui->toolButton_7;
    case 8: return this->ui->toolButton_8;
    case 9: return this->ui->toolButton_9;
    case 10: return this->ui->toolButton_10;
    case 11: return this->ui->toolButton_11;
    case 12: return this->ui->toolButton_12;
    case 13: return this->ui->toolButton_13;
    case 14: return this->ui->toolButton_14;
    case 15: return this->ui->toolButton_15;
    case 16: return this->ui->toolButton_16;
    case 17: return this->ui->toolButton_17;
    case 18: return this->ui->toolButton_18;
    case 19: return this->ui->toolButton_19;
    case 20: return this->ui->toolButton_20;
    case 21: return this->ui->toolButton_21;
    case 22: return this->ui->toolButton_22;
    case 23: return this->ui->toolButton_23;
    }
}

bool bron::verif_bron(QDate date, QTime time_start, QTime time_end, QString id_stud) //проверка времени и даты броинрования(должны быть не раньше нынешнего времени)
{

    if(date < QDate::currentDate() || time_start > time_end || time_start == time_end)
        return false;
    QSqlQuery query,q;
    query.exec("SELECT * FROM Бронь WHERE EXISTS (SELECT * FROM Бронь WHERE Дата = '" + date.toString("yyyy-MM-dd") +
               "' AND Время_Начала = '" + time_start.toString() +
               "' AND Время_Конца = '" + time_end.toString() + "')");
    q.exec("SELECT * FROM Бронь WHERE  Номер_Студии = " + id_stud + " AND ('" + time_start.addSecs(1).toString() + "' BETWEEN Время_Начала AND Время_Конца OR '" +
                                                                                 time_end.addSecs(-1).toString() + "' BETWEEN Время_Начала AND Время_Конца) AND Дата = '" + date.toString("yyyy-MM-dd") + "'");
    if (query.next() || q.next())
        return false;
    else
        return true;

}

bron::~bron()
{
    delete ui;
}

void bron::updateCal() //перерисовка графики
{
    QTime start,end;
    bool flag = false;
    QDateEdit *dt = ui->dateEdit;
    QString studio = ui->comboBox->currentText();
    QSqlQuery q;
    if(!q.next())
        for (int i=0;i<24;i++)
        {
            func(i)->setStyleSheet("background-color: green");
        }
    q.exec("SELECT Время_Начала, Время_Конца FROM Бронь WHERE Номер_Студии = (SELECT Номер_Студии FROM Студия WHERE Название_Студии = '" + studio + "') AND Дата = '" + dt->date().toString("yyyy-MM-dd") + "'");
    while(q.next())
    {
        start = q.value(0).toTime();
        end = q.value(1).toTime();

        for(int i=0;i<24;i++)
        {
            if (start.toString("hh").toInt()==i)
                flag = true;
            if(end.toString("hh").toInt()==i)
                flag = false;
            if(flag)
                func(i)->setStyleSheet("background-color: red");
        }
    }
    //информация о студии
    QString s;
    s = ui->comboBox->currentText();
    q.exec("SELECT Цена,Площадь,Адрес FROM Студия WHERE Название_Студии = '" + s +  "'");
    while(q.next())
    {
        ui->label_33->setText(q.value(0).toString());
        ui->ploshad_label->setText(q.value(1).toString());
        ui->address_label->setText(q.value(2).toString());
    }

}

void bron::on_pushButton_clicked()
{
    this->close();
    emit showMain();
}

void bron::on_pushButton_2_clicked()
{
    QSqlQuery query;
    QTime start,end;
    QDate date = ui->dateEdit->date();
    start = ui->timeEdit->time();
    end = ui->timeEdit_2->time();
    QString status = "Не Завершен";
    QString numobr;
    QString id_stud;
    if(ui->comboBox_2->currentText()!="---") // если выбрано оборудование
    {
        query.exec("SELECT Код_Оборудования FROM Доп_Оборудование WHERE Название = '" + ui->comboBox_2->currentText() + "'");
        while(query.next())
            numobr = query.value(0).toString();
    }
    else numobr = "0";
    query.exec("SELECT Номер_Студии FROM Студия WHERE Название_Студии = '" + ui->comboBox->currentText() + "'");
    while(query.next())
        id_stud = query.value(0).toString();
    if(verif_bron(date,start,end,id_stud))
    {
        query.exec("EXEC addbron " + numobr + "," + QString::fromStdString(std::to_string(SqlDB::id)) + ",'" + start.toString() + "','" +
end.toString() + "'," + id_stud + ",'Не Завершен','" + date.toString("yyyy-MM-dd") +"'");
        ui->label_39->setText("Успешно");
    }
    else
    {
        ui->label_39->setText("Ошибка! Введите корректную дату или время");
    }
    updateCal();
}

void bron::update_oborud()//информация об оборудовании
{
    QSqlQuery q;
    QString s;
    if(ui->comboBox_2->currentText()!="---")
    {
        s = ui->comboBox_2->currentText();
        q.exec("SELECT Стоимость FROM Доп_Оборудование WHERE Название = '" + s + "'");
        while(q.next())
            ui->label_34->setText(q.value(0).toString());
    }
}

void bron::raschet() //предварительный расчет
{
    int start,end,count_hours;
    start = ui->timeEdit->time().toString("hh").toInt();
    end = ui->timeEdit_2->time().toString("hh").toInt();
    count_hours = end-start;

    int stud_price,oborud_price;
    stud_price = ui->label_33->text().toInt();
    oborud_price = ui->label_34->text().toInt();

    int stud_itog,obor_itog;
    stud_itog = count_hours*stud_price;
    obor_itog = count_hours*oborud_price;
    std::string price;
    price = std::to_string(stud_itog);
    ui->sumstud_label->setText("Студия: " +QString::fromStdString(price) + " р.");
    price = std::to_string(obor_itog);
    ui->sumobor_label->setText("Оборудование: " +QString::fromStdString(price) + " р.");
    ui->sumitog_label->setText("Итого: " + QString::fromStdString(std::to_string(obor_itog+stud_itog)));
}

