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
 * loadCampusNamesOnly()
 * Using the "select XXX from" query funtion, the name of the college campuses are read in from the database into a QSqlQueryModel.
 * If a database error occurs, an error warning is printed to the console.
 * IN: no formal parameters
 * OUT: QSqlQueryModel (pointer)
 */
QSqlQueryModel* dbManager::loadCampusNamesOnly()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "select stardingCollege as \"Campuses\" from collegelist group by stardingCollege;";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading Campuses\n";
    }

    model->setQuery(qry);
    return model;
}


/*
 * loadOtherCampusAndDist(QString campus)
 * Using the "select XXX from" query funtion and using the name of a single campus,
 * the names of the other campuses and their distance between them and the original campus are read in from the database into a QSqlQueryModel.
 * If a database error occurs, an error warning is printed to the console.
 * IN: no formal parameters
 * OUT: QSqlQueryModel (pointer)
 */
QSqlQueryModel* dbManager::loadOtherCampusAndDist(QString campus)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "SELECT endingCollege as 'Campuses', distance as 'Distance(mi)' FROM collegelist WHERE stardingCollege='" + campus + "';";
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading Campuses\n";
    }

    model->setQuery(qry);
    return model;
}


/*
 * checkCampusName(QString campus)
 * Using the "select XXX from" query funtion, this function determines if the specified college is present in the database.
 * If a database error occurs, an error warning is printed to the console.
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

/*
 * loadCampusSouvenirs(QString campus)
 * Using the "select XXX from" query funtion, the souvenirs for a specified campus are read in from the database into a QSqlQueryModel.
 * If a database error occurs, an error warning is printed to the console.
 */
QSqlQueryModel* dbManager::loadCampusSouvenirs(QString campus)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString sQry = "select souvenirsName as 'Souvenirs', cost as 'Cost($)' from souvenirs where collegeName = '" +campus+ "';";
    qDebug() << sQry;
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading Campuses\n";
    }

    model->setQuery(qry);
    return model;
}

/*
 * loadSouvCart(QString sQry)
 * Using the "select XXX from" query funtion, the selected sovenirs are read in from the database into a QSqlQueryModel.
 * The query is an accumulator query that contains all the souvenirs the user has selected to add to an update quey using SQL code "UNION".
 * If a database error occurs, an error warning is printed to the console.
 */
QSqlQueryModel* dbManager::loadSouvCart(QString sQry)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare(sQry);

    if(!qry.exec())
    {
        qDebug() << "\nError Loading Souvenirs\n";
    }

    model->setQuery(qry);
    return model;
}

/*
 * createCart()
 * Creates a temporary table called cart in the SQL Database, and alters the table by adding a column called quantity for the quanity purchased.
 */
void dbManager::createCart()
{
    //cartQry - temporary table
    QSqlQuery cartQry;
    cartQry.prepare("create table Cart as SELECT * from souvenirs;");

    if(!cartQry.exec())
    {
        qDebug() << "\nError Creating Cart\n";
    }
    cartQry.prepare("ALTER table Cart add quantity real default 0;");
    if(!cartQry.exec())
    {
        qDebug() << "\nError Creating Quanitity Column\n";
    }
}

/*
 * deleteCart()
 * This deletes the cart table in the SQL Database when the user has completed their shopping trip.
 */
void dbManager::deleteCart()
{
    //cartQry - temporary table
    QSqlQuery cartQry;
    cartQry.prepare("drop table Cart;");

    if(!cartQry.exec())
    {
        qDebug() << "\nError dropping Cart\n";
    }
}

/*
 * updateCartQuantity(QString campus, QString souv, int quantity)
 * This function updates the changes of quantity to the cart table in the SQL Database.
 */
void dbManager::updateCartQuantity(QString campus, QString souv, int quant)
{
    //Update quantity
    QSqlQuery updateQry;
    QString uQry = "UPDATE Cart SET quantity = quantity+" +QString::number(quant)+ " WHERE collegeName = '" +campus+ "' and souvenirsName = '" +souv+ "';";
    updateQry.prepare(uQry);

    if(!updateQry.exec())
    {
        qDebug() << "\nError updating Cart\n";
    }
}
