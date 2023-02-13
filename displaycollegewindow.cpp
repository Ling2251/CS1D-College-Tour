/**********************************************************/
#include "displaycollegewindow.h"
#include "ui_displaycollegewindow.h"
/**********************************************************/

/**********************************************************
*
* displayCollegeWindow
*_________________________________________________________
*This page will display all the colleges offered by the
*program as well as their traditional souvenirs.
*_________________________________________________________
***********************************************************/
displayCollegeWindow::displayCollegeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayCollegeWindow)
{
    ui->setupUi(this);
}

//
displayCollegeWindow::~displayCollegeWindow()
{
    delete ui;
}


