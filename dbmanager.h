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

    /** \fn checkCampusName(QString campus)
     * Using the "select XXX from" query funtion, this function determines if the specified college is present in the database.
     * If a database error occurs, an error warning is printed to the console.
     * @param QString, campus
     * @return bool
     */
    bool checkCampusName(QString campus);

    /** \fn GetDistBtwn(QString start, QString end)
     * Using the "select XXX from" query funtion, the distance between the 2 specified campuses.
     * If a database error occurs, an error warning is printed to the console.
     * @param QString, start
     * @param QString, end
     * @return double
     */
    double GetDistBtwn(QString start, QString end);


private:
   QSqlDatabase m_database;
};

#endif // DBMANAGER_H
