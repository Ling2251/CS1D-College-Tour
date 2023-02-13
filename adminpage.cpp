#include "adminpage.h"
#include "ui_adminpage.h"

adminpage::adminpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminpage)
{
    ui->setupUi(this);
}

adminpage::~adminpage()
{
    delete ui;
}
