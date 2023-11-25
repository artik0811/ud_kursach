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
    for(int i=1;i<25;i++)
        func(i)->setStyleSheet("background-color: green");
    QSqlQuery query;
    query.exec("SELECT Название_Студии FROM Студия");
    while(query.next())
    {
        ui->comboBox->addItem(query.value(0).toString()); // Вытягиваем список студий в comboBox
    }
    connect(ui->comboBox,&QComboBox::currentTextChanged,this,&bron::updateCal);
    updateCal();
    QDate date = QDate::currentDate();
    ui->dateEdit->setMinimumDate(date);
}

QToolButton* bron::func(int i)
{
    switch(i)
    {
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
    case 24: return this->ui->toolButton_24;
    }
}

bron::~bron()
{
    delete ui;
}

void bron::updateCal()
{
    QTime start,end;
    bool flag = false;
    QDateEdit *dt = ui->dateEdit;
    QString studio = ui->comboBox->currentText();
    QSqlQuery q;
    q.exec("SELECT Время_Начала, Время_Конца FROM Бронь WHERE Номер_Студии = (SELECT Номер_Студии FROM Студия WHERE Название_Студии = '" + studio + "') AND Дата = '" + dt->date().toString("yyyy-MM-dd") + "'");
    while(q.next())
    {
        start = q.value(0).toTime();
        end = q.value(1).toTime();

        for(int i=1;i<25;i++)
        {
            if (start.toString("hh").toInt()==i)
                flag = true;
            if(end.toString("hh").toInt()==i)
                flag = false;
            if(flag)
                func(i)->setStyleSheet("background-color: red");
            else
                func(i)->setStyleSheet("background-color: green");
        }
    }
}

void bron::on_pushButton_clicked()
{
    this->close();
    emit showMain();
}
