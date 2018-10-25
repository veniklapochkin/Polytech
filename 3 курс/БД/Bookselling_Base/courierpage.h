#ifndef COURIERPAGE_H
#define COURIERPAGE_H

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
class courierpage;
}

class courierpage : public QDialog
{
    Q_OBJECT

public:
    explicit courierpage(QWidget *parent = 0);
    ~courierpage();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_doneorder_clicked();

private:
    Ui::courierpage *ui;
    QSqlDatabase myDB;
};

#endif // COURIERPAGE_H
