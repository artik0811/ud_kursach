#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include "sqldb.h"
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
    void get_map(std::map<QString, QString> *gm);

private:
    Ui::registration *ui;
    std::map<QString, QString> *map;

signals:
    void showAuth();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // REGISTRATION_H
