#include "createtask.h"
#include "ui_createtask.h"
#define Path_to_DB "/home/venik_lapochkin/Документы/Qt projects/Shedulepro/DB"
#include <QMessageBox>
createtask::createtask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createtask)
{
    ui->setupUi(this);
    for (int i=1;i<=12;i++){
            if(i<=9){
                ui->month->addItem("0"+QString::number(i));
            }else
            ui->month->addItem(QString::number(i));
        }
        for (int i=1;i<=31;i++){
            if(i<=9){
                ui->day->addItem("0"+QString::number(i));
            }else
            ui->day->addItem(QString::number(i));
        }
        for (int i=2020;i>=2015;i--){
            ui->year->addItem(QString::number(i));
        }
        for (int i=0;i<=23;i++){
            if(i<=9){
            ui->hours->addItem("0"+QString::number(i));}
            else ui->hours->addItem(QString::number(i));
        }
        for (int i=0;i<=59;i++){
            if(i<=9){
            ui->minutes->addItem("0"+QString::number(i));}
            else ui->minutes->addItem(QString::number(i));
        }
        for (int i=0;i<=59;i++){
            if(i<=9){
            ui->seconds->addItem("0"+QString::number(i));}
            else ui->seconds->addItem(QString::number(i));
        }

        if(slf.connOpen()){
            qDebug()<<"Connected";
        }
    else{
        qDebug()<<"Not Connected";
    }
}

createtask::~createtask()
{
    delete ui;
}

void createtask::on_pushButton_clicked()
{
    QString name,discription,time,date;
    discription=ui->textEdit->toPlainText();
    name=ui->name->text();
    time = ui->hours->currentText()+":"+ui->minutes->currentText()+":"+ui->seconds->currentText();
    date = ui->day->currentText()+"."+ui->month->currentText()+"."+ui->year->currentText();
    QFile file("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/borisov");
    if(!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "File is open";
    }else qDebug()<<"Success";
    QString msg = "Done";
    QMessageBox::information(this,"Success!You created activity  ",msg);
    QTextStream writeStream(&file);
    writeStream <<"-----------"<<"\n"<< name<<'\n'<<discription<<'\n'<<time<<'\n'<<date;
    file.close();
}
