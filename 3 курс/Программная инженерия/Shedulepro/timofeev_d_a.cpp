#include "timofeev_d_a.h"
#include "ui_timofeev_d_a.h"
#include "myactivity.h"
#include "createactivity.h"
timofeev_d_a::timofeev_d_a(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::timofeev_d_a)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/timofeev_d_a.png");
    ui->label->setPixmap(pix);
}

timofeev_d_a::~timofeev_d_a()
{
    delete ui;
}

void timofeev_d_a::on_pushButton_clicked()
{
    createactivity activity;
    activity.setModal(this);
    activity.exec();
}

void timofeev_d_a::on_pushButton_2_clicked()
{
    myactivity mact;
    mact.setModal(this);
    mact.exec();
}
