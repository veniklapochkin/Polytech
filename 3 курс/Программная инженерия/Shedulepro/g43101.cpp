#include "g43101.h"
#include "ui_g43101.h"
#include "institutes.h"
#include "createtask.h"
G43101::G43101(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G43101)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/43101.png");
    ui->label->setPixmap(pix);
}

G43101::~G43101()
{
    delete ui;
}

void G43101::on_pushButton_clicked()
{
    institutes ins;
    ins.setModal(this);
    ins.exec();
}

void G43101::on_pushButton_2_clicked()
{
    createtask task;
    task.setModal(this);
    task.exec();
}
