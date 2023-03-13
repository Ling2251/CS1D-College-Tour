#ifndef SOUVENIRADDANDEDIT_H
#define SOUVENIRADDANDEDIT_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include "dbmanager.h"
#include "maintenance.h"
#include <string>
using namespace std;

namespace Ui {
class souvenirAddandEdit;
}

class souvenirAddandEdit : public QDialog
{
    Q_OBJECT

public:
    explicit souvenirAddandEdit(QWidget *parent = nullptr);
    ~souvenirAddandEdit();

    void displayCollegeComboBox();


private slots:


    void on_pushButton_clicked();

private:
    Ui::souvenirAddandEdit *ui;

};

#endif // SOUVENIRADDANDEDIT_H
