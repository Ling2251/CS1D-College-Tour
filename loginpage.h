#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>

/**
 * @file loginpage.h
 * @class loginpage
 * @brief Most functionality of the loginpage class is to created a login page
 * for the administrator to gain access to the maintenace
 */
namespace Ui {
class loginpage;
}

class loginpage : public QDialog
{
    Q_OBJECT

public:
    /** \fn loginpage()
     * constructer function that create a window that display the login
     * page to the administrator for access to the maintenace page
     * @return nothing, it just display a window to the administrator
     */
    explicit loginpage(QWidget *parent = nullptr);

    /** \fn ~loginpage()
     *  A destructor function
     * */
    ~loginpage();

private slots:
    /** \fn on_pushButton_login_clicked()
     * This function will check if the administrator has put in the right userID and password
     * @return nothing, it just allow the administrator login
     */
    void on_pushButton_login_clicked();

private:
    Ui::loginpage *ui;  /**< loginpage UI variable*/
};

#endif // LOGINPAGE_H
