#include "resortbooksajeckdialog.h"
#include "ui_resortbooksajeckdialog.h"

#include <QMessageBox>

resortbooksajeckDialog::resortbooksajeckDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resortbooksajeckDialog)
{
    ui->setupUi(this);
}

resortbooksajeckDialog::~resortbooksajeckDialog()
{
    delete ui;
}

void resortbooksajeckDialog::on_pushButton_identityressajeck_clicked()
{
    //QString resortname = ui -> lineEdit_namec -> text();
    //QString description = ui -> lineEdit_descriptionc-> text();
    QString indentity = ui -> lineEdit_identityressajeck -> text();
    QString eid = ui -> lineEdit_eidressajeck -> text();


   if(!connOpenressajeck()){
       qDebug() << "Failed to Open";

   }
   connOpenressajeck();
   QSqlQuery qry;
   qry.prepare("update sajeck set   identity = '"+indentity+"',eid = '"+eid+"' where eid = '"+eid+"'");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("edit"),tr("Booked"));
       connCloseressajeck();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }

}
