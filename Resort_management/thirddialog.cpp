#include "thirddialog.h"
#include "ui_thirddialog.h"

#include <customercaredialog.h>



#include <QMessageBox>

#include <fourthdialog.h>
#include <fivedialog.h>

ThirdDialog::ThirdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdDialog)
{
    ui->setupUi(this);
}

ThirdDialog::~ThirdDialog()
{
    delete ui;
}

void ThirdDialog::on_pushButton_clicked()
{
    QString username = ui -> lineEdit_username -> text();
    QString password = ui -> lineEdit_password-> text();
    QString gmail = ui -> lineEdit_gmail -> text();


   if(!connOpen3rd()){
       qDebug() << "Failed to Open";

   }
   connOpen3rd();
   QSqlQuery qry;
   qry.prepare("insert into adminlogin  (gmail,username,password) values('"+gmail+"','"+username+"' , '"+password+"')");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("save"),tr("saved"));
       connClose3rd();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }
}

void ThirdDialog::on_pushButton_2_clicked()
{
    QString username = ui -> lineEdit_username -> text();
    QString password = ui -> lineEdit_password-> text();
    QString gmail = ui -> lineEdit_gmail -> text();


   if(!connOpen3rd()){
       qDebug() << "Failed to Open";

   }
   connOpen3rd();
   QSqlQuery qry;
   qry.prepare("update adminlogin set username ='"+username+"' , password = '"+password+"' , gmail = '"+gmail+"' where username ='"+username+"'");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("edit"),tr("updated"));
       connClose3rd();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }
}

void ThirdDialog::on_pushButton_3_clicked()//add resort
{
    fourthDialog ap;
    ap.setModal(true);
    ap.exec();
}

void ThirdDialog::on_pushButton_4_clicked()//show resort
{
    fiveDialog op;
    op.setModal(true);
    op.exec();
}

void ThirdDialog::on_pushButton_5_clicked()
{
    customercareDialog  op;
    op.setModal(true);
    op.exec();

}
