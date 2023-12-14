#ifndef TABLE_BRON_OBOR_H
#define TABLE_BRON_OBOR_H

#include <QDialog>
#include <QMessageBox>
#include "sqldb.h"
#include <QValidator>
namespace Ui {
class table_bron_obor;
}

class table_bron_obor : public QDialog
{
    Q_OBJECT

public:
    explicit table_bron_obor(QWidget *parent = nullptr);
    ~table_bron_obor();

signals:
    void showMain();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_find_clicked();

private:
    Ui::table_bron_obor *ui;
    QSqlTableModel *model;
    void update_table(QString qry);
    void reset_table();
};

#endif // TABLE_BRON_OBOR_H
