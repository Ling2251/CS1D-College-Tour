/**********************************************************/
#include "plantripwindow.h"
#include "ui_plantripwindow.h"
/**********************************************************/

/**********************************************************
*
* planTripWindow
*_________________________________________________________
*This page will allow the user to choose between the three
*options. They can either start a trip from a starting point
*of Saddleback College. They can also plan their own custom
*trip from any college they like. Lastly, they can plan a
*short trip with a, starting at Arizona State University.
*_________________________________________________________
***********************************************************/

planTripWindow::planTripWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::planTripWindow)
{
    //this->setWindowState(Qt::WindowMaximized);
    ui->setupUi(this);
}

planTripWindow::~planTripWindow()
{
    delete ui;
}

// This button when pressed will send the user to a page that will allow them to plan the shortest trip
void planTripWindow::on_planShortTrip_clicked()
{

}

// This button when pressed will send the user to a page that will allow them to a plan custom trip
void planTripWindow::on_planCustomTrip_clicked()
{

}

// This button when pressed will send the user to a page that will allow them to vist any colleges starting at Saddleback
void planTripWindow::on_startTrip_clicked()
{

}


void planTripWindow::on_plantrip_ReturnButton_clicked()
{
    this->close();
    emit firstWindow();
}


void planTripWindow::on_plantrip_SaddlebackButton_clicked()
{
    this->close();
    emit collegeWindow();
}


void planTripWindow::on_plantrip_ArizonaStateButton_clicked()
{
    this->close();
    emit collegeWindow();
}


void planTripWindow::on_plantrip_CustomCollegeButton_clicked()
{
    this->close();
    emit collegeWindow();
}

