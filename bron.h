#ifndef BRON_H
#define BRON_H
#include <QToolButton>
#include <QDialog>
#include "sqldb.h"
#include <QListWidget>
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
    bool verif_bron(QDate date,QTime time_start, QTime time_end, QString id_stud);

signals:
    void showMain();

private slots:
    void on_pushButton_clicked();
    void updateCal();
    void on_pushButton_2_clicked();
    void update_oborud();
    void raschet();
    void on_comboBox_2_currentTextChanged(const QString &arg1);
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
};

#endif // BRON_H
