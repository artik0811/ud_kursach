#ifndef REGISTRATION_H
#define REGISTRATION_H
#include "sqldb.h"
#include <QDialog>
namespace Ui {
class registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();
    void extracted();
    void addMember();

private:
    Ui::registration *ui;

signals:
    void showAuth();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // REGISTRATION_H
