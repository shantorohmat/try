#include "customerbooksaintdialog.h"
#include "ui_customerbooksaintdialog.h"

#include <QMessageBox>

customerbooksaintDialog::customerbooksaintDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerbooksaintDialog)
{
    ui->setupUi(this);
}

customerbooksaintDialog::~customerbooksaintDialog()
{
    delete ui;
}

void customerbooksaintDialog::on_pushButton_updatecustomersaint_clicked()
{

    QString identity = ui -> lineEdit_identitysaint -> text();
    QString eid = ui -> lineEdit_eidsaint-> text();
    QString gmail = ui -> lineEdit_gmailsaint -> text();


   if(!connOpencussaint()){
       qDebug() << "Failed to Open";

   }
   connOpencussaint();
   QSqlQuery qry;
   qry.prepare("update customer set identity ='"+identity+"' , eid = '"+eid+"' , gmail = '"+gmail+"' where gmail = '"+gmail+"'");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("edit"),tr("Booked"));
       connClosecussaint();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }

}
