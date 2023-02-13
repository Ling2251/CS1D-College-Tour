#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QDialog>
#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QAxObject> //need ActiveQt

namespace Ui {
class maintenance;
}

class maintenance : public QDialog
{
    Q_OBJECT

public:
    explicit maintenance(QWidget *parent = nullptr);
    ~maintenance();
    void readFile();    //read file function

private:
    Ui::maintenance *ui;
    QPushButton *m_pButton; //IN -- Button to Ask user to input file
    QTextEdit *m_pTextEdit; //IN/OUT -- text edit box
};

#endif // MAINTENANCE_H
