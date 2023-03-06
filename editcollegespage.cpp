#include "editcollegespage.h"
#include "ui_editcollegespage.h"

editcollegespage::editcollegespage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcollegespage)
{
    ui->setupUi(this);
}

editcollegespage::~editcollegespage()
{
    delete ui;
}
