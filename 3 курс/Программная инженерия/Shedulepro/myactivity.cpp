#include "myactivity.h"
#include "ui_myactivity.h"
#include <QTextStream>
#include <QFile>
myactivity::myactivity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myactivity)
{
    ui->setupUi(this);
    ui->comboBox->addItems(QStringList()<<"Samochadin"<<"Karpov"<<"Timofeev"<<"Shoshmina"<<"Senichenkov");
        if(slf.connOpen()){
            qDebug()<<"Connected";
        }
    else{
    qDebug()<<"Not Connected";}
}

myactivity::~myactivity()
{
    delete ui;
}

void myactivity::on_comboBox_currentTextChanged(const QString &arg1)
{
    QString combo;
    combo = ui->comboBox->currentText();
    if(combo=="Samochadin"){
        slf.connOpen();
        /*QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery();
        qry->prepare("SELECT*FROM activity where leader='Samochadin'");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);*/
        QFile file("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/samochadin");
            if(!file.open(QIODevice::ReadOnly))
            {
            qDebug() << "File is open";
            }else qDebug()<<"Success";
            QTextStream in(&file);
            ui->textBrowser->setText(in.readAll());
        slf.connClose();
    }else if(combo=="Karpov"){
        slf.connOpen();
        QFile file("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/karpov");
            if(!file.open(QIODevice::ReadOnly))
            {
            qDebug() << "File is open";
            }else qDebug()<<"Success";
            QTextStream in(&file);
            ui->textBrowser->setText(in.readAll());/*
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery();
        qry->prepare("SELECT*FROM activity where leader = 'Karpov'");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);*/
        slf.connClose();
    }else if(combo=="Senichenkov"){
        slf.connOpen();
        QFile file("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/senichenkov");
            if(!file.open(QIODevice::ReadOnly))
            {
            qDebug() << "File is open";
            }else qDebug()<<"Success";
            QTextStream in(&file);
            ui->textBrowser->setText(in.readAll());/*
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery();
        qry->prepare("SELECT*FROM activity where leader = 'Senichenkov'");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);*/
        slf.connClose();
    }else if(combo=="Shoshmina"){
        slf.connOpen();
        QFile file("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/shoshmina");
            if(!file.open(QIODevice::ReadOnly))
            {
            qDebug() << "File is open";
            }else qDebug()<<"Success";
            QTextStream in(&file);
            ui->textBrowser->setText(in.readAll());/*
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery();
        qry->prepare("SELECT*FROM activity where leader = 'Shoshmina'");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);*/
        slf.connClose();
    }else if(combo=="Timofeev"){
        slf.connOpen();
        QFile file("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/timofeev");
            if(!file.open(QIODevice::ReadOnly))
            {
            qDebug() << "File is open";
            }else qDebug()<<"Success";
            QTextStream in(&file);
            ui->textBrowser->setText(in.readAll());/*
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery();
        qry->prepare("SELECT*FROM activity where leader = 'Timofeev'");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);*/
        slf.connClose();
    }
}
