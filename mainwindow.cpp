/**********************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinterface.h"
#include "maintenance.h"
#include"dbmanager.h"
/**********************************************************/


/**********************************************************
*
* mainWindow
*_________________________________________________________
*This page will be the welcome page and will offer users
*the choice between accessing maintenance or starting the
*program.
*_________________________________________________________
***********************************************************/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton->setText("Admin Page");

    QSqlDatabase m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("../CS1D-College-Tour/collegelist.db");

    if(!m_database.open())
    {
        qDebug() << "Error: DBManager connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    adminPage = new adminpage(this);
    adminPage->show();
//    adminpage adminPage;
//    adminPage.setModal(true);
//    adminPage.exec();
// This button when pressed will send the user to a page that will send them to the user interface
void MainWindow::on_startCollegeTour_clicked()
{
    userInterface userinterface;
    userinterface.setModal(true);
    userinterface.exec();
}


void MainWindow::on_Maintenance_clicked()
{
    maintenance maintenance;
    maintenance.setModal(true);
    maintenance.exec();
}
