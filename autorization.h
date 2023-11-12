#ifndef AUTORIZATION_H
#define AUTORIZATION_H

#include <QDialog>

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
    void on_pushButton_clicked();
    std::map<QString,QString> logins;

private:
    Ui::Autorization *ui;
};

#endif // AUTORIZATION_H
