#include "institutes.h"
#include "ui_institutes.h"
#include "groups_ibi.h"
#include "groups_icst.h"
institutes::institutes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::institutes)
{
    ui->setupUi(this);
}

institutes::~institutes()
{
    delete ui;
}

void institutes::on_pushButton_2_clicked()
{
    Groups_IBI ibi;
    ibi.setModal(this);
    ibi.exec();
}

void institutes::on_pushButton_clicked()
{
    GROUPS_ICST icst;
    icst.setModal(this);
    icst.exec();
}
