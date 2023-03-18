#ifndef DISPLAYCOLLEGEWINDOW_H
#define DISPLAYCOLLEGEWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "dbmanager.h"

/**
 * @file displayCollegeWindow.h
 * @class displayCollegeWindow
 * @brief Most functionality of the displayCollegeWindow class is show the initial college
 * list in the from of a sql database.
 */
namespace Ui {
class displayCollegeWindow;
}

class displayCollegeWindow : public QDialog
{
    Q_OBJECT

public:
    /** \fn displayCollegeWindow()
     * constructer function that create a display window.
     * @return nothing, it just display the tabel view to the students
     */
    explicit displayCollegeWindow(QWidget *parent = nullptr);

    /** \fn ~displayCollegeWindow()
     *  A destructor function
     * */
    ~displayCollegeWindow();

    /** \fn showDBView(QSqlQueryModel *model)
     * The table view for the campus database display UI will display the information held in a QSqlQueryModel pointer.
     * @param QSqlQueryModel, model (passed as a pointer) for displaying the database list in a table view
     * @return nothing returned
     */
    void showDBView(QSqlQueryModel *model);

    /** \fn showCampusDBCombo(QSqlQueryModel *model)
     * The campus combo box for the campus database display UI will display the information held in a QSqlQueryModel pointer.
     * @param QSqlQueryModel, model (passed as a pointer) for displaying the database list in the combo box
     * @return nothing returned
     */
    void showCampusDBCombo(QSqlQueryModel *model);

private slots:
        /** \fn on_other_button_clicked
         * When the other campuses button is clicked on the database display UI, the Distance database is displayed on the table view.
         */
        void on_other_button_clicked();

        /** \fn on_souv_button_clicked
         * When the souvenir button is clicked on the database display UI, the souvenir database for a specificed campus is displayed on the table view.
         */
        void on_souv_button_clicked();

private:
    Ui::displayCollegeWindow *ui;   /**< displayCollegeWindow UI variable*/
    dbManager m_database;   /**< database manager variable*/
};

#endif // DISPLAYCOLLEGEWINDOW_H
