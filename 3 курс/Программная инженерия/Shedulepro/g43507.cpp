#include "g43507.h"
#include "ui_g43507.h"
#include "institutes.h"
#include "createtask.h"
G43507::G43507(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G43507)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/43507.png");
    ui->label->setPixmap(pix);
}

G43507::~G43507()
{
    delete ui;
}

void G43507::on_pushButton_clicked()
{
    institutes ins;
    ins.setModal(this);
    ins.exec();
}

void G43507::on_pushButton_2_clicked()
{
    createtask task;
    task.setModal(this);
    task.exec();
}
