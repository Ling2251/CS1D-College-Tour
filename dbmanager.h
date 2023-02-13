#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QtSql>
#include <QDebug>
#include<QFileInfo>

class dbManager
{
public:
    dbManager();
   ~dbManager();

   QSqlDatabase m_database;


   bool openconnect()
   {
       QSqlDatabase m_database = QSqlDatabase::addDatabase("QSQLITE");
       m_database.setDatabaseName("C:/Users/78418/CS1D-College-Tour/collegelist.db");

       if(m_database.open())
       {
           qDebug() << "Database: connection ok";
           return true;
       }
       else
       {
          qDebug() << "Error: DBManager connection with database failed";
          return false;
       }

   }

private:
};

#endif // DBMANAGER_H
