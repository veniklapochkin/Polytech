#include "adminpage.h"
#include "ui_adminpage.h"

adminpage::adminpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminpage)
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
        close();
        return;
    }else
    ui->chose->addItems(QStringList()<<"Выбрать курьера"<<"Davidov"<<"Davlatov"<<"Al_Capone");
    ui->comboBox->addItems(QStringList()
    <<"Запросы"
    <<"1)Выбрать заказчиков которые покупают продукцию только одного издательства"
    <<"2)Выбрать издательство книги, которое распродается быстрее всего за определённый промежуток времени"
    <<"3)Выбрать курьеров которые получают прибыль с заказов выше среднего"
    <<"4)Повышать книгам рейтинг 3м если они продаются за определённый промежуток времени больше других"
    <<"5)Понижать последним 3 книгам рейтинг если они продаются за определённый промежуток времени меньше других"
    <<"6)Вывести 3 самых активных заказчиков за определенное время"
    <<"7)Выбрать заказчика, сделавшего за определенный промежуток времени более 10 заказов"
    <<"8)Выбрать заказчика,сделавшего заказы продукции нескольких издательств"
    <<"9)Выбрать книги, которые фигурировали в списке наиб-е покупаемых"
    <<"10)Выбрать три дня в году, когда больше всего продаж.");

}

adminpage::~adminpage()
{
    delete ui;
}

void adminpage::on_comboBox_currentTextChanged(const QString &arg1)
{
    QString combo;
    combo = ui->comboBox->currentText();
    if(combo.contains("1)")){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("select distinct customer,publishing from orders a where not exists(select*from Orders b where b.customer=a.customer and b.publishing<>a.publishing)");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }else if(combo.contains("2)")){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("select publishing,COUNT(publishing),SUM(price) from orders where(date BETWEEN '2015-08-08' AND '2015-11-01') group by publishing order by SUM(price) desc limit 1");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }else if(combo.contains("3)")){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("select a.released,SUM(a.price) from bill a group by released having SUM(a.price)>(select AVG(asset) from (select a.released, SUM(a.price) AS asset from Bill a group by a.released) inner_query)");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }else if(combo.contains("4)")){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("update storage set rating=rating+10 where(Nbook IN (select Nproduct from Orders where (date BETWEEN '2015-08-02' AND '2015-11-01')GROUP BY Nproduct order by SUM(price) desc))limit 3");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }else if(combo.contains("5)")){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("update storage set rating=rating-10 where(Nbook IN (select Nproduct from Orders where (date BETWEEN '2015-08-02' AND '2015-11-01')GROUP BY Nproduct order by SUM(price)))limit 3");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }else if(combo.contains("6)")){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("select customer,COUNT(customer),SUM(price) from orders where(date BETWEEN '2015-08-08' AND '2015-11-01')group by customer order by SUM(price) desc limit 3");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }else if(combo.contains("7)")){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("select customer,COUNT(customer) from  orders where  (date between '2015-08-01' and '2015-11-05') group by customer HAVING COUNT(customer)>10");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }else if(combo.contains("8)")){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("select distinct customer,publishing from orders a where exists(select*from Orders b where b.customer=a.customer and b.publishing<>a.publishing)");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }else if(combo.contains("9)")){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("select Nproduct, COUNT(Nproduct) from orders group by Nproduct HAVING COUNT(Nproduct)>1");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }else if(combo.contains("10)")){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("select date,COUNT(date) from Bill group by date order by COUNT(date) desc limit 3");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
}
}

void adminpage::on_pushButton_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("select*from storage");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
}

void adminpage::on_pushButton_2_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("select*from bill");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
}

void adminpage::on_pushButton_3_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("select*from orders");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
}

void adminpage::on_pushButton_4_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel;
    QSqlQuery* qry = new QSqlQuery(myDB);
    QSqlQuery* qry1 = new QSqlQuery(myDB);
    qry->prepare("update orders set status='recieved' where status=' '");
    qry1->prepare("update bill set status='recieved' where status=' '");
    qry->exec();
    qry1->exec();
    modal->setQuery(*qry);
    modal->setQuery(*qry1);
    ui->tableView->setModel(modal);
}

void adminpage::on_chose_currentTextChanged(const QString &arg1)
{
    QString chose;
    chose=ui->chose->currentText();
    if(chose=="Davidov"){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("update bill set released='Davidov' where released=' '");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }else if(chose=="Davlatov"){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("update bill set released='Davlatov' where released=' '");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }else if(chose=="Al_Capone"){
        QSqlQueryModel * modal = new QSqlQueryModel;
        QSqlQuery* qry = new QSqlQuery(myDB);
        qry->prepare("update bill set released='Al Capone' where released=' '");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
    }
}

void adminpage::on_pushButton_5_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel;
    QSqlQuery* qry1 = new QSqlQuery(myDB);
    qry1->prepare("update orders set status='done' where status='recieved'");
    qry1->exec();
    modal->setQuery(*qry1);
    ui->tableView->setModel(modal);
}
