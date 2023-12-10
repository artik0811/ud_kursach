#ifndef TABLE_SOTRUDNIK_H
#define TABLE_SOTRUDNIK_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QValidator>
#include <QMessageBox>
#include <QValidator>
namespace Ui {
class table_sotrudnik;
}

class table_sotrudnik : public QDialog
{
    Q_OBJECT

public:
    explicit table_sotrudnik(QWidget *parent = nullptr);
    ~table_sotrudnik();

signals:
    void showMain();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::table_sotrudnik *ui;
    QSqlTableModel *model;
    void update_table(QString qry);
    void reset_table();
    QRegularExpressionValidator phone_valid;
    QRegularExpressionValidator id_valid;
    void reset_lineedits();
    bool isHaveMember(QString phone);
};

#endif // TABLE_SOTRUDNIK_H
