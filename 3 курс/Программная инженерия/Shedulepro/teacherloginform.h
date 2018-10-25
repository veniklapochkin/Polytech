#ifndef TEACHERLOGINFORM_H
#define TEACHERLOGINFORM_H

#include <QDialog>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include "studentloginform.h"
namespace Ui {
class teacherloginform;
}

class teacherloginform : public QDialog
{
    Q_OBJECT

public:
    studentLoginForm slf;
    explicit teacherloginform(QWidget *parent = 0);
    ~teacherloginform();

private slots:
    void on_btnOk_clicked();

    void on_btnCancel_clicked();

    void on_btnClear_clicked();


    void on_btnRegistration_clicked();

private:
    Ui::teacherloginform *ui;

};

#endif // TEACHERLOGINFORM_H
