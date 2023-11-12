#ifndef TABLE_H
#define TABLE_H

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
    void sett(SqlDB db,const QString t);
    ~Table();

signals:
    void showMain();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Table *ui;
};

#endif // TABLE_H
