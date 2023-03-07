#include "loginpage.h"
#include "ui_loginpage.h"
#include "maintenance.h"
#include <QMessageBox>


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

void loginpage::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_Username->text();
       QString password = ui->lineEdit_password->text();

       if(username == "Admin" && password == "1234")
       {
           QMessageBox::information(this, "Login", "Logged in");
           maintenance maintenance;
           hide();
           maintenance.setModal(true);
           maintenance.exec();
           
       }
       else
       {
           QMessageBox::warning(this, "Login", "Username or Password is Incorrect");
       }
}

