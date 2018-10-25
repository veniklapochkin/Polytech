#ifndef CREATEACTIVITY_H
#define CREATEACTIVITY_H

#include <QDialog>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <iostream>
#include "studentloginform.h"
namespace Ui {
class createactivity;
}

class createactivity : public QDialog
{
    Q_OBJECT

public:
    studentLoginForm slf;
    explicit createactivity(QWidget *parent = 0);
    ~createactivity();

private slots:
    void on_pushButton_clicked();

private:
    Ui::createactivity *ui;
};

#endif // CREATEACTIVITY_H
