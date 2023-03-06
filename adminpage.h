#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>

namespace Ui {
class adminpage;
}

class adminpage : public QDialog
{
    Q_OBJECT

public:
    explicit adminpage(QWidget *parent = nullptr);
    ~adminpage();

signals:
    firstWindow();
    adminWindow();

private slots:
    void on_adminpage_ReturnButton_clicked();

private:
    Ui::adminpage *ui;
};

#endif // ADMINPAGE_H
