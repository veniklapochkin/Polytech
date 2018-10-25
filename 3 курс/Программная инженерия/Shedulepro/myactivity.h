#ifndef MYACTIVITY
#define MYACTIVITY
#include <QDialog>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <iostream>
#include "studentloginform.h"
namespace Ui {
class myactivity;
}

class myactivity : public QDialog
{
    Q_OBJECT

public:
    studentLoginForm slf;
    explicit myactivity(QWidget *parent = 0);
    ~myactivity();

private slots:

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::myactivity *ui;

};

#endif // MYACTIVITY

