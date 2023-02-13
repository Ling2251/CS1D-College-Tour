#include "dbmanager.h"

dbManager::dbManager()
{
    // Connecting to database

    QSqlDatabase m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("C:/Users/78418/CS1D-College-Tour/collegelist.db");

    /*if(!m_database.open())
    {
        ui->label->setText("Failed to open the database");
    }
    else
    {
        ui->label->setText("Connected.......");
    }*/

    if(!m_database.open())
    {
       qDebug() << "Error: DBManager connection with database failed";
    }
    else{
       qDebug() << "Database: connection ok";
    }
}
