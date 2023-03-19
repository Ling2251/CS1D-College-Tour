/**********************************************************/
#include "plantripwindow.h"
#include "ui_plantripwindow.h"
#include "userinterface.h"
#include <QComboBox>
#include <QInputDialog>
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
    // initial the value
    asuNum = 0;
    selectNum = 0;
    distance = 0.0;

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
    /**----------------------------------
    // Test(1) -> 5 trips:
    // distance: 790.3
    // cost: 0

    // Test(2) -> 4 trips:
    // distance: 457.3
    // cost: 0

    */

    // asking the user to input their how many collges they would like to vist
    int selectedCampusCount = QInputDialog::getInt(this,tr("Number of Colleges you want to visit starting from Arizona State University"), "Enter the total number of colleges you want to visit:");
    qDebug() << selectedCampusCount;

    // putting all initiall college in to a vector starting at ASU
    QVector<QString> initial11{"Arizona State University",
                               "University of California, Irvine (UCI)",
                               "Saddleback College",
                               "University of California, Los Angeles (UCLA)",
                               "University of the Pacific",
                               "University of Oregon",
                               "University of Wisconsin",
                               "Northwestern",
                               "University of  Michigan",
                               "Ohio State University",
                               "Massachusetts Institute of Technology (MIT)",
                               };
    // check if all the college is in the database befor the recursive function
    bool allFound = checkCampusVectorNames(initial11);

    if(!allFound){
        QMessageBox::warning(this, "ERROR", "The college list are incomplete, not all 11 college are in the list please check with the administrator.", QMessageBox::Ok, QMessageBox::NoButton);

    }
    // check if the selected campus count is in range
    else if (selectedCampusCount <= 0 || selectedCampusCount > 11)
    {
          QMessageBox::warning(this, "ERROR", "Incorrect number of colleges were selected, Please try again", QMessageBox::Ok, QMessageBox::NoButton);
          planTripWindow user;
          hide();
          user.setModal(true);
          user.exec();
    }
    else
    {
        // resize the list depending on the selected campus count
        initial11.resize(selectedCampusCount);

        // append the selected campus list
        selectedCampuses.append(initial11);

        // the start of the list
        QString shortTrip = *selectedCampuses.begin();

        // recursively sort through the list
        recursiveCollegeSort(shortTrip);

        // calculate the distance and output it
        distance = calculateDistance(selectedCampusCount);
        showTotalDistent(distance);

        // hid the current UI and show the sovenirs UI
        selectedCampuses.append(initial11);
        goToSouvenirShop();
    }

}

// This button when pressed will send the user to a page that will allow them to a plan custom trip
void planTripWindow::on_planCustomTrip_clicked()
{
    /**-----------------------------
    // Test(1):
    // distance: 3201
    // cost: 713.97

    // Test(2):
    // distance: 2412
    // cost: 181.95

    //-----------------------------------------
    //       MAKE CHANGES

    //-----------------------------------------
    // Test(3):
    // distance: 1720
    // cost: 222.40

    // Test(4):
    // distance: 3107
    // cost: 587.44

    */

    ui->stackedWidget->setCurrentWidget(ui->customCollegeTour);

    showAvaliListView(m_database.loadCampusNamesOnly());
    showAvaliListCombo(m_database.loadCampusNamesOnly());
}

/*
 * showAvaliListView(QSqlQueryModel *model)
 * The avaliable campuses list view on the general tour college selection UI will display the information held in a QSqlQueryModel pointer.
 * @param QSqlQueryModel, model (passed as a pointer)
 * @return nothing returned
 */
void planTripWindow::showAvaliListView(QSqlQueryModel *model)
{
    ui->avali_listView->setModel(model);
}

