#include "secdialog.h"
#include "ui_secdialog.h"
#include <QDebug>
#include <QMessageBox>

#include <thirddialog.h>


SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_pushButton_clicked()
{
    QString username = ui -> lineEdit_username -> text();
    QString password = ui -> lineEdit_password-> text();


   if(!connOpen()){
       qDebug() << "Failed to Open";

   }
   connOpen();
   QSqlQuery qry;
   if(qry.exec("select *from adminlogin where username ='"+username+"' and password = '"+password+"'"))
   {
      int count = 0;

       while(qry.next())
       {
           count++;
       }
       if(count == 1){
           QMessageBox :: information(this,"success","<font color = black> login successful");
           connClose();
           //this->hide();
           ThirdDialog op;
           op.setModal(true);
           op.exec();
       }
       if(count>1)
           QMessageBox :: information(this,"success","<font color = black> Informaton duplicate ");
       if(count <1)
           QMessageBox :: information(this,"success","<font color = black> login not successful");
  }
}


