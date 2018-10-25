#include "g33101.h"
#include "ui_g33101.h"
#include "institutes.h"
#include "createtask.h"
G33101::G33101(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G33101)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/33101.png");
    ui->label->setPixmap(pix);
}

G33101::~G33101()
{
    delete ui;
}

void G33101::on_pushButton_clicked()
{
    institutes ins;
    ins.setModal(this);
    ins.exec();
}

void G33101::on_pushButton_2_clicked()
{
    createtask task;
    task.setModal(this);
    task.exec();
}
