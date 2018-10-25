#include "g63507.h"
#include "ui_g63507.h"
#include "institutes.h"
#include "createtask.h"
G63507::G63507(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G63507)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/63507.png");
    ui->label->setPixmap(pix);
}

G63507::~G63507()
{
    delete ui;
}

void G63507::on_pushButton_2_clicked()
{
    institutes ins;
    ins.setModal(this);
    ins.exec();
}

void G63507::on_pushButton_clicked()
{
    createtask task;
    task.setModal(this);
    task.exec();
}
