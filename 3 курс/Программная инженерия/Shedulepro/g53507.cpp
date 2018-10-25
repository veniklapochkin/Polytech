#include "g53507.h"
#include "ui_g53507.h"
#include "institutes.h"
#include "createtask.h"
G53507::G53507(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G53507)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/53507.png");
    ui->label->setPixmap(pix);
}

G53507::~G53507()
{
    delete ui;
}

void G53507::on_pushButton_clicked()
{
    institutes ins;
    ins.setModal(this);
    ins.exec();
}

void G53507::on_pushButton_2_clicked()
{
    createtask task;
    task.setModal(this);
    task.exec();
}
