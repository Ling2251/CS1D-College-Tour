#ifndef PLANTRIPWINDOW_H
#define PLANTRIPWINDOW_H

#include <QDialog>

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

signals:
    void firstWindow();
    void collegeWindow();

private slots:
    void on_planShortTrip_clicked();

    void on_planCustomTrip_clicked();

    void on_startTrip_clicked();

    void on_plantrip_ReturnButton_clicked();

    void on_plantrip_SaddlebackButton_clicked();

    void on_plantrip_ArizonaStateButton_clicked();

    void on_plantrip_CustomCollegeButton_clicked();

private:
    Ui::planTripWindow *ui;
};

#endif // PLANTRIPWINDOW_H
