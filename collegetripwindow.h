#ifndef COLLEGETRIPWINDOW_H
#define COLLEGETRIPWINDOW_H

#include <QDialog>

namespace Ui {
class collegetripwindow;
}

class collegetripwindow : public QDialog
{
    Q_OBJECT

public:
    explicit collegetripwindow(QWidget *parent = nullptr);
    ~collegetripwindow();

signals:
    void receiptPage();

private slots:
    void on_collegetrip_NextCollegeButton_clicked();

private:
    Ui::collegetripwindow *ui;
};

#endif // COLLEGETRIPWINDOW_H
