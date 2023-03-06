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

    Login = new loginpage();
    connect(Login, &loginpage::firstWindow, this, &MainWindow::show);

    PlanTrip = new planTripWindow();
    connect(PlanTrip, &planTripWindow::firstWindow, this, &MainWindow::show);

    Admin = new adminpage();
    connect(Admin, &adminpage::firstWindow, this, &MainWindow::show);
    connect(Login, &loginpage::adminWindow, Admin, &adminpage::show);
    CollegeWin = new collegetripwindow();
    connect(PlanTrip, &planTripWindow::collegeWindow, CollegeWin, &collegetripwindow::show);

    Receipt = new receiptpage();
    connect(Receipt, &receiptpage::firstWindow, this, &MainWindow::show);
    connect(CollegeWin, &collegetripwindow::receiptPage, Receipt, &receiptpage::show);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startCollegeTour_clicked()
{
    userInterface userinterface;
    userinterface.setModal(true);
    userinterface.exec();
}


void MainWindow::on_Maintenance_clicked()
{
    hide();
    adminPage = new adminpage(this);
    adminPage->show();

    maintenance maintenance;
    maintenance.setModal(true);
    maintenance.exec();
}

void MainWindow::on_mainwindow_StartTourButton_clicked()
{
    PlanTrip->show();
    this->close();
}


void MainWindow::on_mainwindow_MaintenanceButton_clicked()
{
    Login->show();
    this->close();
}

