/**********************************************************/
#include "plantripwindow.h"
#include "ui_plantripwindow.h"
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
    //this->setWindowState(Qt::WindowMaximized);
    ui->setupUi(this);
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
 * IN: QVector<QString>, campuses
 * OUT: bool
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

    bool allFound = checkCampusVectorNames(initial11);

    if(!allFound){
        QMessageBox::warning(this, "ERROR", "The 11 initial college are incomplete, please check with the administrator.", QMessageBox::Ok, QMessageBox::NoButton);
    }else{
        selectedCampuses.append(initial11);

        QString start = *selectedCampuses.begin();
        recursiveCollegeSort(start);

        for(int i = 0; i < sortedCampuses.count(); i++)
        {
            ui->sort_listWidget->addItem(sortedCampuses[i]);
        }
    }
}


/*
 * recursiveCollegeSort()
 * This function creates the optimal college touring trip plan.
 * For example, from the starting campus, the next campus will be the closest to the start, then the closest after that.
 * Each recursive call find the closest campus to the campus passed in.
 * When the closest is found, the new campus is sorted and then used for the next call.
 * IN: QString, currentCamp
 * OUT: nothing returned
 */
void planTripWindow::recursiveCollegeSort(QString currentCamp)
{
   sortedCampuses.enqueue(currentCamp);
   selectedCampuses.removeAll(currentCamp);

   if(selectedCampuses.isEmpty())
   {
       return;
   }
   else
   {
        QString* otherCamp = selectedCampuses.begin();
        int currentIndex = 0;

        double leastDist = m_database.GetDistBtwn(currentCamp, *otherCamp);
        int leastIndex = 0;

        otherCamp++;
        currentIndex++;

        while(otherCamp != selectedCampuses.end())
        {
            double currentDist = m_database.GetDistBtwn(currentCamp, *otherCamp);
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
