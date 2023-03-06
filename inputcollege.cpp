#include "inputcollege.h"
#include "ui_inputcollege.h"
#include "global.h"

InputCollege::InputCollege(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputCollege)
{
    ui->setupUi(this);
    connect(ui->InputFile,&QPushButton::clicked,this,&InputCollege::readFile);
    connect(ui->submitButton,&QPushButton::clicked,this,&InputCollege::pushInputData);
}

InputCollege::~InputCollege()
{
    delete ui;
}

/******************************************************
****
*
* void MainWindow::readFile()
*
_______________________________________________________

* This function let user read an excel file(third sheet by default)
* by clicking the button and print all the datas to a table widget.
*
* Receives nothing -- return nothing
_______________________________________________________

* PRE-CONDITIONS
*   ui
* POST-CONDITIONS
*     This function prints the data on the table widget
*     It will also change the button color to green
*     if it already reads the file.
*******************************************************/
void InputCollege::readFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Excel Files (*.xlsx);;All Files (*)"));

    if (!fileName.isEmpty()) {

        QAxObject* excel = new QAxObject("Excel.Application");
        QAxObject* workbooks = excel->querySubObject("Workbooks");
        QAxObject* workbook = workbooks->querySubObject("Open(const QString&)", fileName);
        QAxObject* worksheet = workbook->querySubObject("Worksheets(int)", 3);

        QAxObject* used_range = worksheet->querySubObject("UsedRange");



        for (int row = 1; row <= 47; row++) {
            QAxObject* cell1 = used_range->querySubObject("Cells(int,int)", row+1, 1);
            QString string1 = cell1->dynamicCall("Value()").toString();
            QTableWidgetItem* item1 = new QTableWidgetItem(string1);
            ui->tableWidget->setItem(row-1, 0, item1);
            delete cell1;

            QAxObject* cell2 = used_range->querySubObject("Cells(int,int)", row+1, 2);
            QString string2 = cell2->dynamicCall("Value()").toString();
            QTableWidgetItem* item2 = new QTableWidgetItem(string2);
            ui->tableWidget->setItem(row-1, 1, item2);
            delete cell2;

            QAxObject* cell3 = used_range->querySubObject("Cells(int,int)", row+1, 3);
            double number = cell3->dynamicCall("Value()").toDouble();
            QTableWidgetItem* item3 = new QTableWidgetItem(QString::number(number));
            ui->tableWidget->setItem(row-1, 2, item3);
            delete cell3;
        }

        delete used_range;
        delete worksheet;
        delete workbook;
        delete workbooks;
        delete excel;

        QPalette pal = ui->InputFile->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        ui->InputFile->setAutoFillBackground(true);
        ui->InputFile->setPalette(pal);
        ui->InputFile->update();
    }
}


void InputCollege::pushInputData()
{
    for (int row = 0; row < ui->tableWidget->rowCount(); row++){
        //corner case
        QTableWidgetItem* item = ui->tableWidget->item(row,0);
        if (!item || item->text().isEmpty())
        {
           break;
        }

        QString string1 = ui->tableWidget->item(row,0)->text();
        QString string2 = ui->tableWidget->item(row, 1)->text();
        double distance = ui->tableWidget->item(row, 2)->text().toDouble();


        string start = string1.toStdString();
        string end = string2.toStdString();


        InputCollegeList college = {start,end,distance};
        CollegeList.push_back(college);
    }
    ui->tableWidget->clearContents();

    for (auto & i : CollegeList){   //iterate through all objects in the vector
        string startingCollege = i.startingCollege; //access starting college
        string endingCollege = i.endingCollege;     //access ending college
        double distanceBetween = i.distance;        //access distance between two colleges
        cout<<startingCollege<<"\t"<<endingCollege<<"\t"<<distanceBetween<<endl;    //print all the data out in the console
        }

    QPalette pal = ui->submitButton->palette();
    pal.setColor(QPalette::Button, QColor(Qt::green));
    ui->submitButton->setAutoFillBackground(true);
    ui->submitButton->setPalette(pal);
    ui->submitButton->update();
}

