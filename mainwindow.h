#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adminpage.h"
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include"dbmanager.h"

#include "loginpage.h"
#include "plantripwindow.h"
#include "adminpage.h"
#include "collegetripwindow.h"
#include "receiptpage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_startCollegeTour_clicked();

    void on_Maintenance_clicked();

    void on_mainwindow_StartTourButton_clicked();

    void on_mainwindow_MaintenanceButton_clicked();

private:
    Ui::MainWindow *ui;
    adminpage *adminPage;

    loginpage *Login;
    adminpage *Admin;
    planTripWindow *PlanTrip;
    collegetripwindow *CollegeWin;
    receiptpage *Receipt;
};
#endif // MAINWINDOW_H
