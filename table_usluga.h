#ifndef TABLE_USLUGA_H
#define TABLE_USLUGA_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QValidator>
#include <QMessageBox>
#include "sqldb.h"
namespace Ui {
class table_usluga;
}

class table_usluga : public QDialog
{
    Q_OBJECT

public:
    explicit table_usluga(QWidget *parent = nullptr);
    ~table_usluga();

signals:
    void showMain();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::table_usluga *ui;
    QSqlTableModel *model;
    void update_table(QString qry);
    void reset_table();
    QRegularExpressionValidator price_valid;
    QRegularExpressionValidator id_valid;

};

#endif // TABLE_USLUGA_H
