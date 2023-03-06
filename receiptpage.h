#ifndef RECEIPTPAGE_H
#define RECEIPTPAGE_H

#include <QDialog>

namespace Ui {
class receiptpage;
}

class receiptpage : public QDialog
{
    Q_OBJECT

public:
    explicit receiptpage(QWidget *parent = nullptr);
    ~receiptpage();

signals:
    void firstWindow();

private slots:
    void on_receiptpage_FinishButton_clicked();

private:
    Ui::receiptpage *ui;
};

#endif // RECEIPTPAGE_H
