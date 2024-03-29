#ifndef SOUVENIRADDANDEDIT_H
#define SOUVENIRADDANDEDIT_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <string>
#include "dbmanager.h"
#include "maintenance.h"
#include <string>
using namespace std;

/**
 * @file souvenirAddandEdit.h
 * @class souvenirAddandEdit
 * @brief Most functionality of the souvenirAddandEdit class is to add or deleted
 *  a souvenirs and also edit the price of an exist souvenir
 */
namespace Ui {
class souvenirAddandEdit;
}

class souvenirAddandEdit : public QDialog
{
    Q_OBJECT

public:

    /** \fn souvenirAddandEdit()
     * constructer function that create a window that display to the the souvenirs table
     * page to the administrator for adding or deleying or editting the price of spuvenirs to the prgram
     * @return nothing, it just display a window to the administrator
     */
    explicit souvenirAddandEdit(QWidget *parent = nullptr);

    /** \fn ~souvenirAddandEdit()
     *  A destructor function
     * */
    ~souvenirAddandEdit();


    /** \fn displayCollegeComboBox()
     * This function is to display all the college in a list by once a time.
     */
    void displayCollegeComboBox();


    /** \fn displayItemComBox()
     * This function is to display all the souvenirs of all colleges in a list.
     */
    void displayItemComBox();

private slots:

    /** \fn on_pushButton_clicked()
     * This function is the pushbutton to load the database into the tableview.
     */
    void on_pushButton_clicked();

    /** \fn on_update_clicked()
     * This function is to update the database.
     */
    void on_update_clicked();

    /** \fn on_tableView_activated()
     * This function is to make tableview active so it can be associate with the QString line.
     */
    void on_tableView_activated(const QModelIndex &index);

    /** \fn on_addButton_clicked()
     * This function is to add a new souvenir in to the selected college.
     */
    void on_addButton_clicked();

    /** \fn on_deleteButton_clicked()
     * This function is to delete the souvenir and its price from the college selected.
     */
    void on_deleteButton_clicked();
    
    /** \fn on_goback_clicked()
     * This function is the goback function, it will display the last page after click it.
     */
    void on_goback_clicked();

private:
    Ui::souvenirAddandEdit *ui; /**< souvenirAddandEdit UI variable*/

    bool addOrDelet; /**< the boolean variable to store the logic*/
};

#endif // SOUVENIRADDANDEDIT_H