/*
 * showSelectListView(QSqlQueryModel *model)
 * The selected campuses list view on the general tour college selection UI will display the information held in a QSqlQueryModel pointer.
 * IN: QSqlQueryModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void planTripWindow::showSelectListView()
{
    ui->select_listView->setModel(new QStringListModel(QList<QString>::fromVector(selectedCampuses)));
}

/*
 * showAvaliListCombo(QSqlQueryModel *model)
 * The avaliable campuses combo box on the general tour college selection UI will display the information held in a QSqlQueryModel pointer.
 * IN: QSqlQueryModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void planTripWindow::showAvaliListCombo(QSqlQueryModel *model)
{
    ui->next_combo->setModel(model);
}


void planTripWindow::on_enter_button_clicked()
{

    //Students choice is saved into the vector
    QString campus = ui->next_combo->currentText();

    //No campuses
    if(campus == "")
    {
        QMessageBox::warning(this, "ERROR", "NO MORE CAMPUSES! PLEASE CLICK DONE!", QMessageBox::Ok, QMessageBox::NoButton);
    }
    else if (selectNum == asuNum && selectNum!= 0)
    {
        QMessageBox::warning(this, "ERROR", "YOU HAVE REACHED YOUR MAX FOR THE ASU TOUR! PLEASE CLICK DONE!", QMessageBox::Ok, QMessageBox::NoButton);
    }
    //Campuses remain
    else
    {
        //Pushes newly selected campus to the back of the vector
        selectedCampuses.push_back(campus);
        selectNum++;
        //Refreshes list views and combo box
        showAvaliListView(m_database.loadRemainingCampusNamesOnly(selectedCampuses));
        showSelectListView();
        showAvaliListCombo(m_database.loadRemainingCampusNamesOnly(selectedCampuses));
    }
}


void planTripWindow::on_done_button_clicked()
{
    if((asuNum == 0 || selectNum == asuNum) && selectNum!= 0)
    {
        QMessageBox::information(this, "Loading...", "An custom trip has been selected and you are done selecting all your colleges. Now moving to Souvenir Screen.", QMessageBox::Ok, QMessageBox::NoButton);
        copy(selectedCampuses.begin(), selectedCampuses.end(), back_inserter(campuseList));

        // recursively sort through the list
        // the start of the list
        QString shortTrip = *campuseList.begin();

        recursiveCollegeSort(shortTrip);

        // calculate the distance and output it
        distance = calculateDistance(selectNum);
        showTotalDistent(distance);

        //Go to souvenirShop widget
        copy(campuseList.begin(), campuseList.end(), back_inserter(selectedCampuses));
        goToSouvenirShop();
    }
    else
    {
        QMessageBox::warning(this, "ERROR", "PLEASE SELECT AT LEAST ONE CAMPUSES THAT IS ON THE LIST.", QMessageBox::Ok, QMessageBox::NoButton);
    }
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
    /**----------------------------------
    // Test:
    // distance: 5315.5
    // cost: 0

    */

    // putting all initiall college in to a vector starting at saddleback college
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
         // append the selected campus list
        selectedCampuses.append(initial11);
        QString startTrip = *selectedCampuses.begin();

        // recursively sort through the list
        recursiveCollegeSort(startTrip);

        // calculate the distance and output it
        distance = calculateDistance(11);
        showTotalDistent(distance);

        // hid the current UI and show the sovenirs UI
        selectedCampuses.append(initial11);
        goToSouvenirShop();
    }
}

void planTripWindow::showTotalDistent(double distance){
      ui->finalDistance_Lable->setNum(distance);
}

