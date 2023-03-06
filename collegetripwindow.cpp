#include "collegetripwindow.h"
#include "ui_collegetripwindow.h"

collegetripwindow::collegetripwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::collegetripwindow)
{
    ui->setupUi(this);
}

collegetripwindow::~collegetripwindow()
{
    delete ui;
}

void collegetripwindow::on_collegetrip_NextCollegeButton_clicked()
{
    this->close();
    emit receiptPage();
}

