#ifndef BRON_H
#define BRON_H
#include <QToolButton>
#include <QDialog>
#include "sqldb.h"
namespace Ui {
class bron;
}

class bron : public QDialog
{
    Q_OBJECT

public:
    explicit bron(QWidget *parent = nullptr);
    ~bron();

private:
    Ui::bron *ui;
    QDateTime  *d;
    bool isbisSextus(int x);
    QToolButton* func(int i);

signals:
    void showMain();

private slots:
    void on_pushButton_clicked();
    void updateCal();
};

#endif // BRON_H
