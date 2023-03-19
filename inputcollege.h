#ifndef INPUTCOLLEGE_H
#define INPUTCOLLEGE_H

#include <QDialog>
#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QAxObject>
#include <iostream>
#include <QtSql>
#include <QQueue>

using namespace std;

/**
 * @file InputCollege.h
 * @class InputCollege
 * @brief Most functionality of the InputCollege class is to reading
 * in the new college data as a excel file
 */
namespace Ui {
class InputCollege;
}

class InputCollege : public QDialog
{
    Q_OBJECT

public:
    /** \fn InputCollege()
     * constructer function that create a window that display to the the input data
     * page to the administrator for adding new colleges and spuvenirs to the prgram
     * @return nothing, it just display a window to the administrator
     */
    explicit InputCollege(QWidget *parent = nullptr);

    /** \fn ~InputCollege()
     *  A destructor function
     * */
    ~InputCollege();

    /** \fn readFile()
     * This function will take in a excel file as an input file and read all the data
     * off that file into the program
     */
    void readFile();    //read file function

    /** \fn pushInputData()
     * Once this function is called the data that was readed into the prgram will be
     * storded on to a vetor and a database.
     */
    void pushInputData();
    
private slots:
    /** \fn on_goback_clicked()
     * This function is the goback function, it will display the last page after click it.
     */
    void on_goback_clicked();

private:
    Ui::InputCollege *ui;   /**< InputCollege UI variable*/

};

#endif // INPUTCOLLEGE_H
