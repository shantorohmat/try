#include "fourthdialog.h"
#include "ui_fourthdialog.h"

#include <QMessageBox>

#include <ctgadminsavedialog.h>
#include <saintadminsavedialog.h>
#include <sajadminsavedialog.h>

fourthDialog::fourthDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fourthDialog)
{
    ui->setupUi(this);
}

fourthDialog::~fourthDialog()
{
    delete ui;
}

/*void fourthDialog::on_pushButton_2_clicked()
{
    QString name = ui -> lineEdit_name -> text();
    QString description = ui -> lineEdit_description-> text();
     //QString Gmail = ui -> lineEdit_gmail -> text();


   if(!connOpen1()){
       qDebug() << "Failed to Open";

   }
   connOpen1();
   QSqlQuery qry;
   qry.prepare("insert into resort  (name,description) values('"+name+"' , '"+description+"')");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("save"),tr("saved"));
       connClose1();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }
}

void fourthDialog::on_pushButton_clicked()
{
    QString name = ui -> lineEdit_name -> text();
    QString description = ui -> lineEdit_description-> text();
     //QString Gmail = ui -> lineEdit_gmail -> text();


   if(!connOpen1()){
       qDebug() << "Failed to Open";

   }
   connOpen1();
   QSqlQuery qry;
   qry.prepare("update resort set name ='"+name+"' , description = '"+description+"'  where name ='"+name+"'");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("edit"),tr("updated"));
       connClose1();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }
}*/

void fourthDialog::on_pushButton_chittagongo_clicked()
{
    ctgadminsaveDialog op;
   op.setModal(true);
   op.exec();

}

void fourthDialog::on_pushButton_saintmartino_clicked()
{
    saintadminsaveDialog op;
   op.setModal(true);
   op.exec();
}

void fourthDialog::on_pushButton_sajecko_clicked()
{
    sajadminsaveDialog op;
   op.setModal(true);
   op.exec();
}

/*void fourthDialog::on_label_linkActivated(const QString &link)
{

}*/
