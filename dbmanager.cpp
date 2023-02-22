#include "dbmanager.h"

dbManager::dbManager()
{
    QSqlDatabase m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("../collegelist.db");

    if(m_database.open())
    {
        qDebug() << "Database: connection ok";
    }
    else
    {
       qDebug() << "Error: DBManager connection with database failed";
    }
}

dbManager::~dbManager()
{

}


/*
 * checkCampusName(QString campus)
 * Using the "select XXX from" query funtion, this function determines if the specified college is present in the database.
 * If a database error occurs, an error warning is printed to the console.
 * IN: QString, campus
 * OUT: bool
 */
bool dbManager::checkCampusName(QString campus)
{
    bool execute = false;
    QSqlQuery qry;
    qry.prepare("SELECT * from collegeList where stardingCollege = '" +campus+ "'");

    if(qry.exec())
    {
        execute = qry.next();
    }
    return execute;
}


/*
 * GetDistBtwn(QString start, QString end)
 * Using the "select XXX from" query funtion, the distance between the 2 specified campuses.
 * If a database error occurs, an error warning is printed to the console.
 * IN: QString, start
 * IN: QString, end
 * OUT: double
 */
double dbManager::GetDistBtwn(QString start, QString end)
{
    double distBtwn = 0;
    QString sQry = "select distance from collegeList where stardingCollege = '" +start+ "' and endingCollege = '" +end+ "';";

    QSqlQuery qry;
    qry.prepare(sQry);
    qry.exec();

    if(qry.next())
    {
        distBtwn = qry.value(0).toDouble();
    }

    return distBtwn;
}
