#include "customerbooksajeckdialog.h"
#include "ui_customerbooksajeckdialog.h"

#include <QMessageBox>

customerbooksajeckDialog::customerbooksajeckDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerbooksajeckDialog)
{
    ui->setupUi(this);
}

customerbooksajeckDialog::~customerbooksajeckDialog()
{
    delete ui;
}

void customerbooksajeckDialog::on_pushButton_updatecustomersajeck_clicked()
{
    QString identity = ui -> lineEdit_identitysajeck -> text();
    QString eid = ui -> lineEdit_eidsajeck-> text();
    QString gmail = ui -> lineEdit_gmailsajeck -> text();


   if(!connOpencussajeck()){
       qDebug() << "Failed to Open";

   }
   connOpencussajeck();
   QSqlQuery qry;
   qry.prepare("update customer set identity ='"+identity+"' , eid = '"+eid+"' , gmail = '"+gmail+"' where gmail = '"+gmail+"'");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("edit"),tr("Booked"));
       connClosecussajeck();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }
}