// This button when pressed will send the user to a page that will allow them to vist any colleges starting at UCI
void planTripWindow::on_startTripFormUIC_clicked()
{
    /**----------------------------------
    // Test:
    // distance should be: 5847.2
    // cost: 0

    */

    // putting all initiall college in to a vector starting at UCI
    QVector<QString> initial13{"University of California, Irvine (UCI)",
                               "Saddleback College",
                               "Arizona State University",
                               "Massachusetts Institute of Technology (MIT)",
                               "Northwestern",
                               "Ohio State University",
                               "University of  Michigan",
                               "University of California, Los Angeles (UCLA)",
                               "University of Oregon",
                               "University of Wisconsin",
                               "University of the Pacific",
                               "California State University, Fullerton",
                               "University of Texas"
                               };

    // check if all the college is in the database befor the recursive function
    bool allFound = checkCampusVectorNames(initial13);

    if(!allFound){
        QMessageBox::warning(this, "ERROR", "The college list are incomplete, not all 13 college are in the list please check with the administrator.", QMessageBox::Ok, QMessageBox::NoButton);

    }else{
        // append the selected campus list
        selectedCampuses.append(initial13);

        // append the selected campus list
        QString startTrip = *selectedCampuses.begin();

        // recursively sort through the list
        recursiveCollegeSort(startTrip);

        // calculate the distance and output i
        distance = calculateDistance(13);
        showTotalDistent(distance);

        // hid the current UI and show the sovenirs UI
        selectedCampuses.append(initial13);
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
    m_database.createCart();
    showSouvCartTableView(m_database.loadSouvCart(sQry));
}


    /*UI DESIGN*/
/*
 * gobackbuttonclicked()
 * This function let the go back button work on the screen
 */
void planTripWindow::on_goback_clicked()
{
    planTripWindow user;
    hide();
    user.setModal(true);
    user.exec();
}

void planTripWindow::on_goback2_clicked()
{
    userInterface user;
    hide();
    user.setModal(true);
    user.exec();
}

void planTripWindow::on_custom_goback_clicked()
{
    planTripWindow user;
    hide();
    user.setModal(true);
    user.exec();
}

void planTripWindow::on_receiptDone_clicked()
{
    QMessageBox::information(this, "Loading...", "You are now done with this trip. Now retruning to the main selection Screen.", QMessageBox::Ok, QMessageBox::NoButton);

    // clear the prives shoping cart item and all other things
    m_database.deleteCart();
    sQry.clear();
    asuNum = 0;
    selectNum = 0;
    total = 0;

    while(!sortedCampuses.empty())
    {
        sortedCampuses.pop_front();
    }

    planTripWindow user;
    hide();
    user.setModal(true);
    user.exec();
}

void planTripWindow::on_doneBuying_clicked()
{
    QMessageBox::information(this, "Loading...", "You are done buying all souvenirs. Now moving to the receipt Screen.", QMessageBox::Ok, QMessageBox::NoButton);
    displayReceiptPage();

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
    ui->collegecomboBox->setModel(model);
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
    ui->souvenirsListView->setModel(model);

}

/*
 * on_addSouvenir_button_clicked()
 * The function adds souvenirs to the souvenir cart using an accumulator string to use as the query for the database.
 * It also adds the total of the item costs in an accumulator total.
 */
void planTripWindow::on_addSouvenir_button_clicked()
{
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


   // call the calculate function
   calculateTotal();

   showTotal(total);
  // showSouvCartTableView();
  // get the total cost here__YC:
}

//calculate function is to calculate total price from the cart table
//assign the variable into the elements in header file
void planTripWindow::calculateTotal()
{
    //initial a double type total
    double total = 0.0;

    // initial ary
    QSqlQuery qry;

    //if the statement is true, then run the calculation method
    if(true)
    {
        qry.prepare("select printf(\"%.2f\",sum(cost * quantity)) from Cart;");
        qry.exec();
        if(qry.next())
        {
            total = qry.value(0).toDouble();
        }
    }

    //assign the value to the header
    this->total = total;

}

//calculateDistance function is to calculate total distance traveled
double planTripWindow::calculateDistance(int selectedCampusCount)
{
     //initial a double type total
    double distance = 0.0;

     // set the campises to a string
    QString* currentCampus = selectedCampuses.begin();
    QString* otherCampus = selectedCampuses.begin();

    // loop through for each campus that was selected
    for (int i = 0; i < selectedCampusCount; i++)
    {
       distance += m_database.GetDistBtwn(*otherCampus,*currentCampus);
       currentCampus = otherCampus;
       otherCampus++;
    }

    // return the final distance
    return distance;

}

//showTotal function is to display the total purchases in the label
//pass the variable total from calculateTotal()function
void planTripWindow::showTotal(double total)
{
    // associate the total with the label in the uo page
    ui->finalCostLabel->setNum(total);
}


//displayReceiptPage function is to display the list of college that
//the student will viste in order and the souvenirs that they bought
//at each college, as well as the total distenct and the total price.
void planTripWindow::displayReceiptPage(){

    //Go to the receipt widget
    ui->stackedWidget->setCurrentWidget(ui->receiptPage);
    // set the combo box to display all the selected college
    showSelectCampusComboBox(new QStringListModel(QList<QString>::fromVector(selectedCampuses)));

    // display the college vistting order on to the screen
    for(int i= 0; i<selectedCampuses.count(); i++){
        ui->collegeListView->setModel((new QStringListModel(QList<QString>::fromVector(selectedCampuses))));
        ui->collegeListView->setColumnWidth(0, 460);
        ui->collegeListView->setColumnWidth(1, 280);
    }

}

void planTripWindow::on_SearchButton_clicked()
{
    double collegeSouvenirsPrice = 0.0;
    QString campaseName;
    QSqlQuery qry;
    double cost = 0.00;

    campaseName = ui->collegecomboBox->currentText();
    ui->SelectedCollegeLabel->setText(campaseName);

    //qry.prepare("select cost from Cart where collegeName='"+campaseName+"'");
    qry.prepare("select printf(\"%.2f\",sum(cost * quantity)) from Cart where collegeName='"+campaseName+"'");
    qry.exec();
    if(qry.next()){
        cost = (qry.value(0).toDouble());
    }else{
        QMessageBox::warning(this, "ERROR", "There is issue with the displaying", QMessageBox::Ok, QMessageBox::NoButton);
    }

    collegeSouvenirsPrice =  cost;
    ui->collegeCostLabel->setNum(collegeSouvenirsPrice);

}

