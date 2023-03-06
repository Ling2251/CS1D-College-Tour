#include "receiptpage.h"
#include "ui_receiptpage.h"

receiptpage::receiptpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::receiptpage)
{
    ui->setupUi(this);
}

receiptpage::~receiptpage()
{
    delete ui;
}

void receiptpage::on_receiptpage_FinishButton_clicked()
{
    this->close();
    emit firstWindow();
}

