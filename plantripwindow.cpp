/**********************************************************/
#include "plantripwindow.h"
#include "ui_plantripwindow.h"
#include "userinterface.h"
#include <QComboBox>
#include "mainwindow.h"
/**********************************************************/

/**********************************************************
*
* planTripWindow
*_________________________________________________________
*This page will allow the user to choose between the three
*options. They can either start a trip from a starting point
*of Saddleback College. They can also plan their own custom
*trip from any college they like. Lastly, they can plan a
*short trip with a, starting at Arizona State University.
*_________________________________________________________
***********************************************************/

planTripWindow::planTripWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::planTripWindow)
{
    //Shows the UI that has the different trip selections
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->StudentSelect);

    // clear the prives shoping cart item
    m_database.deleteCart();
}

planTripWindow::~planTripWindow()
{
    delete ui;
}

// This button when pressed will send the user to a page that will allow them to plan the shortest trip
void planTripWindow::on_planShortTrip_clicked()
{

}

// This button when pressed will send the user to a page that will allow them to a plan custom trip
void planTripWindow::on_planCustomTrip_clicked()
{

}

/*
 * checkCampusVectorNames(QVector<QString> campuses)
 * This function will check to if all the campuses from the vector are present in the database.
 */
bool planTripWindow::checkCampusVectorNames(QVector<QString> campuses)
{
    bool found = true;
    QString *p = campuses.begin();
    while (p != campuses.end() && found == true)
    {
        if(!m_database.checkCampusName(*p))
        {
            found = false;

        }
        else
        {
            p++;
        }
    }
    return found;
}

// This button when pressed will send the user to a page that will allow them to vist any colleges starting at Saddleback
void planTripWindow::on_startTrip_clicked()
{
    // putting all initiall college in to a vector including saddleback college
    QVector<QString> initial11{"Saddleback College",
                               "University of California, Irvine (UCI)",
                               "Arizona State University",
                               "Massachusetts Institute of Technology (MIT)",
                               "Northwestern",
                               "Ohio State University",
                               "University of  Michigan",
                               "University of California, Los Angeles (UCLA)",
                               "University of Oregon",
                               "University of Wisconsin",
                               "University of the Pacific",
                               };

    // check if all the college is in the database befor the recursive function
    bool allFound = checkCampusVectorNames(initial11);

    if(!allFound){
        QMessageBox::warning(this, "ERROR", "The 11 initial college are incomplete, please check with the administrator.", QMessageBox::Ok, QMessageBox::NoButton);
    }else{

        selectedCampuses.append(initial11);
        //displayCollegeTripList();
        QMessageBox::information(this, "Loading...", "Start Trip has been selected. Now moving to Souvenir Screen.", QMessageBox::Ok, QMessageBox::NoButton);
        // hid the current UI and show the sovenirs UI
        goToSouvenirShop();
    }
}

/*
 * recursiveCollegeSort()
 * This function will creat the shortest way to visit different colleges.
 * For example, from the starting campus, the next campus will be the closest to the startding college, then the closest after that.
 * Each recursive call find the closest campus to the campus passed in.
 * When the closest is found, the new campus is sorted and then used for the next call.
 */
void planTripWindow::recursiveCollegeSort(QString currentCamp)
{
   sortedCampuses.enqueue(currentCamp);         /**< queue of sorted campuses for tour*/
   selectedCampuses.removeAll(currentCamp);     /**< vector of selected campuses for the tour*/
   //double distance = 0.0;

   // first check to see if there is anly college in the selectedCampuse vector
   if(selectedCampuses.isEmpty())
   {
       return;
   }
   else
   {
       // set the frist campises to a string
        QString* otherCamp = selectedCampuses.begin();
        int currentIndex = 0;

        // getting the distanct using GetDistBtwn function in dbmanger
        double leastDist = m_database.GetDistBtwn(currentCamp, *otherCamp);
        int leastIndex = 0;

        otherCamp++;
        currentIndex++;

        // keep looping thorgh the colleges untill it has reach to the end of the vector
        while(otherCamp != selectedCampuses.end())
        {
            // // getting the current distanct using GetDistBtwn function in dbmanger
            double currentDist = m_database.GetDistBtwn(currentCamp, *otherCamp);
            //distance += m_database.GetDistBtwn(currentCamp, *otherCamp);

            // do the comparsion
            if (currentDist < leastDist)
            {
                leastDist = currentDist;
                leastIndex = currentIndex;
            }
            else
            {
                otherCamp++;
                currentIndex++;
            }
        }
        QString nextCamp = selectedCampuses.at(leastIndex);
        recursiveCollegeSort(nextCamp);
        this->distance = distance;
   }
}


/*
 * goToSouvenirShop()
 * This function switches the current UI to the Souvenir shop UI and initializes the widgets on the UI.
 */
void planTripWindow::goToSouvenirShop()
{
    //Go to souvenirShop widget
    ui->stackedWidget->setCurrentWidget(ui->souvenirShop);
    showSouvTableView(m_database.loadCampusSouvenirs(""));
    showSelectCampusComboBox(new QStringListModel(QList<QString>::fromVector(selectedCampuses)));

    showSouvTableView(m_database.loadCampusSouvenirs(ui->selectCampus_comboBox->currentText()));
    //create Cart table
    m_database.createCart();
    showSouvCartTableView(m_database.loadSouvCart(sQry));
    //showTotalCost(totalCost);
    //showDistance(distance);
}


    /*UI DESIGN*/
