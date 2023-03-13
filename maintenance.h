#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QDialog>
#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QAxObject> //need ActiveQt
#include "souveniraddandedit.h"

namespace Ui {
class maintenance;
}

class maintenance : public QDialog
{
    Q_OBJECT

public:
    explicit maintenance(QWidget *parent = nullptr);
    ~maintenance();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::maintenance *ui;

};

#endif // MAINTENANCE_H
