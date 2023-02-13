/**********************************************************/
#include "maintenance.h"
#include "ui_maintenance.h"
/**********************************************************/

/**********************************************************
*
* maintenance
*_________________________________________________________
*This page will require a login to be used. However, it will
*allow the user to edit the colleges as well as the ability
*to edit the souvenirs for each college.
*_________________________________________________________
***********************************************************/

maintenance::maintenance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::maintenance)
{
    ui->setupUi(this);
    m_pButton = new QPushButton("Choose a file to upload", this);
    m_pTextEdit = new QTextEdit(this);

    m_pButton->setGeometry(QRect(QPoint(50, 50), QSize(180, 50)));
    m_pTextEdit->setGeometry(QRect(QPoint(50, 125), QSize(650, 400)));

    connect(m_pButton, &QPushButton::clicked, this, &maintenance::readFile);
}

maintenance::~maintenance()
{
    delete ui;
}

/******************************************************
****
*
* void maintenance::readFile()
*
_______________________________________________________

* This function let user read an excel file(third sheet by default)
* by clicking the button and print all the datas to a text edit box.
* Every data on a row is sepearted by a tab "\t" key.
*
* Receives nothing -- return nothing
_______________________________________________________

* PRE-CONDITIONS
*   QPushButton *m_pButton; QTextEdit *m_pTextEdit;
* POST-CONDITIONS
*     This function prints the data on the text edit
*     box, each data are seprarted by a tab key on each
*     row. It will also change the button color to green
*     if it already reads the file.
*******************************************************/
void maintenance::readFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Excel Files (*.xlsx);;All Files (*)"));

    if (!fileName.isEmpty()) {

        QAxObject *excel = new QAxObject("Excel.Application", this);
        excel->setProperty("Visible", false);

        QAxObject *workbooks = excel->querySubObject("Workbooks");
        QAxObject *workbook = workbooks->querySubObject("Open(const QString&)", fileName);

        QAxObject *worksheet = workbook->querySubObject("Sheets(int)", 3);
        QAxObject *usedRange = worksheet->querySubObject("UsedRange");

        QVariant allData = usedRange->dynamicCall("Value");
        QVariantList data = allData.toList();

        QString text;
        for (int i = 0; i < data.size(); i++) {
            QVariantList row = data[i].toList();
                for (int j = 0; j < row.size(); j++) {
                    text += row[j].toString() + "\t";
                    }
                text += "\n";
        }

        m_pTextEdit->setPlainText(text);
        workbook->dynamicCall("Close()");
        excel->dynamicCall("Quit()");

        QPalette pal = m_pButton->palette();
        pal.setColor(QPalette::Button, QColor(Qt::green));
        m_pButton->setAutoFillBackground(true);
        m_pButton->setPalette(pal);
        m_pButton->update();
    }
}

