#include "g13101.h"
#include "ui_g13101.h"
#include "institutes.h"
#include "createtask.h"
G13101::G13101(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G13101)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/13101.png");
    ui->image->setPixmap(pix);
}

G13101::~G13101()
{
    delete ui;
}

void G13101::on_pushButton_clicked()
{
    institutes ins;
    ins.setModal(this);
    ins.exec();
}

void G13101::on_pushButton_2_clicked()
{
    createtask task;
    task.setModal(this);
    task.exec();
}
