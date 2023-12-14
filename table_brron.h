#ifndef TABLE_BRRON_H
#define TABLE_BRRON_H

#include <QDialog>
#include "sqldb.h"
#include "table_bron_obor.h"
#include "bron.h"
#include <QValidator>
#include <QMessageBox>
namespace Ui {
class table_brron;
}

class table_brron : public QDialog
{
    Q_OBJECT

public:
    explicit table_brron(QWidget *parent = nullptr);
    ~table_brron();

signals:
    void showMain();

private slots:
    void on_pushButton_back_clicked();

    void on_checkBox_actualBroni_stateChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_change_clicked();

private:
    Ui::table_brron *ui;
    QSqlTableModel *model;
    void update_table(QString qry);
    table_bron_obor *table_brbr;
    bron *bro;
    void reset_table();
    QRegularExpressionValidator phone_valid;
    QRegularExpressionValidator mail_valid;
    QRegularExpressionValidator fio_valid;
    bool check_actual_broni = true;
};

#endif // TABLE_BRRON_H
