#ifndef JOURNAL_DELETE_H
#define JOURNAL_DELETE_H

#include <QDialog>
#include "sqldb.h"
namespace Ui {
class journal_delete;
}

class journal_delete : public QDialog
{
    Q_OBJECT

public:
    explicit journal_delete(QWidget *parent = nullptr);
    ~journal_delete();

private:
    Ui::journal_delete *ui;
    QSqlTableModel *model;

signals:
    void showMain();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // JOURNAL_DELETE_H
