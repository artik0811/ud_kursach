#ifndef AUTORIZATION_H
#define AUTORIZATION_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Autorization;
}

class Autorization : public QDialog
{
    Q_OBJECT

public:
    explicit Autorization(QWidget *parent = nullptr);
    ~Autorization();
    bool auth();
    std::map<QString,QString> logins;

signals:
    void showMain();

private:
    Ui::Autorization *ui;
    MainWindow *m;

private slots:
    void on_pushButton_clicked();
};

#endif // AUTORIZATION_H
