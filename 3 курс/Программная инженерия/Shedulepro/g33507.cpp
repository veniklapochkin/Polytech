#include "g33507.h"
#include "ui_g33507.h"
#include "institutes.h"
#include "mytask.h"
#include "createtask.h"
G33507::G33507(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G33507)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/33507.png");
    ui->label->setPixmap(pix);
}

G33507::~G33507()
{
    delete ui;
}

void G33507::on_pushButton_clicked()
{
    institutes ins;
    ins.setModal(this);
    ins.exec();
}

void G33507::on_pushButton_2_clicked()
{
    createtask task;
    task.setModal(this);
    task.exec();
}

void G33507::on_pushButton_3_clicked()
{
    mytask mt;
    mt.setModal(this);
    mt.exec();
}
