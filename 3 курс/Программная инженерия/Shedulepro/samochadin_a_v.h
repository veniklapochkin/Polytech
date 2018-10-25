#ifndef SAMOCHADIN_A_V_H
#define SAMOCHADIN_A_V_H

#include <QDialog>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <iostream>

namespace Ui {
class samochadin_a_v;
}

class samochadin_a_v : public QDialog
{
    Q_OBJECT

public:
    explicit samochadin_a_v(QWidget *parent = 0);
    ~samochadin_a_v();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::samochadin_a_v *ui;
    QSqlDatabase myDB;
};

#endif // SAMOCHADIN_A_V_H
