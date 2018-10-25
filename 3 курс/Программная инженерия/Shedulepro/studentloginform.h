#ifndef STUDENTLOGINFORM_H
#define STUDENTLOGINFORM_H

#include <QDialog>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <iostream>
#define Path_to_DB "/home/venik_lapochkin/Документы/Qt projects/Shedulepro/DB"
namespace Ui {
class studentLoginForm;
}

class studentLoginForm : public QDialog
{
    Q_OBJECT
public:
    QSqlDatabase myDB;
    void connClose(){
        myDB.close();
        myDB.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen(){
        myDB = QSqlDatabase::addDatabase("QSQLITE");
        myDB.setDatabaseName(Path_to_DB);
        if(myDB.open()){
            qDebug()<<"Connected to DB";
            return true;
        }
        else{
            qDebug()<<" Not Connected to DB";
            return false;
        }
    }
public:
    explicit studentLoginForm(QWidget *parent = 0);
    ~studentLoginForm();

private slots:
    void on_btnOk_clicked();

    void on_btnClear_clicked();

    void on_btnCancel_clicked();


    void on_btnRegistration_clicked();

private:
    Ui::studentLoginForm *ui;
    };

#endif // STUDENTLOGINFORM_H
