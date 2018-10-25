#include "samochadin_a_v.h"
#include "ui_samochadin_a_v.h"
#include "myactivity.h"
#include "createactivity.h"
#define Path_to_DB "/home/venik_lapochkin/Документы/Qt projects/Shedulepro/DB"
samochadin_a_v::samochadin_a_v(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::samochadin_a_v)

{
    ui->setupUi(this);
    QPixmap pix("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/samochadin_a_v.png");
    ui->label->setPixmap(pix);
}

samochadin_a_v::~samochadin_a_v()
{
    delete ui;
}

void samochadin_a_v::on_pushButton_clicked()
{
    createactivity activity;
    activity.setModal(this);
    activity.exec();
}

void samochadin_a_v::on_pushButton_2_clicked()
{
    myactivity mact;
    mact.setModal(this);
    mact.exec();
    /*QFile file("/home/venik_lapochkin/Документы/Qt projects/Shedulepro/activity");
    if(!file.open(QIODevice::ReadOnly))
    {
    qDebug() << "File is open";
    }else qDebug()<<"Success";*/
    /*myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(Path_to_DB);
    QFileInfo checkFile(Path_to_DB);
    if(checkFile.isFile()){
        if(myDB.open()){
            qDebug()<<"Connected";

        }
    }else{
    qDebug()<<"Connected";}
    QSqlQueryModel * modal = new QSqlQueryModel;
    QSqlQuery* qry = new QSqlQuery(myDB);
    qry->prepare("SELECT*FROM activity WHERE leader='Samochadin'");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);*/
}

