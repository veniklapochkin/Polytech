#ifndef GROUPS_ICST_H
#define GROUPS_ICST_H

#include <QDialog>

namespace Ui {
class GROUPS_ICST;
}

class GROUPS_ICST : public QDialog
{
    Q_OBJECT

public:
    explicit GROUPS_ICST(QWidget *parent = 0);
    ~GROUPS_ICST();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::GROUPS_ICST *ui;
};

#endif // GROUPS_ICST_H
