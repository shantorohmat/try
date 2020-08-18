#include "resortbooksaintdialog.h"
#include "ui_resortbooksaintdialog.h"

#include <QMessageBox>

resortbooksaintDialog::resortbooksaintDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resortbooksaintDialog)
{
    ui->setupUi(this);
}

resortbooksaintDialog::~resortbooksaintDialog()
{
    delete ui;
}

void resortbooksaintDialog::on_pushButton_identityressaint_clicked()
{
    //QString resortname = ui -> lineEdit_namec -> text();
    //QString description = ui -> lineEdit_descriptionc-> text();
    QString indentity = ui -> lineEdit_identityressaint -> text();
    QString eid = ui -> lineEdit_eidressaint -> text();


   if(!connOpenressaint()){
       qDebug() << "Failed to Open";

   }
   connOpenressaint();
   QSqlQuery qry;
   qry.prepare("update saintmartin set   identity = '"+indentity+"',eid = '"+eid+"' where eid = '"+eid+"'");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("edit"),tr("Booked"));
       connCloseressaint();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }

}
