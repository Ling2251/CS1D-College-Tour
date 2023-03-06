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

using namespace std;
namespace Ui {
class InputCollege;
}

class InputCollege : public QDialog
{
    Q_OBJECT

public:
    explicit InputCollege(QWidget *parent = nullptr);
    ~InputCollege();

    void readFile();    //read file function
    void pushInputData();

private:
    Ui::InputCollege *ui;

};

#endif // INPUTCOLLEGE_H
