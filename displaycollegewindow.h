#ifndef DISPLAYCOLLEGEWINDOW_H
#define DISPLAYCOLLEGEWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "dbmanager.h"

// This class will display colleges from a file
namespace Ui {
class displayCollegeWindow;
}

class displayCollegeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit displayCollegeWindow(QWidget *parent = nullptr);
    ~displayCollegeWindow();
    void showDBView(QSqlQueryModel *model);
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
    Ui::displayCollegeWindow *ui;
    dbManager m_database;
};

#endif // DISPLAYCOLLEGEWINDOW_H
