#include "resortbookctgdialog.h"
#include "ui_resortbookctgdialog.h"

#include <QMessageBox>

resortbookctgDialog::resortbookctgDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resortbookctgDialog)
{
    ui->setupUi(this);
}

resortbookctgDialog::~resortbookctgDialog()
{
    delete ui;
}

void resortbookctgDialog::on_pushButton_identityresctg_clicked()
{
    //QString resortname = ui -> lineEdit_namec -> text();
    //QString description = ui -> lineEdit_descriptionc-> text();
    QString indentity = ui -> lineEdit_identityresctg -> text();
    QString eid = ui -> lineEdit_eidresctg -> text();


   if(!connOpenresctg()){
       qDebug() << "Failed to Open";

   }
   connOpenresctg();
   QSqlQuery qry;
   qry.prepare("update chittagong set   identity = '"+indentity+"',eid = '"+eid+"' where eid = '"+eid+"'");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("edit"),tr("Booked"));
       connCloseresctg();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }
}
