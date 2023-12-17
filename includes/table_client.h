#ifndef TABLE_CLIENT_H
#define TABLE_CLIENT_H

#include <QDialog>
#include "sqldb.h"
#include <QValidator>

namespace Ui {
class table_client;
}

class table_client : public QDialog
{
    Q_OBJECT

public:
    explicit table_client(QWidget *parent = nullptr);
    ~table_client();

signals:
    void showMain();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::table_client *ui;
    QSqlTableModel *model;
    void update_table(QString qry);
    void reset_table();
    QRegularExpressionValidator phone_valid;
    QRegularExpressionValidator mail_valid;
    QRegularExpressionValidator fio_valid;
    void reset_lineedits();
    bool isHaveMember(QString phone);
};

#endif // TABLE_CLIENT_H
