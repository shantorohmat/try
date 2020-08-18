#include "sajadminsavedialog.h"
#include "ui_sajadminsavedialog.h"

#include <QMessageBox>

sajadminsaveDialog::sajadminsaveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sajadminsaveDialog)
{
    ui->setupUi(this);
}

sajadminsaveDialog::~sajadminsaveDialog()
{
    delete ui;
}

void sajadminsaveDialog::on_pushButton_savesaj_clicked()
{
    QString resortname = ui -> lineEdit_namesaj -> text();
    QString description = ui -> lineEdit_descriptionsaj-> text();
    QString indentity = ui -> lineEdit_identitysaj -> text();
    QString eid = ui -> lineEdit_eidsaj -> text();



   if(!connOpensajk()){
       qDebug() << "Failed to Open";

   }
   connOpensajk();
   QSqlQuery qry;
   qry.prepare("insert into sajeck  (resortname,description,identity,eid) values('"+resortname+"' , '"+description+"','"+indentity+"','"+eid+"')");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("save"),tr("saved"));
       connClossajk();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }
}

void sajadminsaveDialog::on_pushButton_updatesaj_clicked()
{
    QString resortname = ui -> lineEdit_namesaj -> text();
    QString description = ui -> lineEdit_descriptionsaj-> text();
    QString indentity = ui -> lineEdit_identitysaj -> text();
    QString eid = ui -> lineEdit_eidsaj -> text();


   if(!connOpensajk()){
       qDebug() << "Failed to Open";

   }
   connOpensajk();
   QSqlQuery qry;
   qry.prepare("update sajeck set resortname ='"+resortname+"' , description = '"+description+"' , identity = '"+indentity+"',eid = '"+eid+"' where resortname ='"+resortname+"'");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("edit"),tr("updated"));
       connClossajk();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }
}
