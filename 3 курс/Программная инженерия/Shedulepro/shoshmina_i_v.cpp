#include "shoshmina_i_v.h"
#include "ui_shoshmina_i_v.h"
#include "myactivity.h"
#include "createactivity.h"
shoshmina_i_v::shoshmina_i_v(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shoshmina_i_v)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/shoshmina_i_v.png");
    ui->label->setPixmap(pix);
}

shoshmina_i_v::~shoshmina_i_v()
{
    delete ui;
}

void shoshmina_i_v::on_pushButton_clicked()
{
    createactivity activity;
    activity.setModal(this);
    activity.exec();
}

void shoshmina_i_v::on_pushButton_2_clicked()
{
    myactivity mact;
    mact.setModal(this);
    mact.exec();
}
