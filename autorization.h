#ifndef AUTORIZATION_H
#define AUTORIZATION_H

#include <QDialog>
#include "mainwindow.h"
#include "registration.h"

namespace Ui {
class Autorization;
}

class Autorization : public QDialog
{
    Q_OBJECT

public:
    explicit Autorization(QWidget *parent = nullptr);
    ~Autorization();
    void auth();
    bool flag = false;

signals:
    void showMain();
    void showRegistration();

private:
    Ui::Autorization *ui;
    MainWindow *m;
    Registration *r;

private slots:
    void showPassword();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // AUTORIZATION_H
