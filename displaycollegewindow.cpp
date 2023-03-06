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
    QVector<QString> initial11{"Saddleback College",
                               "University of California, Irvine (UCI)",
                               "Arizona State University",
                               "Massachusetts Institute of Technology (MIT)",
                               "Northwestern",
                               "Ohio State University",
                               "University of  Michigan",
                               "University of California, Los Angeles (UCLA)",
                               "University of Oregon",
                               "University of Wisconsin",
                               "University of the Pacific",
                               };

    for(int i = 0; i < 11; i++)
    {
        ui->listWidget->addItem(initial11[i]);
    }
}

//
displayCollegeWindow::~displayCollegeWindow()
{
    delete ui;
}



