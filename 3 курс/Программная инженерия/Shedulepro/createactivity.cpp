#include "createactivity.h"
#include "ui_createactivity.h"
#define Path_to_DB "/home/venik_lapochkin/Документы/Qt projects/Shedulepro/DB"
#include <QMessageBox>
createactivity::createactivity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createactivity)
{
    ui->setupUi(this);
    for (int i=0;i<=23;i++){
        if(i<=9){
            ui->hours->addItem("0"+QString::number(i));
        }else
            ui->hours->addItem(QString::number(i));
    }
    for (int i=0;i<=59;i++){
        if(i<=9){
            ui->minutes->addItem("0"+QString::number(i));
        }else
            ui->minutes->addItem(QString::number(i));
    }
    for (int i=0;i<=59;i++){
        if(i<=9){
            ui->seconds->addItem("0"+QString::number(i));
        }else
            ui->seconds->addItem(QString::number(i));
    }
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
    for (int i=2015;i<=2020;i++){
        ui->year->addItem(QString::number(i));
    }
    ui->party->addItems(QStringList()<<"13507"<<"23507"<<"33507"<<"43507"<<"53507"<<"63507");
    ui->leader->addItems(QStringList()<<"Самочадин А.А."<<"Шошмина И.В."<<"Тимофеев.Д.А"<<"Карпов Ю.Г."<<"Сениченков.Ю.Б");
    for(int i=100;i<=150;i++){
        ui->aud->addItem("a."+QString::number(i));
    }

    if(slf.connOpen()){
        qDebug()<<"Connected";
    }
    else{
        qDebug()<<"Not Connected";
    }
}

createactivity::~createactivity()
{
    delete ui;
}

void createactivity::on_pushButton_clicked()
{

    QString aud,party,date,time,leader;
    aud = ui->aud->currentText();
    party = ui->party->currentText();
    leader = ui->leader->currentText();
    time = ui->hours->currentText()+":"+ui->minutes->currentText()+":"+ui->seconds->currentText();
    date = ui->day->currentText()+"."+ui->month->currentText()+"."+ui->year->currentText();
    if(leader=="Самочадин А.А."){
    QFile file("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/samochadin");
    if(!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "File is open";
    }else qDebug()<<"Success";
    QString msg = "Done";
    QMessageBox::information(this,"Success!You created activity  ",msg);
    QTextStream writeStream(&file);
    writeStream <<"-----------"<<"\n"<< aud<<'\n'<<party<<'\n'<<leader<<'\n'<<time<<'\n'<<date;
    file.close();}
    else if(leader=="Карпов Ю.Г."){
    QFile file("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/karpov");
    if(!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "File is open";
    }else qDebug()<<"Success";
    QString msg = "Done";
    QMessageBox::information(this,"Success!You created activity  ",msg);
    QTextStream writeStream(&file);
    writeStream <<"-----------"<<"\n"<< aud<<'\n'<<party<<'\n'<<leader<<'\n'<<time<<'\n'<<date;
    file.close();}
    else if(leader=="Сениченков.Ю.Б"){
    QFile file("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/senichenkov");
    if(!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "File is open";
    }else qDebug()<<"Success";
    QString msg = "Done";
    QMessageBox::information(this,"Success!You created activity  ",msg);
    QTextStream writeStream(&file);
    writeStream <<"-----------"<<"\n"<< aud<<'\n'<<party<<'\n'<<leader<<'\n'<<time<<'\n'<<date;
    file.close();}
    else if(leader=="Шошмина И.В."){
    QFile file("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/shoshmina");
    if(!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "File is open";
    }else qDebug()<<"Success";
    QString msg = "Done";
    QMessageBox::information(this,"Success!You created activity  ",msg);
    QTextStream writeStream(&file);
    writeStream <<"-----------"<<"\n"<< aud<<'\n'<<party<<'\n'<<leader<<'\n'<<time<<'\n'<<date;
    file.close();}
    else if(leader=="Тимофеев.Д.А"){
    QFile file("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/timofeev");
    if(!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "File is open";
    }else qDebug()<<"Success";
    QString msg = "Done";
    QMessageBox::information(this,"Success!You created activity  ",msg);
    QTextStream writeStream(&file);
    writeStream <<"-----------"<<"\n"<< aud<<'\n'<<party<<'\n'<<leader<<'\n'<<time<<'\n'<<date;
    file.close();}

}

