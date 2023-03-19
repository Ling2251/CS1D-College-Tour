#ifndef PLANTRIPWINDOW_H
#define PLANTRIPWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QAbstractTableModel>
#include "dbmanager.h"
using namespace std;

/**
 * @file planTripWindow.h
 * @class planTripWindow
 * @brief Most functionality of the planTripWindow class is to give the
 * student options on how they would like to plan their trip and buying
 * multiple souvenits at differnt colleges
 */
namespace Ui {
class planTripWindow;
}

class planTripWindow : public QDialog
{
    Q_OBJECT

public:
    /** \struct Souvenir
     * Struct for the information about a souvenir purchased by the student.
     */
    struct Souvenir
    {
        QString souvName; /**< Souvenir name*/
        QString campus; /**< Campus of origin*/
        double cost; /**< Cost of the souvenir */
        int quantity; /**< Number of souvenirs purchased*/
    };

    /** \fn planTripWindow()
     * constructer function that create a window that display to the students
     * for differnt oppsions
     * @return nothing, it just display a window to the students
     */
    explicit planTripWindow(QWidget *parent = nullptr);

    /** \fn ~planTripWindow()
     *  A destructor function
     * */
    ~planTripWindow();

    /** \fn checkCampusVectorNames(QVector<QString> campuses)
     * This function will check to if all the campuses from the vector are present in the database.
     * @param QVector<QString>, the campuses name
     * @return true or falst, if the name is in the database
     */
    bool checkCampusVectorNames(QVector<QString> campuses);

    /** \fn recursiveCollegeSort()
     * This function sort the college touring trip list in order.
     * For example, from the starting campus, the next campus will be the closest to the start, then the closest after that.
     * Each recursive call find the closest campus to the campus passed in.
     * When the closest is found, the new campus is sorted and then used for the next call.
     * @param String currentCamp, the name of the current campues
     */
    void recursiveCollegeSort(QString currentCamp);

    /** \fn goToSouvenirShop()
     * This function switches the current UI to the Souvenir shop UI and initializes the widgets on the UI.
     * @param no parameters
     * @return nothing returned
     */
    void goToSouvenirShop();


    /** \fn showSelectCampusComboBox()
     * This function will used the tax that is in the campus combo box for the
     * souvenir shop UI and display the information held in a QStringListModel pointer.
     * @param pointer model, the list of college name in the form of database accesed it
     * by QStringListModel pointer
     * @return nothing returned, it just display souvenirs of the selected campus name in the combo box
     */
    void showSelectCampusComboBox(QStringListModel *model);

    /** \fn showSouvTableView()
     * The souvenir table view for the souvenir shop UI will display the information about the souvenirs of a selected
     *  campus held in a QStringListModel pointer.
     * @param pointer model, the list of souvenirs in the form of database accesed it
     * by QStringListModel pointer
     * @return nothing returned, it just display souvenirs of the selected campus name in the table view
     */
    void showSouvTableView(QSqlQueryModel *model);

    /** \fn showSouvCartTableView()
     * The souvenir cart table view for the souvenir shop UI will display the information about the souvenirs selected
     * held in a QStringListModel pointer.
     * @param pointer model, the list of souvenirs in the form of database accesed it
     * by QStringListModel pointer
     * @return nothing returned, it just display souvenirs of the selected campus name in the table view
     */
    void showSouvCartTableView(QSqlQueryModel *model);

    /** \fn calculateTotal()
     * This function calcuate the price total of what the student has purches from all campues.
     * @param no parameters
     * @return nothing returned
     */
    void calculateTotal();

    /** \fn calculateDistance()
     * This function calcuate the distance of the campues the student has selected from the trip.
     * @param int selectedCampusCount, the number of selected campus
     * @return double distance, the total distance
     */
    double calculateDistance(int selectedCampusCount);

    /** \fn showTotal()
     * This function show the total price of all souvenirs and initializes the widgets on the UI.
     * @param double total, the total price
     * @return nothing returned, it just set the total price to the UI
     */
    void showTotal(double total);

    /** \fn showAvaliListCombo()
     * The avaliable campuses combo box on the general tour college selection UI will display the information held in a QSqlQueryModel pointer.
     * @param QSqlQueryModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showAvaliListCombo(QSqlQueryModel *model);

    /** \fn showSelectListView()
     * The selected campuses list view on the general tour college selection UI will display the information held in a QSqlQueryModel pointer.
     * @param QSqlQueryModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showSelectListView();

    /** \fn showAvaliListView()
     * The avaliable campuses list view on the general tour college selection UI will display the information held in a QSqlQueryModel pointer.
     * @param QSqlQueryModel, model (passed as a pointer)
     * @return nothing returned
     */
    void showAvaliListView(QSqlQueryModel *model);

