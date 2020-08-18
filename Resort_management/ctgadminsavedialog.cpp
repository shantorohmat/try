#include "ctgadminsavedialog.h"
#include "ui_ctgadminsavedialog.h"

#include <QMessageBox>

ctgadminsaveDialog::ctgadminsaveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ctgadminsaveDialog)
{
    ui->setupUi(this);
}

ctgadminsaveDialog::~ctgadminsaveDialog()
{
    delete ui;
}

void ctgadminsaveDialog::on_pushButton_savec_clicked()
{
    QString resortname = ui -> lineEdit_namec -> text();
    QString description = ui -> lineEdit_descriptionc-> text();
    QString indentity = ui -> lineEdit_identityc -> text();
    QString eid = ui -> lineEdit_eidc -> text();



   if(!connOpenctg()){
       qDebug() << "Failed to Open";

   }
   connOpenctg();
   QSqlQuery qry;
   qry.prepare("insert into chittagong  (resortname,description,identity,eid) values('"+resortname+"' , '"+description+"','"+indentity+"','"+eid+"')");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("save"),tr("saved"));
       connClosectg();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }

}

void ctgadminsaveDialog::on_pushButton_updatec_clicked()
{
    QString resortname = ui -> lineEdit_namec -> text();
    QString description = ui -> lineEdit_descriptionc-> text();
    QString indentity = ui -> lineEdit_identityc -> text();
    QString eid = ui -> lineEdit_eidc -> text();


   if(!connOpenctg()){
       qDebug() << "Failed to Open";

   }
   connOpenctg();
   QSqlQuery qry;
   qry.prepare("update chittagong set resortname ='"+resortname+"' , description = '"+description+"' , identity = '"+indentity+"',eid = '"+eid+"' where resortname ='"+resortname+"'");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("edit"),tr("updated"));
       connClosectg();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }

}
