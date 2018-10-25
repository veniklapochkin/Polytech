#include "groups_ibi.h"
#include "ui_groups_ibi.h"
#include "g13101.h"
#include "g23101.h"
#include "g33101.h"
#include "g43101.h"
#include "g53101.h"
#include "g63101.h"
Groups_IBI::Groups_IBI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Groups_IBI)
{
    ui->setupUi(this);
}

Groups_IBI::~Groups_IBI()
{
    delete ui;
}

void Groups_IBI::on_pushButton_clicked()
{
    G13101 g13101;
    g13101.setModal(this);
    g13101.exec();
}

void Groups_IBI::on_pushButton_2_clicked()
{
    G23101 g23101;
    g23101.setModal(this);
    g23101.exec();
}

void Groups_IBI::on_pushButton_3_clicked()
{
    G33101 g33101;
    g33101.setModal(this);
    g33101.exec();
}

void Groups_IBI::on_pushButton_4_clicked()
{
    G43101 g43101;
    g43101.setModal(this);
    g43101.exec();
}

void Groups_IBI::on_pushButton_5_clicked()
{
    G53101 g53101;
    g53101.setModal(this);
    g53101.exec();
}

void Groups_IBI::on_pushButton_6_clicked()
{
    G63101 g63101;
    g63101.setModal(this);
    g63101.exec();
}
