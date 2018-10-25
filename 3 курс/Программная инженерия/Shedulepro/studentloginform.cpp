#include "studentloginform.h"
#include "ui_studentloginform.h"
#include "institutes.h"
#include "studentregistration.h"
#include "g13101.h"
#include "g23101.h"
#include "g33101.h"
#include "g43101.h"
#include "g53101.h"
#include "g63101.h"
#include "g13507.h"
#include "g23507.h"
#include "g33507.h"
#include "g43507.h"
#include "g53507.h"
#include "g63507.h"
#include "mainwindow.h"
#define Path_to_DB "/home/venik_lapochkin/Документы/Qt projects/Shedulepro/DB"
studentLoginForm::studentLoginForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentLoginForm)
{
    ui->setupUi(this);
    if(connOpen()){
        ui->lstatus->setText("Connected to DB");
    }
    else{
        ui->lstatus->setText("Not connected to DB");}
}

studentLoginForm::~studentLoginForm()
{
    delete ui;
    qDebug() <<"Closing the connection DB";
}

void studentLoginForm::on_btnOk_clicked()
{
    QString login,password;
    login = ui->txtu->text();
    password = ui->txtp->text();
    if(!connOpen()){
        qDebug() <<"No connection to DB";
    }else{qDebug()<<"Connection exist";}
    connOpen();
    QSqlQuery qry;
    qry.prepare("SELECT login,password from students where login=\'"+login+"'AND password=\'"+password+"\'");
    if(qry.exec()){
        if(qry.next()){
            ui->lstatus->setText("Valid login or password");
            QString msg = "Hello, "+qry.value(0).toString()+"\n";
            QMessageBox::information(this,"You were authenticated   ",msg);
            if (login.contains("17")){
                connClose();
                G13507 g;
                g.setModal(this);
                g.exec();
            }
            else if (login.contains("27")){
                connClose();
                G23507 g;
                g.setModal(this);
                g.exec();
            }
            else if (login.contains("37")){
                connClose();
                G33507 g;
                g.setModal(this);
                g.exec();
            }
            else if (login.contains("47")){
                connClose();
                G43507 g;
                g.setModal(this);
                g.exec();
            }
            else if (login.contains("57")){
                connClose();
                G53507 g;
                g.setModal(this);
                g.exec();
            }
            else if (login.contains("67")){
                connClose();
                G63507 g;
                g.setModal(this);
                g.exec();
            }
            else if(login.contains("11")){
                connClose();
                G13101 g;
                g.setModal(this);
                g.exec();
            }
            else if(login.contains("21")){
                connClose();
                G23101 g;
                g.setModal(this);
                g.exec();
            }
            else if(login.contains("31")){
                connClose();
                G33101 g;
                g.setModal(this);
                g.exec();
            }
            else if(login.contains("41")){
                connClose();
                G43101 g;
                g.setModal(this);
                g.exec();
            }
            else if(login.contains("51")){
                connClose();
                G53101 g;
                g.setModal(this);
                g.exec();
            }
            else if(login.contains("61")){
                connClose();
                G63101 g;
                g.setModal(this);
                g.exec();
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
        else if (login.contains("а")||login.contains("б")||login.contains("в")||login.contains("г")||login.contains("д")||login.contains("е")||login.contains("ё")||login.contains("ж")||login.contains("з")||login.contains("и")||login.contains("й")||login.contains("к")||login.contains("л")||login.contains("м")||login.contains("н")||login.contains("о")||login.contains("п")||login.contains("р")||login.contains("с")||login.contains("т")||login.contains("у")||login.contains("ф")||login.contains("х")||login.contains("ц")||login.contains("ч")||login.contains("ш")||login.contains("щ")||login.contains("ъ")||login.contains("ы")||login.contains("ь")||login.contains("э")||login.contains("ю")||login.contains("я")||
                 password.contains("а")||password.contains("б")||password.contains("в")||password.contains("г")||password.contains("д")||password.contains("е")||password.contains("ё")||password.contains("ж")||password.contains("з")||password.contains("и")||password.contains("й")||password.contains("к")||password.contains("л")||password.contains("м")||password.contains("н")||password.contains("о")||password.contains("п")||password.contains("р")||password.contains("с")||password.contains("т")||password.contains("у")||password.contains("ф")||password.contains("х")||password.contains("ц")||password.contains("ч")||password.contains("ш")||password.contains("щ")||password.contains("ъ")||password.contains("ы")||password.contains("ь")||password.contains("э")||password.contains("ю")||password.contains("я")){
            ui->lstatus->setText("only english symbols");
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

void studentLoginForm::on_btnClear_clicked()
{
    ui->txtp->setText("");
    ui->txtu->setText("");
}

void studentLoginForm::on_btnCancel_clicked()
{
    this->close();
}


void studentLoginForm::on_btnRegistration_clicked()
{
    studentregistration reg;
    reg.setModal(this);
    reg.exec();
}
