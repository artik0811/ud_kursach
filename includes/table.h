#ifndef TABLE_H
#define TABLE_H
#include <QValidator>
#include <QDialog>
#include "sqldb.h"

namespace Ui {
class Table;
}

class Table : public QDialog
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    void sett(SqlDB db,const QString t,const QString q);
    ~Table();

signals:
    void showMain();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void order();
    void on_pushButton_3_clicked();

private:
    Ui::Table *ui;
    bool flag_studia = false;
    bool flag_sotr = false;
    void update_table(QString qry);
    QSqlTableModel *model;
    QString table_name;
    QString table_query;
    QRegularExpressionValidator price;
    QRegularExpressionValidator size;
};

#endif // TABLE_H
