#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>


#include <secdialog.h>
#include <sixdialog.h>
#include <sevendialog.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    SecDialog op;
    op.setModal(true);
    op.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    //MainWindow conn;

    QSqlQueryModel *modal = new QSqlQueryModel();

    //conn.connOpen1();

    connOpen1();

    //QSqlQuery *qry = new QSqlQuery(conn.db1);

    QSqlQuery *qry = new QSqlQuery(db1);

    qry->prepare("select place from place");
    qry->exec();

    modal->setQuery(*qry);

    ui-> comboBox-> setModel(modal);

    //conn.connClose1();
    connClose1();
    qDebug() << (modal->rowCount());
}

void MainWindow::on_pushButton_3_clicked()
{

     sixDialog op;
    op.setModal(true);
    op.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
   /* QString username = ui -> lineEdit_username -> text();
    QString password = ui -> lineEdit_password-> text();*/

    QString password = ui -> lineEdit_passwordb-> text();
    QString gmail = ui -> lineEdit_gmailb -> text();


   if(!connOpen10()){
       qDebug() << "Failed to Open";

   }
   connOpen10();
   QSqlQuery qry;
   if(qry.exec("select *from customer where gmail ='"+gmail+"' and password = '"+password+"'"))
   {
      int count = 0;

       while(qry.next())
       {
           count++;
       }
       if(count == 1){
           QMessageBox :: information(this,"success","<font color = black> login successful");
           connClose10();
           //this->hide();
          sevenDialog op;
           op.setModal(true);
           op.exec();
       }
       if(count>1)
           QMessageBox :: information(this,"success","<font color = black> Informaton duplicate ");
       if(count <1)
           QMessageBox :: information(this,"success","<font color = black> login not successful");
  }
}
