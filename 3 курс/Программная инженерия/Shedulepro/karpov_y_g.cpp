#include "karpov_y_g.h"
#include "ui_karpov_y_g.h"
#include "myactivity.h"
#include "createactivity.h"
karpov_y_g::karpov_y_g(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::karpov_y_g)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/karpov_y_g.png");
    ui->label->setPixmap(pix);
}

karpov_y_g::~karpov_y_g()
{
    delete ui;
}

void karpov_y_g::on_pushButton_clicked()
{
    createactivity activity;
    activity.setModal(this);
    activity.exec();
}

void karpov_y_g::on_pushButton_2_clicked()
{
    myactivity mact;
    mact.setModal(this);
    mact.exec();
}
