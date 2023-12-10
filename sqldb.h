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
    inline static long long id;
    inline static QString role;
};

#endif // SQLDB_H
