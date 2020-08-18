#include "customerbookctgdialog.h"
#include "ui_customerbookctgdialog.h"
#include <QMessageBox>

customerbookctgDialog::customerbookctgDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerbookctgDialog)
{
    ui->setupUi(this);
}

customerbookctgDialog::~customerbookctgDialog()
{
    delete ui;
}

void customerbookctgDialog::on_pushButton_updatecustomerctg_clicked()
{
    QString identity = ui -> lineEdit_identityctg -> text();
    QString eid = ui -> lineEdit_eidctg-> text();
    QString gmail = ui -> lineEdit_gmailctg -> text();


   if(!connOpencusctg()){
       qDebug() << "Failed to Open";

   }
   connOpencusctg();
   QSqlQuery qry;
   qry.prepare("update customer set identity ='"+identity+"' , eid = '"+eid+"' , gmail = '"+gmail+"' where gmail = '"+gmail+"'");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("edit"),tr("Booked"));
       connClosecusctg();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }
}
