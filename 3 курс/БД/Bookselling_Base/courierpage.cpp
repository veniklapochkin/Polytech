#include "courierpage.h"
#include "ui_courierpage.h"

courierpage::courierpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::courierpage)
{
    ui->setupUi(this);
    ui->comboBox->addItems(QStringList()<<"Выберите имя"<<"Davidov"<<"Davlatov"<<"Al_Capone");
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

courierpage::~courierpage()
{
    delete ui;
}

void courierpage::on_comboBox_currentTextChanged(const QString &arg1)
{
    QString combo;
    combo = ui->comboBox->currentText();
    if(combo=="Davidov"){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("SELECT*FROM bill where released='Davidov'");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }else if(combo=="Davlatov"){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("SELECT*FROM bill WHERE released = 'Davlatov'");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }else if(combo=="Al_Capone"){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("SELECT*FROM bill WHERE released = 'Al Capone'");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }
}

void courierpage::on_doneorder_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel;
    QSqlQuery* qry1 = new QSqlQuery(myDB);
    qry1->prepare("update bill set status='done' where status='recieved'");
    qry1->exec();
    modal->setQuery(*qry1);
    ui->tableView->setModel(modal);
}
