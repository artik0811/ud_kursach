#ifndef TABLE_ZAKAZ_H
#define TABLE_ZAKAZ_H

#include <QDialog>
#include "sqldb.h"
#include <QMessageBox>
#include <QValidator>

namespace Ui {
class table_zakaz;
}

class table_zakaz : public QDialog
{
    Q_OBJECT

public:
    explicit table_zakaz(QWidget *parent = nullptr);
    ~table_zakaz();

private slots:
    void on_pushButton_clicked();



    void on_pushButton_reset_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_add_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_comboBox_client_currentIndexChanged(int index);

    void on_comboBox_sotr_currentTextChanged(const QString &arg1);

    void on_comboBox_studia_currentTextChanged(const QString &arg1);

    void on_comboBox_uslug_currentTextChanged(const QString &arg1);

    void on_toolButton_clicked();

    void on_pushButton_change_clicked();

private:
    Ui::table_zakaz *ui;
    QSqlTableModel *model;
    void update_table(QString qry);
    void reset_table();
    QRegularExpressionValidator price_valid;
    QRegularExpressionValidator id_valid;
    QRegularExpressionValidator count_valid;

signals:
    void showMain();
};

#endif // TABLE_ZAKAZ_H
