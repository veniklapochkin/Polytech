#ifndef MYTASK_H
#define MYTASK_H

#include <QDialog>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <iostream>
#include "studentloginform.h"
namespace Ui {
class mytask;
}

class mytask : public QDialog
{
    Q_OBJECT

public:
    studentLoginForm slf;
    explicit mytask(QWidget *parent = 0);
    ~mytask();

private:
    Ui::mytask *ui;
};

#endif // MYTASK_H
