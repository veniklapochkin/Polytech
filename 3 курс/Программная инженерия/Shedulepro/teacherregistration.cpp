#include "teacherregistration.h"
#include "ui_teacherregistration.h"
#define Path_to_DB "/home/venik_lapochkin/Документы/Qt projects/Shedulepro/DB"
#include <QMessageBox>
teacherregistration::teacherregistration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacherregistration)
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

teacherregistration::~teacherregistration()
{
    delete ui;
    qDebug() <<"Closing the connection DB";
}

void teacherregistration::on_pushButton_2_clicked()
{
    this->close();
}

void teacherregistration::on_pushButton_clicked()
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
            ui->llabel->setText("Empty login");
        }
        else if (login.length()<3){
            ui->llabel->setText("length login less than 3");
        }
        else if (login.contains("а")||login.contains("б")||login.contains("в")||login.contains("г")||login.contains("д")||login.contains("е")||login.contains("ё")||login.contains("ж")||login.contains("з")||login.contains("и")||login.contains("й")||login.contains("к")||login.contains("л")||login.contains("м")||login.contains("н")||login.contains("о")||login.contains("п")||login.contains("р")||login.contains("с")||login.contains("т")||login.contains("у")||login.contains("ф")||login.contains("х")||login.contains("ц")||login.contains("ч")||login.contains("ш")||login.contains("щ")||login.contains("ъ")||login.contains("ы")||login.contains("ь")||login.contains("э")||login.contains("ю")||login.contains("я"))
        {
            ui->llabel->setText("only english symbols");
        }
        else {ui->llabel->setText("Correct");}
        if (password == ""){
            ui->plabel->setText("Empty password");
        }
        else if (password.length()<3){
            ui->plabel->setText("length password less than 3");
        }
        else if(password.contains("а")||password.contains("б")||password.contains("в")||password.contains("г")||password.contains("д")||password.contains("е")||password.contains("ё")||password.contains("ж")||password.contains("з")||password.contains("и")||password.contains("й")||password.contains("к")||password.contains("л")||password.contains("м")||password.contains("н")||password.contains("о")||password.contains("п")||password.contains("р")||password.contains("с")||password.contains("т")||password.contains("у")||password.contains("ф")||password.contains("х")||password.contains("ц")||password.contains("ч")||password.contains("ш")||password.contains("щ")||password.contains("ъ")||password.contains("ы")||password.contains("ь")||password.contains("э")||password.contains("ю")||password.contains("я")){
            ui->plabel->setText("only english symbols");
        }
        else { ui->plabel->setText("Correct");}
        if (spassword ==""){
            ui->splabel->setText("Empty password");
        }
        else if (spassword.length()<3){
            ui->splabel->setText("length password less than 3");
        }
        else if(spassword.contains("а")||spassword.contains("б")||spassword.contains("в")||spassword.contains("г")||spassword.contains("д")||spassword.contains("е")||spassword.contains("ё")||spassword.contains("ж")||spassword.contains("з")||spassword.contains("и")||spassword.contains("й")||spassword.contains("к")||spassword.contains("л")||spassword.contains("м")||spassword.contains("н")||spassword.contains("о")||spassword.contains("п")||spassword.contains("р")||spassword.contains("с")||spassword.contains("т")||spassword.contains("у")||spassword.contains("ф")||spassword.contains("х")||spassword.contains("ц")||spassword.contains("ч")||spassword.contains("ш")||spassword.contains("щ")||spassword.contains("ъ")||spassword.contains("ы")||spassword.contains("ь")||spassword.contains("э")||spassword.contains("ю")||spassword.contains("я")){
            ui->splabel->setText("only english symbols");
        }
        else if (spassword !=password){
            ui->splabel->setText("the passwords do not match");
            ui->plabel->setText("the passwords do not match");
        }
        else{ui->plabel->setText("Correct");
            ui->splabel->setText("Correct");}
        if(mail==""){
            ui->mlabel->setText("Empty mail");
        }
        else if (mail.length()<3){
            ui->mlabel->setText("length mail less than 3");
        }
        else if(mail.contains("а")||mail.contains("б")||mail.contains("в")||mail.contains("г")||mail.contains("д")||mail.contains("е")||mail.contains("ё")||mail.contains("ж")||mail.contains("з")||mail.contains("и")||mail.contains("й")||mail.contains("к")||mail.contains("л")||mail.contains("м")||mail.contains("н")||mail.contains("о")||mail.contains("п")||mail.contains("р")||mail.contains("с")||mail.contains("т")||mail.contains("у")||mail.contains("ф")||mail.contains("х")||mail.contains("ц")||mail.contains("ч")||mail.contains("ш")||mail.contains("щ")||mail.contains("ъ")||mail.contains("ы")||mail.contains("ь")||mail.contains("э")||mail.contains("ю")||mail.contains("я")){
            ui->mlabel->setText("only english symbols");
        }
        else{ui->mlabel->setText("Correct");}
        QString msg = "Please, try again";
        QMessageBox::warning(this,"Fail!You weren`t registred   ",msg);
    }else{
        if(!slf.connOpen()){
            qDebug() <<"No connection to DB";
            return;
        }else{qDebug()<<"Connection exist";}
        slf.connOpen();
        QSqlQuery qry;
        qry.prepare("insert into teachers (birthday,gender,mail,login,password) values ('"+birthday+"','"+gender+"','"+mail+"','"+login+"','"+password+"')");
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
