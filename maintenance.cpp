/**********************************************************/
#include "maintenance.h"
#include "ui_maintenance.h"
#include "inputcollege.h"
/**********************************************************/

/**********************************************************
*
* maintenance
*_________________________________________________________
*This page will require a login to be used. However, it will
*allow the user to edit the colleges as well as the ability
*to edit the souvenirs for each college.
*_________________________________________________________
***********************************************************/

maintenance::maintenance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::maintenance)
{
    ui->setupUi(this);

}

maintenance::~maintenance()
{
    delete ui;
}

void maintenance::on_pushButton_2_clicked()
{
    InputCollege inputCollege;
    inputCollege.setModal(true);
    inputCollege.exec();


}



