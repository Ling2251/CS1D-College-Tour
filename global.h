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


/**
 * @file global.h
 * @class global
 * @brief Most functionality of the global file is to created a global struct for
 * storing the new input data of college information.


/** \struct InputCollegeList
 * Struct for the information about a new college data.
 */
struct InputCollegeList{
    string startingCollege; /**< starting college name*/
    string endingCollege;   /**< ending college name*/
    double distance;        /**< the distance between starting college and ending college*/
};

vector<InputCollegeList> CollegeList; /**< global vetor variable used for stord in the new college data */  //

#endif // GLOBAL_H
