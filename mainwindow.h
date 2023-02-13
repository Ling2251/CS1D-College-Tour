#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adminpage.h"
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include"dbmanager.h"


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

private:
    Ui::MainWindow *ui;
    adminpage *adminPage;
};
#endif // MAINWINDOW_H