/*
 * gobackbuttonclicked()
 * This function let the go back button work on the screen
 */
void planTripWindow::on_goback_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->StudentSelect);
}

void planTripWindow::on_goback2_clicked()
{
    userInterface user;
    hide();
    user.setModal(true);
    user.exec();
}

//go home screen button
//This button will allow the user to go back to home page
void planTripWindow::on_mainpage_clicked()
{
    QList<QWidget*> topLevelWidgets = qApp->topLevelWidgets();
        foreach(QWidget *widget, topLevelWidgets) {
            QMainWindow *mainWindow = qobject_cast<QMainWindow*>(widget);
            if (mainWindow) {
                // Show the main window if it was previously hidden
                if (!mainWindow->isVisible()) {
                    mainWindow->show();
                }
                break;
            }
        }
    hide();

}

//This button will allow the user to go back to home page
void planTripWindow::on_mainpage_2_clicked()
{
    QList<QWidget*> topLevelWidgets = qApp->topLevelWidgets();
        foreach(QWidget *widget, topLevelWidgets) {
            QMainWindow *mainWindow = qobject_cast<QMainWindow*>(widget);
            if (mainWindow) {
                // Show the main window if it was previously hidden
                if (!mainWindow->isVisible()) {
                    mainWindow->show();
                }
                break;
            }
        }
    hide();

}


    /*UI DESIGN ENDS HERE*/

/*
 * showSelectCampusComboBox(QStringListModel *model)
 * The campus combo box for the souvenir shop UI will display the information held in a QStringListModel pointer.
 */
void planTripWindow::showSelectCampusComboBox(QStringListModel *model)
{
    ui ->selectCampus_comboBox->setModel(model);
}

/*
 * showSouvTableView(QSqlQueryModel *model)
 * The souvenir table view for the souvenir shop UI will display the information about the souvenirs of a specified campus held in a QStringListModel pointer.
 */
void planTripWindow::showSouvTableView(QSqlQueryModel *model)
{
    ui->souv_tableView->setModel(model);
    ui->souv_comboBox->setModel(model);
}

/*
 * on_selectCampus_comboBox_currentIndexChanged()
 * This function changes the souviner table depening on what campus the users has selected in the combo box.
 */
void planTripWindow::on_selectCampus_comboBox_currentIndexChanged()
{
    QString campus = ui->selectCampus_comboBox->currentText();
    showSouvTableView(m_database.loadCampusSouvenirs(campus));
}

/*
 * showSouvCartTableView(QSqlQueryModel *model)
 * The souvenir cart table view for the souvenir shop UI will display the information about the souvenirs selected held in a QStringListModel pointer.
 */
void planTripWindow::showSouvCartTableView(QSqlQueryModel *model)
{
    ui->souvCart_tableView->setModel(model);
}

/*
 * on_addSouvenir_button_clicked()
 * The function adds souvenirs to the souvenir cart using an accumulator string to use as the query for the database.
 * It also adds the total of the item costs in an accumulator total.
 */
void planTripWindow::on_addSouvenir_button_clicked()
{
    Souvenir souv;
    //set the name and campus
    QString name, campus;
    name = ui->souv_comboBox->currentText();
    souv.souvName = name;
    campus = ui->selectCampus_comboBox->currentText();
    souv.campus = campus;


    //get the quantity and item cost
    int quantity = ui-> quantity_spinBox -> cleanText().toInt();
    souv.quantity = quantity;



    souvenirCart.push(souv);

    //update Cart table
    m_database.updateCartQuantity(campus, name, quantity);

    //displays cart in table
   if(sQry == "")
   {
       sQry += "select collegeName as 'College', souvenirsName as 'Souvenirs', cost as 'Cost', quantity as 'Quantity' "
                       "from Cart where collegeName = '" +campus+ "' and souvenirsName = '" +name+ "'";
   }
   else
   {
       sQry += " union select collegeName as 'College', souvenirsName as 'Souvenirs', cost as 'Cost', quantity as 'Quantity'"
                       "from Cart where collegeName = '" +campus+ "' and souvenirsName = '" +name+ "'";
   }

   showSouvCartTableView(m_database.loadSouvCart(sQry));

   calculateTotal();
   showTotal(total);
  // showSouvCartTableView();
  // get the total cost here__YC:
}

//calculate function is to calculate total price from the cart table
void planTripWindow::calculateTotal()
{
    double total = 0.0;
    QSqlQuery qry;

    if(true)
    {
        qry.prepare("select printf(\"%.2f\",sum(cost * quantity)) from Cart;");
        qry.exec();
        if(qry.next())
        {
            total = qry.value(0).toDouble();
        }
    }

    this->total = total;

}

//showTotal function is to display the total purchases in the label
//pass the variable total from calculateTotal()function
void planTripWindow::showTotal(double total)
{
    ui->totalCart_label->setNum(total);
}
//showDistance function is to display the total distance travled
//pass the variable total from calculateTotal()function
//void planTripWindow::showDistance(double distance)
//{
//    ui->totalDistance_label->setNum(distance);
//}

