#ifndef EDITCOLLEGESPAGE_H
#define EDITCOLLEGESPAGE_H

#include <QDialog>

namespace Ui {
class editcollegespage;
}

class editcollegespage : public QDialog
{
    Q_OBJECT

public:
    explicit editcollegespage(QWidget *parent = nullptr);
    ~editcollegespage();

private:
    Ui::editcollegespage *ui;
};

#endif // EDITCOLLEGESPAGE_H
