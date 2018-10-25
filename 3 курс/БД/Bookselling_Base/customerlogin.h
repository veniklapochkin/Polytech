#ifndef CUSTOMERLOGIN_H
#define CUSTOMERLOGIN_H

#include <QDialog>
#include <QCloseEvent>
#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <iostream>

namespace Ui {
class customerlogin;
}

class customerlogin : public QDialog
{
    Q_OBJECT

public:
    explicit customerlogin(QWidget *parent = 0);
    ~customerlogin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::customerlogin *ui;
    QSqlDatabase myDB;
};

#endif // CUSTOMERLOGIN_H
