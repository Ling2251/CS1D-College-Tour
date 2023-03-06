/**********************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinterface.h"
#include "maintenance.h"
#include "loginpage.h"
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
    //hide();
//    loginpage = new adminpage(this);
//    adminPage->show();

    loginpage login;
    login.setModal(true);
    login.exec();
}
