#include "teacherloginform.h"
#include "ui_teacherloginform.h"
#include "samochadin_a_v.h"
#include "senichenkov_y_b.h"
#include "timofeev_d_a.h"
#include "shoshmina_i_v.h"
#include "karpov_y_g.h"
#include "teacherregistration.h"
teacherloginform::teacherloginform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacherloginform)
{

    ui->setupUi(this);

    if(slf.connOpen()){
        ui->lstatus->setText("Connected to DB");
    }
    else{
        ui->lstatus->setText("Not connected to DB");}
}

teacherloginform::~teacherloginform()
{
    delete ui;
    qDebug() <<"Closing the connection DB";
}

void teacherloginform::on_btnOk_clicked()
{
    QString login,password;
    login = ui->txtu->text();
    password = ui->txtp->text();
    if(!slf.connOpen()){
        qDebug() <<"No connection to DB";
        return;
    }else{qDebug()<<"Connection exist";}
    slf.connOpen();
    QSqlQuery qry;
    if(qry.exec("SELECT login,password from teachers where login=\'"+login+"'AND password=\'"+password+"\'")){
        if(qry.next()){
            ui->lstatus->setText("Valid login or password");
            if(login=="Samochadin" && password=="13Samochadin"){
                QString msg = "Hello, Alexander Victorovich \n";
                QMessageBox::information(this,"You were authenticated   ",msg);
                samochadin_a_v sam_a_v;
                sam_a_v.setModal(this);
                sam_a_v.exec();slf.connClose();}
            else if(login=="Shoshmina"&&password=="13Shoshmina"){
                QString msg = "Hello, Irina Vladimirovna \n";
                QMessageBox::information(this,"You were authenticated   ",msg);
                shoshmina_i_v sho_i_v;
                sho_i_v.setModal(this);
                sho_i_v.exec();
                slf.connClose();
            }
            else if(login=="Senichenkov"&&password=="13Senichenkov"){
                QString msg = "Hello, Yuri Borisovich \n";
                QMessageBox::information(this,"You were authenticated   ",msg);
                senichenkov_y_b sen_y_b;
                sen_y_b.setModal(this);
                sen_y_b.exec();
                slf.connClose();
            }
            else if(login=="Timofeev"&&password=="13Timofeev"){
                QString msg = "Hello, Dmitri Andreevich \n";
                QMessageBox::information(this,"You were authenticated   ",msg);
                timofeev_d_a tim_d_a;
                tim_d_a.setModal(this);
                tim_d_a.exec();
                slf.connClose();
            }
            else if(login=="Karpov"&&password=="13Karpov"){
                QString msg = "Hello, Yuri Glebovich \n";
                QMessageBox::information(this,"You were authenticated   ",msg);
                karpov_y_g kar_y_g;
                kar_y_g.setModal(this);
                kar_y_g.exec();
                slf.connClose();
            }
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
            ui->lstatus->setText("length login and password\nless than 3");
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

void teacherloginform::on_btnCancel_clicked()
{
    this->close();
}

void teacherloginform::on_btnClear_clicked()
{
    ui->txtu->setText("");
    ui->txtp->setText("");
}

void teacherloginform::on_btnRegistration_clicked()
{
    teacherregistration reg;
    reg.setModal(this);
    reg.exec();
}
