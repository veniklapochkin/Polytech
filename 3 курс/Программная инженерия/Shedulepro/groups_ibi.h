#ifndef GROUPS_IBI_H
#define GROUPS_IBI_H

#include <QDialog>

namespace Ui {
class Groups_IBI;
}

class Groups_IBI : public QDialog
{
    Q_OBJECT

public:
    explicit Groups_IBI(QWidget *parent = 0);
    ~Groups_IBI();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Groups_IBI *ui;
};

#endif // GROUPS_IBI_H
