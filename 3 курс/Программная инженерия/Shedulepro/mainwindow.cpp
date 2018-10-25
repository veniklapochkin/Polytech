#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "studentloginform.h"
#include "teacherloginform.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    studentLoginForm std;
    std.setModal(this);
    std.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    teacherloginform tch;
    tch.setModal(this);
    tch.exec();
}
