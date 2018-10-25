#include "g23101.h"
#include "ui_g23101.h"
#include "institutes.h"
#include "createtask.h"
G23101::G23101(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G23101)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/23101.png");
    ui->label->setPixmap(pix);
}

G23101::~G23101()
{
    delete ui;
}

void G23101::on_pushButton_clicked()
{
    institutes ins;
    ins.setModal(this);
    ins.exec();
}

void G23101::on_pushButton_2_clicked()
{
    createtask task;
    task.setModal(this);
    task.exec();
}
