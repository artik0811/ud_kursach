#include "table.h"
#include "ui_table.h"

Table::Table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
}

void Table::sett(SqlDB db,const QString t)
{
    db.query = new QSqlQuery(db.server);
    db.model = new QSqlTableModel (this,db.server);
    db.model->setTable(t);
    db.model->select();
    ui->tableView->setModel(db.model);
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
