#include "customerlogin.h"
#include "ui_customerlogin.h"
#include "customerpage.h"
customerlogin::customerlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerlogin)
{
    ui->setupUi(this);
    myDB = QSqlDatabase::addDatabase("QMYSQL");
    myDB.setPort(3306);
    myDB.setUserName("root");
    myDB.setPassword("0000");
    myDB.setHostName("localhost");
    myDB.setDatabaseName("bookselling_base");
    if(!myDB.open()){
        qDebug()<<"No connection :(";
        return;
    }else qDebug()<<"Connection exist :)";
}

customerlogin::~customerlogin()
{
    delete ui;
}

void customerlogin::on_pushButton_2_clicked()
{
    this->close();
}

void customerlogin::on_pushButton_clicked()
{
    QString login,password;
    login = ui->txtl->text();
    password = ui->txtp->text();
    if(!myDB.isOpen()){
        qDebug() <<"No connection to DB";
    }else{qDebug()<<"Connected";
        QSqlQuery qry;
        qry.prepare("select login,password from customers where login='"+login+"'and password='"+password+"'");
        if(qry.exec()){
            if(qry.next()){
                ui->lstatus->setText("Valid login or password");
                QString msg = "Hello, "+qry.value(0).toString()+"\n";
                QMessageBox::information(this,"You were authenticated   ",msg);
                customerpage cpage;
                cpage.setModal(this);
                cpage.exec();
            }
            else if (login == "" && password ==""){
                ui->lstatus->setText("Empty login and password");
            }
            else if (login == ""){
                ui->lstatus->setText("Empty login");
            }
            else if (password == ""){
                ui->lstatus->setText("Empty password");
            }
            else if (login.length()<3 && password.length()<3){
                ui->lstatus->setText("length login and password less than 3");
            }
            else if (login.length()<3){
                ui->lstatus->setText("length login less than 3");
            }
            else if (password.length()<3){
                ui->lstatus->setText("length password less than 3");
            }
            else{
                ui->lstatus->setText("Invalid login or password");
            }
        }
    }
}
