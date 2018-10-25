#ifndef ADMINPAGE_H
#define ADMINPAGE_H

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
class adminpage;
}

class adminpage : public QDialog
{
    Q_OBJECT

public:
    explicit adminpage(QWidget *parent = 0);
    ~adminpage();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_chose_currentTextChanged(const QString &arg1);

    void on_pushButton_5_clicked();

private:
    Ui::adminpage *ui;
    QSqlDatabase myDB;
};

#endif // ADMINPAGE_H
