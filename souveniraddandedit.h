#ifndef SOUVENIRADDANDEDIT_H
#define SOUVENIRADDANDEDIT_H

#include <QDialog>
#include <QtSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <string>
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

    void displayItemComBox();

private slots:


    void on_pushButton_clicked();

    void on_update_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_addButton_clicked();

    void on_deleteButton_clicked();
    
    void on_goback_clicked();

private:
    Ui::souvenirAddandEdit *ui;

    bool addOrDelet;
};

#endif // SOUVENIRADDANDEDIT_H
