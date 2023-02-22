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
    explicit planTripWindow(QWidget *parent = nullptr);
    ~planTripWindow();

private slots:
    void on_planShortTrip_clicked();

    void on_planCustomTrip_clicked();

    void on_startTrip_clicked();
    bool checkCampusVectorNames(QVector<QString> campuses);
    void recursiveCollegeSort(QString currentCamp);

private:
    Ui::planTripWindow *ui;
    dbManager m_database;

    QVector<QString> selectedCampuses; /**< vector of selected campuses for the tour*/
    QQueue<QString> sortedCampuses;   /**< queue of sorted campuses for tour*/
};

#endif // PLANTRIPWINDOW_H
