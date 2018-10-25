#include "g53101.h"
#include "ui_g53101.h"
#include "institutes.h"
#include "createtask.h"
G53101::G53101(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G53101)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/53101.png");
    ui->label->setPixmap(pix);
}

G53101::~G53101()
{
    delete ui;
}

void G53101::on_pushButton_clicked()
{
    institutes ins;
    ins.setModal(this);
    ins.exec();
}

void G53101::on_pushButton_2_clicked()
{
    createtask task;
    task.setModal(this);
    task.exec();
}
