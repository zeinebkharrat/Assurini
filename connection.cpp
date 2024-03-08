#include "connection.h"
Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A13");
    db.setUserName("mahdi");
    db.setPassword("mahdi");

if(db.open())
test=true;


return test;



}
