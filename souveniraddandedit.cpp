#include "souveniraddandedit.h"
#include "ui_souveniraddandedit.h"

souvenirAddandEdit::souvenirAddandEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::souvenirAddandEdit)
{
    ui->setupUi(this);

    //display the college comboBox and souvenirs comboBox
    displayCollegeComboBox();
    displayItemComBox();

}

souvenirAddandEdit::~souvenirAddandEdit()
{
    delete ui;
}

/*This function is to create the combobox of college, to let mantenence to
 * pick the college that he want*/
void souvenirAddandEdit::displayCollegeComboBox()
{
    //connect database
    dbManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn.m_database);

    // only put the college name out from the souvenirs
    list->prepare("select collegeName as \"Campuses\" from souvenirs group by collegeName;");
    list->exec();

    // if exect then set it to the ui
    modal->setQuery(*list);

    //set college name into comboBox
    ui->displayCollegeComboBox->setModel(modal);
}

/*pushbutton to log the item who included each college
 * only souvenirname and cost will display in tableView
 * */
void souvenirAddandEdit::on_pushButton_clicked()
{
    //connect database
    dbManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();


    QSqlQuery* qry = new QSqlQuery(conn.m_database);

    //create a current string
    QString currentName;

    //set this variabble bycomboBox
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

/*Update button to update the cost of each souvenir that you want
 *This button will connect the college comboBox and souvenirs comboBox
 *Also this button will connect with the tableView
*/
void souvenirAddandEdit::on_update_clicked()
{
    //connect database
    dbManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();

    QSqlQuery* qry = new QSqlQuery(conn.m_database);

    //create three string variables
    QString collegeName,souvenirs,cost;

    //assign those variables with the current text
    collegeName = ui->displayCollegeComboBox->currentText();
    souvenirs = ui->souvenirsLine->text();
    cost = ui->costLine->text();

    //open the database
    conn.m_database.open();

    //update function to update the cost
    qry->prepare("update souvenirs set cost='"+cost+"'where souvenirsName='"+souvenirs+"'");

    //if update succesfully then will display a messageBox::Update
    if(qry->exec())
    {
        QMessageBox::critical(this,tr("Edit"),tr("Updated"));
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry->lastError().text());
    }

}

/*Display souvenirs comboBox function will display all the souvenir
fron the souvenir database*/
void souvenirAddandEdit::displayItemComBox()
{
    //database object
    dbManager conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery * list = new QSqlQuery(conn.m_database);

    //q string variable
    QString college;
    college = ui->displayCollegeComboBox->currentText();

    // only put the name out from the souvenirs
    list->prepare("select souvenirsName from souvenirs;");
    list->exec();

    // if exect then set it to the ui
    modal->setQuery(*list);
    ui->displayItemComBox->setModel(modal);
}

/*This function will connect to the tableView
 * It can let user click the table to display all the
 * info of college in to the white line*/
void souvenirAddandEdit::on_tableView_activated(const QModelIndex &index)
{
    //Set val to tableView model
    QString val = ui->tableView->model()->data(index).toString();

    //connect database
    dbManager conn;
    QSqlQuery qry;

    //select the souvenirName and cost that you want
    qry.prepare("select * from souvenirs where souvenirsName= '"+val+"'or cost='"+val+"'");

    //if qry.exec, it will assign the info in to collegeLine, souvenirsLine, and costLine
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->collegeLine->setText(qry.value(0).toString());
            ui->souvenirsLine->setText(qry.value(1).toString());
            ui->costLine->setText(qry.value(2).toString());
        }
        //close the database
        conn.m_database.close();
    }
    else
    {
        //else it will display the error
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }


}


void souvenirAddandEdit::on_addButton_clicked()
{
    // opned the data base
    dbManager conn;

    conn.m_database.open();


    QSqlQuery qry;
    QString collegeName,souvenirName,cost;

    //get the data in from the ui intput
    collegeName   = ui->collegeLine->text();
    souvenirName  = ui->souvenirsLine->text();
    cost = ui->costLine->text();


    // error checking input
    if(collegeName != "" && cost != "" && souvenirName != ""){
        addOrDelet = true;
    }
    else{
        addOrDelet = false;
    }

    if(addOrDelet){
        // add the item
        qry.prepare("insert into souvenirs (collegeName, souvenirsName, cost) values ('"+collegeName+"', '"+souvenirName+"', '"+cost+"')");

        // error message if the item can't be added due to the data base
        if(qry.exec())
        {
            QMessageBox::about(this, "", "The item was added, double check if error occured");
            // close the connection to data base
            conn.m_database.close();
        }
        else
        {
            QMessageBox::about(this, "Error", "Database not found double check path to database");
        }
    }
    else{
        QMessageBox::about(this, "Error", "Can't enter an empty input to add an item, please try agin");
        //ClearSreen();
    }
}


void souvenirAddandEdit::on_deleteButton_clicked()
{
    // opned the data base
   dbManager conn;

   conn.m_database.open();
   //get the data in from the ui intput
   QSqlQuery qry;
   QString collegeName1,souvenirName1,cost1;

   //get the data in from the ui intput
   collegeName1   = ui->collegeLine->text();
   souvenirName1  = ui->souvenirsLine->text();
   cost1 = ui->costLine->text();

   // error checking input
   if(collegeName1 != "" && cost1 != "" && souvenirName1 != ""){
       addOrDelet = true;
   }
   else{
       addOrDelet = false;
   }

   if(addOrDelet)
   {
       // delete the item
       qry.prepare("Delete from souvenirs where collegeName=='"+collegeName1+"'and souvenirsName=='"+souvenirName1+"'and cost=='"+cost1+"'");

       // error message if the item can't be deleted due to the data base
       if(qry.exec())
       {
           QMessageBox::about(this, "", "The item(s) was/were deleted, double check if error occured");
       }
       else
       {
           QMessageBox::about(this, "Error", "Database not found double check path to database");
       }
   }

   else
   {
       QMessageBox::about(this, "Error", "Can't enter an empty or invaild input to delet an item , please try agin");
   }

}

