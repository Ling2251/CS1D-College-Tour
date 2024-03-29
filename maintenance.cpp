/**********************************************************/
#include "maintenance.h"
#include "ui_maintenance.h"
#include "inputcollege.h"
#include "souveniraddandedit.h"
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
    hide();
    inputCollege.setModal(true);
    inputCollege.exec();


}


void maintenance::on_pushButton_clicked()
{
    souvenirAddandEdit souvenir;
    hide();
    souvenir.setModal(true);
    souvenir.exec();
}

