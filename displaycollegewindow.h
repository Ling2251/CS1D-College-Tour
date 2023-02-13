#ifndef DISPLAYCOLLEGEWINDOW_H
#define DISPLAYCOLLEGEWINDOW_H

#include <QDialog>

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

private slots:

private:
    Ui::displayCollegeWindow *ui;
};

#endif // DISPLAYCOLLEGEWINDOW_H
