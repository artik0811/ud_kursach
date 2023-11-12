#include "sqldb.h"
#include <iostream>
SqlDB::SqlDB()
{
    server = QSqlDatabase::addDatabase("QODBC");
    server.setDatabaseName("DRIVER={SQL Server};SERVER=localhost\\SQLEXPRESS;DATABASE=udkurs;Trusted_Connection=yes");
    if(server.open())
    {
        std::cout << "Open";
    }
    else
        std::cout << "NO";
}

SqlDB::~SqlDB()
{

}

