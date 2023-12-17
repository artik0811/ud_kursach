#ifndef REGISTRATION_H
#define REGISTRATION_H
#include "sqldb.h"
#include <QDialog>
#include <QValidator>
namespace Ui {
class registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private:
    Ui::registration *ui;
    bool verif_member(QString login,QString pass,QString pass2,QString mail,QString fio,QString sex);
    QRegularExpressionValidator phone_valid;
    QRegularExpressionValidator mail_valid;
    QRegularExpressionValidator fio_valid;

signals:
    void showAuth();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // REGISTRATION_H
