#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QtSql>
#include <QVector>
#include <QQueue>

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

    /** \fn loadCampusSouvenirs(QString campus)
     * Using the "select XXX from" query funtion, the souvenirs for a specified campus are read in from the database into a QSqlQueryModel.
     * If a database error occurs, an error warning is printed to the console.
     * @param no formal parameters
     * @return QSqlQueryModel (pointer)
     */
    QSqlQueryModel *loadCampusSouvenirs(QString campus);

    /** \fn loadSouvCart(QString sQry)
     * Using the "select XXX from" query funtion, the selected sovenirs are read in from the database into a QSqlQueryModel.
     * The query is an accumulator query that contains all the souvenirs the user has selected to add to an update quey using SQL code "UNION".
     * If a database error occurs, an error warning is printed to the console.
     * @param QString, sQry
     * @return QSqlQueryModel (pointer)
     */
    QSqlQueryModel* loadSouvCart(QString sQry);

    /** \fn createCart()
     * Creates a temporary table called cart in the SQL Database, and alters the table by adding a column called quantity for the quanity purchased.
     * @param no formal parameters
     * @return nothing returned
     */
    void createCart();

    /** \fn updateCartQuantity(QString campus, QString souv, int quantity)
     * This function updates the changes of quantity to the cart table in the SQL Database.
     * @param QString, campus
     * @param QString, souv
     * @param int, quantity
     * @return nothing returned
     */
    void updateCartQuantity(QString campus, QString souv, int quantity);



private:
   QSqlDatabase m_database;
};

#endif // DBMANAGER_H
