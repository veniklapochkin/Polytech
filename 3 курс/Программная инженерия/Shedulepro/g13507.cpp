#include "g13507.h"
#include "ui_g13507.h"
#include "institutes.h"
#include "createtask.h"
G13507::G13507(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G13507)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/13507.png");
    ui->label->setPixmap(pix);
}

G13507::~G13507()
{
    delete ui;
}

void G13507::on_pushButton_clicked()
{
    institutes ins;
    ins.setModal(this);
    ins.exec();
}

void G13507::on_pushButton_2_clicked()
{
    createtask task;
    task.setModal(this);
    task.exec();
}
