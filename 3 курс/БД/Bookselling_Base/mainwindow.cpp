#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customerlogin.h"
#include "courierlogin.h"
#include "adminlogin.h"
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
    customerlogin clogin;
    clogin.setModal(true);
    clogin.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    courierlogin coulogin;
    coulogin.setModal(true);
    coulogin.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    adminlogin alogin;
    alogin.setModal(true);
    alogin.exec();
}
