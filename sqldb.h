#ifndef SQLDB_H
#define SQLDB_H
#include "conf.h"

class SqlDB: public QSqlDatabase
{
public:
    SqlDB();
    ~SqlDB();
    QSqlDatabase server;
    QSqlQuery *query;
    QSqlTableModel *model;
    SqlDB get(){return *this;};
private:

};

#endif // SQLDB_H
