#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QDialog>

/**
 * @file userInterface.h
 * @class userInterface
 * @brief Most functionality of the userInterface class
 * is the main page and will offer the user the choice of either planning a
 * trip or to see the colleges that this program offers
 */
namespace Ui {
class userInterface;
}

class userInterface : public QDialog
{
    Q_OBJECT

public:
    /** \fn userInterface()
     * constructer function that create a window that display to the the main page
     * and will offer the user the choice of either planning a
     * trip or to see the colleges that this program offers
     * @return nothing, it just display a window to the student
     */
    explicit userInterface(QWidget *parent = nullptr);

    /** \fn ~userInterface()
     *  A destructor function
     * */
    ~userInterface();

private slots:
    /** \fn on_displayCollegeButton_clicked()
     * This function is the go to display college page function, it will display the differnt colleges and
     * their souvenirs of student's choioc after click it.
     */
    void on_displayCollegeButton_clicked();

    /** \fn on_planTripButton_clicked()
     * This function is the go to plan trips page function, it will display the differnt trip page after click it.
     */
    void on_planTripButton_clicked();
    
    /** \fn on_mainpage_clicked()
     * This function is the go to main page function, it will display the main page after click it.
     */
    void on_mainpage_clicked();

private:
    Ui::userInterface *ui;  /**< userInterface UI variable*/
};

#endif // USERINTERFACE_H
