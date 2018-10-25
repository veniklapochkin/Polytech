#include "g63101.h"
#include "ui_g63101.h"
#include "institutes.h"
#include "createtask.h"
G63101::G63101(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G63101)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/63101.png");
    ui->label->setPixmap(pix);
}

G63101::~G63101()
{
    delete ui;
}

void G63101::on_pushButton_clicked()
{
    institutes ins;
    ins.setModal(this);
    ins.exec();
}

void G63101::on_pushButton_2_clicked()
{
    createtask task;
    task.setModal(this);
    task.exec();
}
