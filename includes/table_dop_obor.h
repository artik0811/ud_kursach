#ifndef TABLE_DOP_OBOR_H
#define TABLE_DOP_OBOR_H

#include <QDialog>
#include "sqldb.h"
#include <QValidator>
#include <QMessageBox>

namespace Ui {
class table_dop_obor;
}

class table_dop_obor : public QDialog
{
    Q_OBJECT

public:
    explicit table_dop_obor(QWidget *parent = nullptr);
    ~table_dop_obor();
signals:
    void showMain();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::table_dop_obor *ui;
    QSqlTableModel *model;
    void update_table(QString qry);
    void reset_table();
    QRegularExpressionValidator id_valid;
    QRegularExpressionValidator count_valid;
};

#endif // TABLE_DOP_OBOR_H
