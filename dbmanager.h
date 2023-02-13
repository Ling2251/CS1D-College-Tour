#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QtSql>
#include <QDebug>

class dbManager
{
public:
    dbManager();
   ~dbManager();

   QSqlDatabase m_database;
};

#endif // DBMANAGER_H
