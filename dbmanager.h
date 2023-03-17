#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QtSql>
#include <QVector>
#include <QQueue>

/**
 * @file dbManager.h
 * @class dbManager
 * @brief Most functionality of  the dbManager class is to load the campus names and the
 * the distance between the selected campus and loading souvenirs name and price and lastly
 * the ability to create a data table for the shopping cart.
 */
class dbManager
{
public:
    /** \fn dbManager()
     * constructer function that create a object to associate with the database
     * connected the database with the qt creator
     * @return nothing, it just link this program to the SQL database
     */
    dbManager();

    /** \fn ~dbManager()
     *  A destructor function
     * */
   ~dbManager();

    /** \fn loadCampusNamesOnly()
     * Using the SQl query funtion, only the name of the college campuses are read in from the database into a QSqlQueryModel.
     * If a database error occurs, an error warning is printed to the console.
     * @return pointer model, the name of the campus in the from of sql database
     */
    QSqlQueryModel *loadCampusNamesOnly();

    /** \fn loadOtherCampusAndDist(QString campus)
     * Using the SQL query funtion and using the name of a single campus,
     * the names of the other campuses and their distance between them and the starding campus are read in from the database into a QSqlQueryModel.
     * If a database error occurs, an error warning is printed to the console.
     * @param string campus, the selected campus name
     * @return pointer model, the list of other campus name with the distenct to the selected campus in the from of sql database
     */
    QSqlQueryModel *loadOtherCampusAndDist(QString campus);

    /** \fn loadRemainingCampusNamesOnly(QVector<QString> campuses)
     * Using the SQL query funtion, the name of the avaliable college campuses are read in from the database into a QSqlQueryModel.
     * The function excludes reading in the campuses from the passed in vector.
     * If a database error occurs, an error warning is printed to the console.
     * @param vetctor campus, the selected campus name
     * @return pointer model, the list of other campus name to the selected campus in the from of sql database
     */
    QSqlQueryModel *loadRemainingCampusNamesOnly(QVector<QString> campuses);

    /** \fn checkCampusName(QString campus)
     * Using the SQL query funtion, this function determines if the specified college is present in the database.
     * If a database error occurs, an error warning is printed to the console.
     * @param string campus, the selected campus name
     * @return true or falst, to see if the name is in the list.
     */
    bool checkCampusName(QString campus);

    /** \fn GetDistBtwn(QString start, QString end)
     * Using the SQL query funtion, the distance between the 2 specified campuses.
     * If a database error occurs, an error warning is printed to the console.
     * @param string start, string end, the distenct between the start campuses and end campuses
     * @return double distenct, the distenct between 2 campuses
     */
    double GetDistBtwn(QString start, QString end);

    /** \fn loadCampusSouvenirs(QString campus)
     * Using the SQL query funtion, the souvenirs for a specified campus are read in from the database into a QSqlQueryModel.
     * If a database error occurs, an error warning is printed to the console.
     * @param string campus, the selected campus name
     * @return pointer model, the souvenirs of the selected campus
     */
    QSqlQueryModel *loadCampusSouvenirs(QString campus);

    /** \fn loadSouvCart(QString sQry)
     * Using the SQL query funtion, the selected sovenirs are read in from the database into a QSqlQueryModel.
     * The query is an accumulator query that contains all the souvenirs the user has selected to add to an update quey using SQL code "UNION".
     * If a database error occurs, an error warning is printed to the console.
     * @param string sqry, accumulator query that contains all the souvenirs the user has selected
     * @return pointer model, the souvenirs the user has selected add
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
     * @param string campus, string souv, int quantity, The name of the campus with the souvenirs name and the quantity the student has added
     * @return nothing, it just updated the quantity of the souvenirs item the student has add
     */
    void updateCartQuantity(QString campus, QString souv, int quantity);

    /**
     * @brief m_database
     * A public database variable for access all the dbmanager functions
     */
    QSqlDatabase m_database;

private:
};

#endif // DBMANAGER_H
