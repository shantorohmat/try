#include "sixdialog.h"
#include "ui_sixdialog.h"

#include <QMessageBox>


sixDialog::sixDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sixDialog)
{
    ui->setupUi(this);
}

sixDialog::~sixDialog()
{
    delete ui;
}

void sixDialog::on_pushButton_clicked()
{
    //QString username = ui -> lineEdit_username -> text();
    QString password = ui -> lineEdit_passworda-> text();
    QString gmail = ui -> lineEdit_gmaila -> text();


   if(!connOpen6()){
       qDebug() << "Failed to Open";

   }
   connOpen6();
   QSqlQuery qry;
   qry.prepare("insert into customer  (gmail,password) values('"+gmail+"', '"+password+"')");
   if(qry.exec())
   {
       QMessageBox::critical(this,tr("save"),tr("saved"));
       connClose6();
   }
   else
   {
       QMessageBox :: critical(this,tr("error::"),qry.lastError().text());
   }
}
