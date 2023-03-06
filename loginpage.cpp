#include "loginpage.h"
#include "ui_loginpage.h"

loginpage::loginpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginpage)
{
    ui->setupUi(this);
}

loginpage::~loginpage()
{
    delete ui;
}

void loginpage::on_pushButton_cancel_clicked()
{
    this->close();
    emit firstWindow();
}


void loginpage::on_pushButton_login_clicked()
{
    this->close();
    emit adminWindow();
}

