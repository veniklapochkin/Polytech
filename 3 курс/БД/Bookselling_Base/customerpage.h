#ifndef CUSTOMERPAGE_H
#define CUSTOMERPAGE_H

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
class customerpage;
}

class customerpage : public QDialog
{
    Q_OBJECT

public:
    explicit customerpage(QWidget *parent = 0);
    ~customerpage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::customerpage *ui;
    QSqlDatabase myDB;
};

#endif // CUSTOMERPAGE_H
