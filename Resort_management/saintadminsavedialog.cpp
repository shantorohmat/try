#include "saintadminsavedialog.h"
#include "ui_saintadminsavedialog.h"

#include <QMessageBox>

saintadminsaveDialog::saintadminsaveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saintadminsaveDialog)
{
    ui->setupUi(this);
}

saintadminsaveDialog::~saintadminsaveDialog()
{
    delete ui;
}

void saintadminsaveDialog::on_pushButton_saves_clicked()
{
    QString resortname = ui -> lineEdit_names -> text();
    QString description = ui -> lineEdit_descriptions-> text();
    QString indentity = ui -> lineEdit_identitys -> text();
    QString eid = ui -> lineEdit_eids -> text();



   if(!connOpensaint()){
       qDebug() << "Failed to Open";

   }
   connOpensaint();
   QSqlQuery qry;
   qry.prepare("insert into saintmartin  (resortname,description,identity,eid) values('"+resortname+"' , '"+description+"','"+indentity+"','"+eid+"')");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("save"),tr("saved"));
       connClosesaint();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }
}

void saintadminsaveDialog::on_pushButton_updates_clicked()
{
    QString resortname = ui -> lineEdit_names -> text();
    QString description = ui -> lineEdit_descriptions-> text();
    QString indentity = ui -> lineEdit_identitys -> text();
    QString eid = ui -> lineEdit_eids -> text();


   if(!connOpensaint()){
       qDebug() << "Failed to Open";

   }
   connOpensaint();
   QSqlQuery qry;
   qry.prepare("update saintmartin set resortname ='"+resortname+"' , description = '"+description+"' , identity = '"+indentity+"',eid = '"+eid+"' where resortname ='"+resortname+"'");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("edit"),tr("updated"));
       connClosesaint();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }
}
