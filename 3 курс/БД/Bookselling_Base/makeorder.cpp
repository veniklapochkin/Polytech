#include "makeorder.h"
#include "ui_makeorder.h"

makeorder::makeorder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::makeorder)
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
    ui->product->addItems(QStringList()<<"Выберете книгу"<<"1984"<<"Animal farm"<<"Brave New Wordl"<<"We"<<"Lord of the Flies"<<"Billy Milligan"<<"The Hitchhiker’s Guide to the Galaxy"<<"A Clockwork Orange"<<"Lolita"<<"The Great Gatsby"<<"La Nausee"<<"The Master and Margarita"<<"To Kill a Mockingbird"<<"Game of Thrones"<<"The Picture of Dorian Gray"<<"Slaughterhouse-Five"<<"Ham on Rye"<<"Solaris"<<"Der Steppenwolf"<<"Fahrenheit 451"<<"The Last Wish"<<"Sword of Destiny"<<"The Road"<<"Red Dragon"<<"The Chronicles of Narnia"<<"The Fall of the House of Usher"<<"One Hundred Years of Solitude"<<"Wuthering Heights"<<"Fear and Loathing in Las Vegas"<<"The Phantom of the Opera"<<"Don Quijote"<<"Les Miserables"<<"The Godfather"<<"Das Parfum"<<"A Hero of Our Time"<<"The Catcher in the Rye"<<"Idiot"<<"The Grapes of Wrath"<<"Hamlet, Prince of Denmarke"<<"The Martian");
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
    for (int i=2015;i<=2020;i++){
        ui->year->addItem(QString::number(i));
    }
}

makeorder::~makeorder()
{
    delete ui;
}

void makeorder::on_pushButton_clicked()
{
    QString customer,address,date,Nproduct,publishing,price,status,released;
    Nproduct = ui->product->currentText();
    released = " ";
    status = " ";
    price = ui->price->text();
    publishing = ui->publishing->text();
    customer = ui->name->text();
    address = ui->address->text();
    date = ui->year->currentText()+"-"+ui->month->currentText()+"-"+ui->day->currentText();
    if(!myDB.open()){
        qDebug() <<"No connection to DB";
        return;
    }else{qDebug()<<"Connection exist";}
    QSqlQuery qry,qry1,qry2;
    qry.prepare("insert into Orders(customer,Nproduct,publishing,address,price,date,status) values ('"+customer+"','"+Nproduct+"','"+publishing+"','"+address+"','"+price+"','"+date+"','"+status+"')");
    qry1.prepare("insert into Bill(Nproduct,publishing,price,date,address,released,received,status) values ('"+Nproduct+"','"+publishing+"','"+price+"','"+date+"','"+address+"','"+released+"','"+customer+"','"+status+"')");
    qry2.prepare("update storage set volume=volume-1 where Nbook='"+Nproduct+"'");
    if(qry.exec()&&qry1.exec()&&qry2.exec()){
        QString msg = "Please, restart your application";
        QMessageBox::information(this,"Success!You were ordered item   ",msg);
    }else{
        QString msg = "Please, try again";
        QMessageBox::warning(this,"Fail!You weren`t order item   ",msg);
    }
}


