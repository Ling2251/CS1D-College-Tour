#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QDialog>

// This class is the main page and will offer the user the choice of either planning a trip or to see the colleges that this program offers
namespace Ui {
class userInterface;
}

class userInterface : public QDialog
{
    Q_OBJECT

public:
    explicit userInterface(QWidget *parent = nullptr);
    ~userInterface();

private slots:
    void on_displayCollegeButton_clicked();

    void on_planTripButton_clicked();
    
    void on_mainpage_clicked();

private:
    Ui::userInterface *ui;
};

#endif // USERINTERFACE_H
