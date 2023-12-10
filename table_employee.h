#ifndef TABLE_EMPLOYEE_H
#define TABLE_EMPLOYEE_H

#include <QDialog>
#include "conf.h"
#include <QValidator>
namespace Ui {
class table_employee;
}

class table_employee : public QDialog
{
    Q_OBJECT

public:
    explicit table_employee(QWidget *parent = nullptr);
    ~table_employee();

private:
    Ui::table_employee *ui;
    QSqlTableModel *model;
    void update_table(QString qry);
    void reset_table();
    QRegularExpressionValidator id_valid;
    QRegularExpressionValidator ploshad_valid;
    QRegularExpressionValidator price_valid;
    int row;

signals:
    void showMain();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();
};

#endif // TABLE_EMPLOYEE_H
