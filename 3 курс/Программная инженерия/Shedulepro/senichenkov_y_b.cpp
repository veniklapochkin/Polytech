#include "senichenkov_y_b.h"
#include "ui_senichenkov_y_b.h"
#include "myactivity.h"
#include "createactivity.h"
senichenkov_y_b::senichenkov_y_b(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::senichenkov_y_b)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/senichenkov_y_b.png");
    ui->label->setPixmap(pix);
}

senichenkov_y_b::~senichenkov_y_b()
{
    delete ui;
}

void senichenkov_y_b::on_pushButton_clicked()
{
    createactivity activity;
    activity.setModal(this);
    activity.exec();
}

void senichenkov_y_b::on_pushButton_2_clicked()
{
    myactivity mact;
    mact.setModal(this);
    mact.exec();
}
