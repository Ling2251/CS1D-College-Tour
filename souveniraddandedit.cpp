#include "souveniraddandedit.h"
#include "ui_souveniraddandedit.h"

souvenirAddandEdit::souvenirAddandEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::souvenirAddandEdit)
{
    ui->setupUi(this);

    displayCollegeComboBox();
    displayItemComBox();

}

souvenirAddandEdit::~souvenirAddandEdit()
{
    delete ui;
}

void souvenirAddandEdit::displayCollegeComboBox()
{
    dbManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn.m_database);

    // only put the name out from the souvenirs
    list->prepare("select collegeName as \"Campuses\" from souvenirs group by collegeName;");
    list->exec();

    // if exect then set it to the ui
    modal->setQuery(*list);
    ui->displayCollegeComboBox->setModel(modal);
}

void souvenirAddandEdit::on_pushButton_clicked()
{
    dbManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();


    QSqlQuery* qry = new QSqlQuery(conn.m_database);
    QString currentName;

    currentName = ui->displayCollegeComboBox->currentText();

    //selects the list in the data base
    qry->prepare("select * from souvenirs where collegeName= ?");
    qry->addBindValue(currentName);

    // error message if the item can't be added due to the data base
    if(qry->exec())
    {
        while(qry->next()){
            QMessageBox::about(this, "", "The souvenir report is printed, double check if error occured");

            //Tranfers data from Querry to model
            modal->setQuery(*qry);

            //data base customers get viewed on the ui table view
            ui->tableView->setModel(modal);

            //closes connention to data base
            //counts rows from the model
            qDebug() <<(modal->rowCount());
        }
    }
    else
    {
        QMessageBox::about(this, "Error", "Database not found double check path to database");
    }
}


void souvenirAddandEdit::on_update_clicked()
{
    dbManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery(conn.m_database);

    QString collegeName,souvenirs,cost;

    collegeName = ui->displayCollegeComboBox->currentText();
    souvenirs = ui->displayItemComBox->currentText();
    cost = ui->costLine->text();

    conn.m_database.open();

    qry->prepare("update souvenirs set cost='"+cost+"'where souvenirsName='"+souvenirs+"'");

    if(qry->exec())
    {
        QMessageBox::critical(this,tr("Edit"),tr("Updated"));
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry->lastError().text());
    }

}

void souvenirAddandEdit::displayItemComBox()
{
    dbManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn.m_database);

    QString college;
    college = ui->displayCollegeComboBox->currentText();
    // only put the name out from the souvenirs
    list->prepare("select souvenirsName from souvenirs;");
    list->exec();

    // if exect then set it to the ui
    modal->setQuery(*list);
    ui->displayItemComBox->setModel(modal);
}

