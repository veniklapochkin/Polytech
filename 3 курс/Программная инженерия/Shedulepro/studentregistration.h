#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H

#include <QDialog>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <iostream>
#include "studentloginform.h"
namespace Ui {
class studentregistration;
}

class studentregistration : public QDialog
{
    Q_OBJECT

public:
    studentLoginForm slf;
    explicit studentregistration(QWidget *parent = 0);
    ~studentregistration();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::studentregistration *ui;
};

#endif // STUDENTREGISTRATION_H
