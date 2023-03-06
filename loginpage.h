#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>

namespace Ui {
class loginpage;
}

class loginpage : public QDialog
{
    Q_OBJECT

public:
    explicit loginpage(QWidget *parent = nullptr);
    ~loginpage();

signals:
    void firstWindow();
    void adminWindow();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::loginpage *ui;
};

#endif // LOGINPAGE_H
