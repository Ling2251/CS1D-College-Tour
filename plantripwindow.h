#ifndef PLANTRIPWINDOW_H
#define PLANTRIPWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "dbmanager.h"

// This class will give the user options on how they would like to plan their trip
namespace Ui {
class planTripWindow;
}

class planTripWindow : public QDialog
{
    Q_OBJECT

public:
    struct Souvenir
    {
        QString souvName; /**< Souvenir name*/
        QString campus; /**< Campus of origin*/
        double cost; /**< Cost of the souvenir */
        int quantity; /**< Number of souvenirs purchased*/
    };

    explicit planTripWindow(QWidget *parent = nullptr);
    ~planTripWindow();

    bool checkCampusVectorNames(QVector<QString> campuses);
    void displayCollegeTripList();
    void recursiveCollegeSort(QString currentCamp);
    void goToSouvenirShop();
    void showSelectCampusComboBox(QStringListModel *model);
    void showSouvTableView(QSqlQueryModel *model);
    void showSouvCartTableView(QSqlQueryModel *model);

private slots:
    void on_planShortTrip_clicked();

    void on_planCustomTrip_clicked();

    void on_startTrip_clicked();

    void on_selectCampus_comboBox_currentIndexChanged();

    void on_addSouvenir_button_clicked();

private:
    Ui::planTripWindow *ui;
    dbManager m_database;
    QVector<QString> selectedCampuses; /**< vector of selected campuses for the tour*/
    QQueue<QString> sortedCampuses;   /**< queue of sorted campuses for tour*/
    QStack<Souvenir> souvenirCart;  /**< stack of the purchased souvenirs*/
    QString sQry;
};

#endif // PLANTRIPWINDOW_H
