#include "studentregistration.h"
#include "ui_studentregistration.h"
#define Path_to_DB "/home/venik_lapochkin/Документы/Qt projects/Shedulepro/DB"
#include <QMessageBox>
studentregistration::studentregistration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentregistration)
{
    ui->setupUi(this);
    ui->combogender->addItem("male");
    ui->combogender->addItem("female");
    ui->comboBox->addItems(QStringList()<<"@mail"<<"@yandex"<<"@gmail");
    ui->comboBox_2->addItems(QStringList()<<".ru"<<".com");
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
    for (int i=2015;i>=1900;i--){
        ui->year->addItem(QString::number(i));
    }
    if(slf.connOpen()){
        ui->Status->setText("Connected to DB");
    }
    else{
        ui->Status->setText("Not connected to DB");}
}

studentregistration::~studentregistration()
{
    delete ui;
    qDebug() <<"Closing the connection DB";
}

void studentregistration::on_pushButton_clicked()
{
    this->close();
}

void studentregistration::on_pushButton_2_clicked()
{
    QString login,password,spassword,mail,gender,birthday;
    login = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    spassword = ui->lineEdit_3->text();
    mail = ui->lineEdit_4->text()+ui->comboBox->currentText()+ui->comboBox_2->currentText();
    gender = ui->combogender->currentText();
    birthday = ui->day->currentText()+"."+ui->month->currentText()+"."+ui->year->currentText();
    if(password.length()<3||login.length()<3||spassword !=password||spassword.length()<3){
        if (login == ""){
            ui->llable->setText("Empty login");
        }
        else if (login.length()<3){
            ui->llable->setText("length login less than 3");
        }

        else if(login.indexOf((QRegExp("[\\x0400-\\x045f]"), 0)))
        {
            ui->llable->setText("only english symbols");
        }
        else {ui->llable->setText("Correct");}
        if (password == ""){
            ui->plable->setText("Empty password");
        }
        else if (password.length()<3){
            ui->plable->setText("length password less than 3");
        }
        else if(password.indexOf((QRegExp("[\\x0400-\\x045f]"), 0)))
        {
            ui->plable->setText("only english symbols");
        }
        else { ui->plable->setText("Correct");}
        if (spassword ==""){
            ui->splable->setText("Empty password");
        }
        else if (spassword.length()<3){
            ui->splable->setText("length password less than 3");
        }
        else if(spassword.indexOf((QRegExp("[\\x0400-\\x045f]"), 0)))
        {
            ui->splable->setText("only english symbols");
        }
        else if (spassword !=password){
            ui->splable->setText("the passwords do not match");
            ui->plable->setText("the passwords do not match");
        }
        else{ui->plable->setText("Correct");
            ui->splable->setText("Correct");}
        if(mail==""){
            ui->mlable->setText("Empty mail");
        }
        else if (mail.length()<3){
            ui->mlable->setText("length mail less than 3");
        }
        else if(mail.indexOf((QRegExp("[\\x0400-\\x045f]"), 0))){
        ui->mlable->setText("only english symbols");
        }
        else{ui->mlable->setText("Correct");}
        QString msg = "Please, try again";
        QMessageBox::warning(this,"Fail!You weren`t registred   ",msg);
    }else{
        if(!slf.connOpen()){
            qDebug() <<"No connection to DB";
            return;
        }else{qDebug()<<"Connection exist";}
        slf.connOpen();
        QSqlQuery qry;
        qry.prepare("insert into students (birthday,gender,mail,login,password) values ('"+birthday+"','"+gender+"','"+mail+"','"+login+"','"+password+"')");
        if(qry.exec()){
            QString msg = "Please, restart your application";
            QMessageBox::information(this,"Success!You were registred   ",msg);
            slf.connClose();
        }else{
            QString msg = "Please, try again";
            QMessageBox::warning(this,"Fail!You weren`t registred   ",msg);
            slf.connClose();
        }
    }
}
