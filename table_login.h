#ifndef TABLE_LOGIN_H
#define TABLE_LOGIN_H

#include <QDialog>
#include "sqldb.h"
#include <QValidator>
namespace Ui {
class table_login;
}

class table_login : public QDialog
{
    Q_OBJECT

public:
    explicit table_login(QWidget *parent = nullptr);
    ~table_login();

signals:
    void showMain();


private slots:
    void on_backButton_clicked();

    void on_findButton_clicked();

    void on_pushButton_clicked();


    void on_changeButton_clicked();

private:
    Ui::table_login *ui;
    QSqlTableModel *model;
    void update_table(QString qry);
    void reset_table();
    void reset_lineedits();
    QRegularExpressionValidator phone_valid;
};

#endif // TABLE_LOGIN_H
