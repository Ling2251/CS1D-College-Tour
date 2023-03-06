#ifndef GLOBAL_H
#define GLOBAL_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QAxObject>
#include <iostream>
#include <vector>
using namespace std;

struct InputCollegeList{
    string startingCollege;
    string endingCollege;
    double distance;
};

vector<InputCollegeList> CollegeList;    //global variable

#endif // GLOBAL_H
