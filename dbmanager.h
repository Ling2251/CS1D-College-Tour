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

    /** \fn loadCampusNamesOnly()
     * Using the "select XXX from" query funtion, the name of the college campuses are read in from the database into a QSqlQueryModel.
     * If a database error occurs, an error warning is printed to the console.
     */
    QSqlQueryModel *loadCampusNamesOnly();

    /** \fn loadOtherCampusAndDist(QString campus)
     * Using the "select XXX from" query funtion and using the name of a single campus,
     * the names of the other campuses and their distance between them and the original campus are read in from the database into a QSqlQueryModel.
     * If a database error occurs, an error warning is printed to the console.
     */
    QSqlQueryModel *loadOtherCampusAndDist(QString campus);

    /** \fn checkCampusName(QString campus)
     * Using the "select XXX from" query funtion, this function determines if the specified college is present in the database.
     * If a database error occurs, an error warning is printed to the console.
     */
    bool checkCampusName(QString campus);

    /** \fn GetDistBtwn(QString start, QString end)
     * Using the "select XXX from" query funtion, the distance between the 2 specified campuses.
     * If a database error occurs, an error warning is printed to the console.
     */
    double GetDistBtwn(QString start, QString end);

    /** \fn loadCampusSouvenirs(QString campus)
     * Using the "select XXX from" query funtion, the souvenirs for a specified campus are read in from the database into a QSqlQueryModel.
     * If a database error occurs, an error warning is printed to the console.
     */
    QSqlQueryModel *loadCampusSouvenirs(QString campus);

    /** \fn loadSouvCart(QString sQry)
     * Using the "select XXX from" query funtion, the selected sovenirs are read in from the database into a QSqlQueryModel.
     * The query is an accumulator query that contains all the souvenirs the user has selected to add to an update quey using SQL code "UNION".
     * If a database error occurs, an error warning is printed to the console.
     */
    QSqlQueryModel* loadSouvCart(QString sQry);

    /** \fn createCart()
     * Creates a temporary table called cart in the SQL Database, and alters the table by adding a column called quantity for the quanity purchased.
     */
    void createCart();

    /** \fn deleteCart()
     * This deletes the cart table in the SQL Database when the user has completed their shopping trip.
     */
    void deleteCart();

    /** \fn updateCartQuantity(QString campus, QString souv, int quantity)
     * This function updates the changes of quantity to the cart table in the SQL Database.
     */
    void updateCartQuantity(QString campus, QString souv, int quantity);

private:
   QSqlDatabase m_database;
};

#endif // DBMANAGER_H
