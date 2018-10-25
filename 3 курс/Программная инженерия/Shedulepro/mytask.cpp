#include "mytask.h"
#include "ui_mytask.h"
mytask::mytask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mytask)
{
    ui->setupUi(this);
    QFile file("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/borisov");
        if(!file.open(QIODevice::ReadOnly))
        {
        qDebug() << "File is open";
        }else qDebug()<<"Success";
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
}

mytask::~mytask()
{
    delete ui;
}
