#ifndef MAKEORDER_H
#define MAKEORDER_H

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
class makeorder;
}

class makeorder : public QDialog
{
    Q_OBJECT

public:
    explicit makeorder(QWidget *parent = 0);
    ~makeorder();

private slots:
    void on_pushButton_clicked();


    void on_product_currentTextChanged(const QString &arg1);

private:
    Ui::makeorder *ui;
    QSqlDatabase myDB;
};

#endif // MAKEORDER_H
