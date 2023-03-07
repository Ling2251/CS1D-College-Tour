/**********************************************************/
#include "userinterface.h"
#include "ui_userinterface.h"
#include "plantripwindow.h"
#include "displaycollegewindow.h"
#include "mainwindow.h"
/**********************************************************/

/**********************************************************
*
* userInterface
*_________________________________________________________
*This page will allow users to choose between displaying
*all the colleges available and their souvenirs, or they
*can start planning their own trip.
*_________________________________________________________
***********************************************************/
userInterface::userInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userInterface)
{
    //this->setWindowState(Qt::WindowMaximized);
    ui->setupUi(this);
}

userInterface::~userInterface()
{
    delete ui;
}

// This button when pressed will send the user to a page that will provide them the option to display all the colleges
void userInterface::on_displayCollegeButton_clicked()
{
    displayCollegeWindow displaycollege;
    displaycollege.setModal(true);
    displaycollege.exec();
}

// This button when pressed will send the user to a page that will allow them to plan a trip of their choice
void userInterface::on_planTripButton_clicked()
{
    planTripWindow plantrip;
    plantrip.setModal(true);
    plantrip.exec();
}

//This button will allow the user to go back to home page
void userInterface::on_mainpage_clicked()
{
    QList<QWidget*> topLevelWidgets = qApp->topLevelWidgets();
        foreach(QWidget *widget, topLevelWidgets) {
            QMainWindow *mainWindow = qobject_cast<QMainWindow*>(widget);
            if (mainWindow) {
                // Show the main window if it was previously hidden
                if (!mainWindow->isVisible()) {
                    mainWindow->show();
                }
                break;
            }
        }
    hide();

}


