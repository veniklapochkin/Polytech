#include "g23507.h"
#include "ui_g23507.h"
#include "institutes.h"
#include "createtask.h"
G23507::G23507(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G23507)
{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/23507.png");
    ui->label->setPixmap(pix);
}

G23507::~G23507()
{
    delete ui;
}

void G23507::on_pushButton_clicked()
{
    institutes ins;
    ins.setModal(this);
    ins.exec();
}

void G23507::on_pushButton_2_clicked()
{
    createtask task;
    task.setModal(this);
    task.exec();
}
