/**********************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinterface.h"
#include "maintenance.h"
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

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