    /** \fn showTotalDistent()
     * This function show the total distent of each trip and initializes the widgets on the UI.
     * @param no parameters
     * @return nothing returned
     */
    void showTotalDistent(double distance);

    /** \fn displayReceiptPage()
     * This function switches the current UI to the final receipt page UI and initializes the widgets on the UI.
     */
    void displayReceiptPage();


private slots:

    /** \fn on_planShortTrip_clicked()
     * This function is the plan the shortes trip form ASU, it will plan the college
     * tour trip starding at ASU and vist the 11 college after click it.
     */
    void on_planShortTrip_clicked();

    /** \fn on_planCustomTrip_clicked()
     * This function is the plan the custom trip, it will plan the college
     * tour trip starding at where the student wants and vist the all other college
     * base on what student has pick after click it.
     */
    void on_planCustomTrip_clicked();

    /** \fn on_startTrip_clicked()
     * This function is the plan a trip form saddleback college, it will plan the college
     * tour trip starding at saddleback college and vist the 11 college after click it.
     */
    void on_startTrip_clicked();

    /** \fn on_selectCampus_comboBox_currentIndexChanged()
     * This function changes the souviner table base on what campus the student has selected in the combo box.
     */
    void on_selectCampus_comboBox_currentIndexChanged();

    /** \fn on_addSouvenir_button_clicked()
     * This function is the adding souvenirs function, it will display the souvenirs
     * the student has pick on to the cart table after click it.
     */
    void on_addSouvenir_button_clicked();
    
    /** \fn on_goback_clicked()
     * This function is the goback function, it will display the last page after click it.
     */
    void on_goback_clicked();

    /** \fn on_goback2_clicked()
     * This function is the goback function, it will display the last page after click it.
     */
    void on_goback2_clicked();

    /** \fn on_mainpage_clicked()
     * This function is the go to main page function, it will display the main page after click it.
     */
    void on_mainpage_clicked();

    /** \fn on_mainpage_2_clicked()
     * This function is the go to main page function, it will display the main page after click it.
     */
    void on_mainpage_2_clicked();

    /** \fn on_startTripFormUIC_clicked()
     * This function is the plan the a trip form UIC, it will plan the college
     * tour trip starding at UCI and vist the 13 college after click it.
     */
    void on_startTripFormUIC_clicked();

    /** \fn on_enter_button_clicked()
     * This function is the enter function, it will move the selected college name
     * the student has pick to the selectedCollege list after click it.
     */
    void on_enter_button_clicked();

    /** \fn on_done_button_clicked()
     * This function is the done function, it will display the souvenirs shop page after click it.
     */
    void on_done_button_clicked();

    /** \fn on_custom_goback_clicked()
     * This function is the goback function, it will display the last page after click it.
     */
    void on_custom_goback_clicked();

    /** \fn on_doneBuying_clicked()
     * This function is the done function, it will display the receipt page after click it.
     */
    void on_doneBuying_clicked();

    /** \fn on_receiptDone_clicked()
     * This function is the done function, it will display the main page after click it.
     */
    void on_receiptDone_clicked();

    /** \fn on_receiptDone_clicked()
     * This function is the search function, it will search the college name that is
     * currenly display on the combo box after click it.
     */
    void on_SearchButton_clicked();

private:
    Ui::planTripWindow *ui; /**< planTripWindow UI variable*/
    dbManager m_database;   /**< database manager variable*/
    QVector<QString> selectedCampuses; /**< vector of selected campuses for the tour*/
    QVector<QString> campuseList;   /**< vector of selected campuses for the tour*/
    QQueue<QString> sortedCampuses;   /**< queue of sorted campuses for tour*/
    QStack<Souvenir> souvenirCart;  /**< stack of the purchased souvenirs*/
    int asuNum;     /**< the maximum number of campuses allowed during the ASU tour*/
    int selectNum;  /**< the current number of campuses*/
    QString sQry;   /**< souvenir query - ACCUMULATOR*/
    Souvenir souv; /**< struct of the purchased souvenirs*/
    double total; /**< double of the total price form the purchased souvenirs*/
    double distance; /**< double of the total distance form the tours*/

};

#endif // PLANTRIPWINDOW_H
