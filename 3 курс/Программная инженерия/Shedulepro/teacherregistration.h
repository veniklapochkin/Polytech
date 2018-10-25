#ifndef TEACHERREGISTRATION_H
#define TEACHERREGISTRATION_H

#include <QDialog>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <iostream>
#include "studentloginform.h"
namespace Ui {
class teacherregistration;
}

class teacherregistration : public QDialog
{
    Q_OBJECT

public:
    studentLoginForm slf;
    explicit teacherregistration(QWidget *parent = 0);
    ~teacherregistration();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::teacherregistration *ui;

};

#endif // TEACHERREGISTRATION_H
