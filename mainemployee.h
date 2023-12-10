#ifndef MAINEMPLOYEE_H
#define MAINEMPLOYEE_H

#include <QDialog>
#include "conf.h"
#include "table_employee.h"
#include "table_usluga.h"
#include "table_sotrudnik.h"
#include "journal_delete.h"
#include "table_login.h"
namespace Ui {
class mainEmployee;
}

class mainEmployee : public QDialog
{
    Q_OBJECT

public:
    explicit mainEmployee(QWidget *parent = nullptr);
    ~mainEmployee();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_5_clicked();

signals:
    void showAuth();

private:
    Ui::mainEmployee *ui;
    table_employee *table;
    table_usluga *table_usl;
    table_sotrudnik *table_sotr;
    journal_delete *journal;
    table_login *table_log;
};

#endif // MAINEMPLOYEE_H