void makeorder::on_product_currentTextChanged(const QString &arg1)
{
    QString product;
    product=ui->product->currentText();
    if(product=="1984"){
        ui->price->setText("200");
        ui->publishing->setText("AST");
    }else if(product=="Animal farm"){
        ui->price->setText("249");
        ui->publishing->setText("AST");
    }else if(product=="Brave New Wordl"){
        ui->price->setText("300");
        ui->publishing->setText("Exmo");
    }else if(product=="We"){
        ui->price->setText("213");
        ui->publishing->setText("Exmo");
    }else if(product=="Lord of the Flies"){
        ui->price->setText("189");
        ui->publishing->setText("AST");
    }else if(product=="Billy Milligan"){
        ui->price->setText("249");
        ui->publishing->setText("Exmo");
    }else if(product=="The Hitchhiker’s Guide to the Galaxy"){
        ui->price->setText("155");
        ui->publishing->setText("AST");
    }else if(product=="A Clockwork Orange"){
        ui->price->setText("180");
        ui->publishing->setText("AST");
    }else if(product=="Lolita"){
        ui->price->setText("142");
        ui->publishing->setText("Azbuka");
    }else if(product=="The Great Gatsby"){
        ui->price->setText("105");
        ui->publishing->setText("Azbuka");
    }else if(product=="La Nausee"){
        ui->price->setText("189");
        ui->publishing->setText("AST");
    }else if(product=="The Master and Margarita"){
        ui->price->setText("115");
        ui->publishing->setText("Azbuka");
    }else if(product=="To Kill a Mockingbird"){
        ui->price->setText("361");
        ui->publishing->setText("AST");
    }else if(product=="Game of Thrones"){
        ui->price->setText("406");
        ui->publishing->setText("AST");
    }else if(product=="The Picture of Dorian Gray"){
        ui->price->setText("156");
        ui->publishing->setText("Azbuka");
    }else if(product=="Slaughterhouse-Five"){
        ui->price->setText("171");
        ui->publishing->setText("AST");
    }else if(product=="Ham on Rye"){
        ui->price->setText("149");
        ui->publishing->setText("Exmo");
    }else if(product=="Solaris"){
        ui->price->setText("162");
        ui->publishing->setText("AST");
    }else if(product=="Der Steppenwolf"){
        ui->price->setText("189");
        ui->publishing->setText("AST");
    }else if(product=="Fahrenheit 451"){
        ui->price->setText("451");
        ui->publishing->setText("Azbuka");
    }else if(product=="The Last Wish"){
        ui->price->setText("379");
        ui->publishing->setText("Azbuka");
    }else if(product=="Sword of Destiny"){
        ui->price->setText("599");
        ui->publishing->setText("Exmo");
    }else if(product=="The Road"){
        ui->price->setText("450");
        ui->publishing->setText("AST");
    }else if(product=="Red Dragon"){
        ui->price->setText("500");
        ui->publishing->setText("AST");
    }else if(product=="The Chronicles of Narnia"){
        ui->price->setText("539");
        ui->publishing->setText("Exmo");
    }else if(product=="The Fall of the House of Usher"){
        ui->price->setText("116");
        ui->publishing->setText("Azbuka");
    }else if(product=="One Hundred Years of Solitude"){
        ui->price->setText("495");
        ui->publishing->setText("AST");
    }else if(product=="Wuthering Heights"){
        ui->price->setText("115");
        ui->publishing->setText("Azbuka");
    }else if(product=="Fear and Loathing in Las Vegas"){
        ui->price->setText("180");
        ui->publishing->setText("AST");
    }else if(product=="The Phantom of the Opera"){
        ui->price->setText("116");
        ui->publishing->setText("Azbuka");
    }else if(product=="Don Quijote"){
        ui->price->setText("171");
        ui->publishing->setText("Azbuka");
    }else if(product=="Les Miserables"){
        ui->price->setText("163");
        ui->publishing->setText("Azbuka");
    }else if(product=="The Godfather"){
        ui->price->setText("181");
        ui->publishing->setText("Exmo");
    }else if(product=="Das Parfum"){
        ui->price->setText("142");
        ui->publishing->setText("Azbuka");
    }else if(product=="A Hero of Our Time"){
        ui->price->setText("116");
        ui->publishing->setText("Azbuka");
    }else if(product=="The Catcher in the Rye"){
        ui->price->setText("135");
        ui->publishing->setText("Exmo");
    }else if(product=="Idiot"){
        ui->price->setText("217");
        ui->publishing->setText("Exmo");
    }else if(product=="The Grapes of Wrath"){
        ui->price->setText("148");
        ui->publishing->setText("Exmo");
    }else if(product=="Hamlet, Prince of Denmarke"){
        ui->price->setText("105");
        ui->publishing->setText("Azbuka");
    }else if(product=="The Martian"){
        ui->price->setText("400");
        ui->publishing->setText("AST");
    }
}
