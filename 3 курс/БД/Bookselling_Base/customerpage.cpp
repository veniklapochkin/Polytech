#include "customerpage.h"
#include "ui_customerpage.h"
#include "makeorder.h"
customerpage::customerpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerpage)
{
    ui->setupUi(this);
    myDB = QSqlDatabase::addDatabase("QMYSQL");
    myDB.setDatabaseName("bookselling_base");
    myDB.setPort(3306);
    myDB.setUserName("root");
    myDB.setPassword("0000");
    myDB.setHostName("localhost");
    if(!myDB.open()){
        qDebug()<<"Not Connection";
        return;
    }else qDebug()<<"Connection exist";
}

customerpage::~customerpage()
{
    delete ui;
}

void customerpage::on_pushButton_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("select*from storage");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
}

void customerpage::on_pushButton_2_clicked()
{
    makeorder morder;
    morder.setModal(true);
    morder.exec();
}
