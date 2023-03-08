/**********************************************************/
#include "displaycollegewindow.h"
#include "ui_displaycollegewindow.h"
/**********************************************************/

/**********************************************************
*
* displayCollegeWindow
*_________________________________________________________
*This page will display all the colleges offered by the
*program as well as their traditional souvenirs.
*_________________________________________________________
***********************************************************/
displayCollegeWindow::displayCollegeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::displayCollegeWindow)
{
        ui->setupUi(this);
}

//
displayCollegeWindow::~displayCollegeWindow()
{
    delete ui;
}

/*
 * showDBView(QSqlQueryModel *model)
 * The table view for the campus database display UI will display the information held in a QSqlQueryModel pointer.
 * IN: QSqlQueryModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void displayCollegeWindow::showDBView(QSqlQueryModel *model)
{
    ui->tableView->setModel(model);
}

/*
 * showCampusDBCombo(QSqlQueryModel *model)
 * The campus combo box for the campus database display UI will display the information held in a QSqlQueryModel pointer.
 * IN: QSqlQueryModel, model (passed as a pointer)
 * OUT: nothing returned
 */
void displayCollegeWindow::showCampusDBCombo(QSqlQueryModel *model)
{
    ui->campus_combo->setModel(model);
}

/*
 * on_other_button_clicked
 * When the other campuses button is clicked on the database display UI, the Distance database is displayed on the table view.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void displayCollegeWindow::on_other_button_clicked()
{
    ui->database_label->setText(ui->campus_combo->currentText());
    showDBView(m_database.loadOtherCampusAndDist(ui->campus_combo->currentText()));
    ui->tableView->setColumnWidth(0, 450);
    ui->tableView->setColumnWidth(1, 280);
}

/*
 * on_souv_button_clicked
 * When the souvenir button is clicked on the database display UI, the souvenir database for a specificed campus is displayed on the table view.
 * IN: no formal parameters
 * OUT: nothing returned
 */
void displayCollegeWindow::on_souv_button_clicked()
{
    ui->database_label->setText(ui->campus_combo->currentText());
    showDBView(m_database.loadCampusSouvenirs(ui->campus_combo->currentText()));
    ui->tableView->setColumnWidth(0, 460);
    ui->tableView->setColumnWidth(1, 280);
}


