#include "dbmanager.h"

dbManager::dbManager()
{
    QSqlDatabase m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("C:/Users/78418/CS1D-College-Tour/collegelist.db");

}

dbManager::~dbManager()
{

}
