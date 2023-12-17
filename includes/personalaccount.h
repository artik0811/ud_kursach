#ifndef PERSONALACCOUNT_H
#define PERSONALACCOUNT_H

#include <QDialog>
#include <QValidator>
#include <QSqlError>
#include "sqldb.h"
namespace Ui {
class PersonalAccount;
}

class PersonalAccount : public QDialog
{
    Q_OBJECT

public:
    explicit PersonalAccount(QWidget *parent = nullptr);
    ~PersonalAccount();

signals:
    void showMain();

private:
    Ui::PersonalAccount *ui;
    QRegularExpressionValidator phone_valid;
    QRegularExpressionValidator mail_valid;
    QRegularExpressionValidator fio_valid;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_otmena_clicked();
};

#endif // PERSONALACCOUNT_H
