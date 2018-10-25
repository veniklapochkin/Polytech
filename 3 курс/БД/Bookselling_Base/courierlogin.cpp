#include "courierlogin.h"
#include "ui_courierlogin.h"
#include "courierpage.h"
courierlogin::courierlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::courierlogin)
{
    ui->setupUi(this);
    myDB = QSqlDatabase::addDatabase("QMYSQL");
    myDB.setDatabaseName("bookselling_base");
    myDB.setPort(3306);
    myDB.setUserName("root");
    myDB.setPassword("0000");
    myDB.setHostName("localhost");
    if(!myDB.open()){
        qDebug()<<"No connection :(";
        return;
    }else qDebug()<<"Connection exist :)";
}

courierlogin::~courierlogin()
{
    delete ui;
}

void courierlogin::on_pushButton_2_clicked()
{
    this->close();
}

void courierlogin::on_pushButton_clicked()
{
    QString login,password;
    login = ui->txtl->text();
    password = ui->txtp->text();
    if(!myDB.isOpen()){
        qDebug() <<"No connection to DB";
    }else{qDebug()<<"Connected";
        QSqlQuery qry;
        qry.prepare("SELECT login,password from couriers where login=\'"+login+"'AND password=\'"+password+"\'");
        if(qry.exec()){
            if(qry.next()){
                ui->lstatus->setText("Valid login or password");
                QString msg = "Hello, "+qry.value(0).toString()+"\n";
                QMessageBox::information(this,"You were authenticated   ",msg);
                courierpage coupage;
                coupage.setModal(this);
                coupage.exec();
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
