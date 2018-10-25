#ifndef COURIERLOGIN_H
#define COURIERLOGIN_H

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
class courierlogin;
}

class courierlogin : public QDialog
{
    Q_OBJECT

public:
    explicit courierlogin(QWidget *parent = 0);
    ~courierlogin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::courierlogin *ui;
    QSqlDatabase myDB;
};

#endif // COURIERLOGIN_H
