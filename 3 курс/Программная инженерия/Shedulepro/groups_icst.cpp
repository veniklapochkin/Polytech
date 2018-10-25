#include "groups_icst.h"
#include "ui_groups_icst.h"
#include "g13507.h"
#include "g23507.h"
#include "g33507.h"
#include "g43507.h"
#include "g53507.h"
#include "g63507.h"
GROUPS_ICST::GROUPS_ICST(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GROUPS_ICST)
{
    ui->setupUi(this);
}

GROUPS_ICST::~GROUPS_ICST()
{
    delete ui;
}

void GROUPS_ICST::on_pushButton_2_clicked()
{
    G23507 g23507;
    g23507.setModal(this);
    g23507.exec();
}

void GROUPS_ICST::on_pushButton_clicked()
{
    G13507 g13507;
    g13507.setModal(this);
    g13507.exec();
}

void GROUPS_ICST::on_pushButton_3_clicked()
{
    G33507 g33507;
    g33507.setModal(this);
    g33507.exec();
}

void GROUPS_ICST::on_pushButton_4_clicked()
{
    G43507 g43507;
    g43507.setModal(this);
    g43507.exec();
}

void GROUPS_ICST::on_pushButton_5_clicked()
{
    G53507 g53507;
    g53507.setModal(this);
    g53507.exec();
}

void GROUPS_ICST::on_pushButton_6_clicked()
{
    G63507 g63507;
    g63507.setModal(this);
    g63507.exec();
}
