#ifndef CREATETASK_H
#define CREATETASK_H
#include <QDialog>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <iostream>
#include "studentloginform.h"
namespace Ui {
class createtask;
}

class createtask : public QDialog
{
    Q_OBJECT

public:
    studentLoginForm slf;
    explicit createtask(QWidget *parent = 0);
    ~createtask();

private slots:
    void on_pushButton_clicked();

private:
    Ui::createtask *ui;
};

#endif // CREATETASK_H
