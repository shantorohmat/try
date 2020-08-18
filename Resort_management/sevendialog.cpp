#include "sevendialog.h"
#include "ui_sevendialog.h"

#include <chittagongdialog.h>
#include <saintmartindialog.h>
#include <sajeckdialog.h>

sevenDialog::sevenDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sevenDialog)
{
    ui->setupUi(this);
}

sevenDialog::~sevenDialog()
{
    delete ui;
}

/*void sevenDialog::on_pushButton_clicked()
{
    //MainWindow conn;

    QSqlQueryModel *modal = new QSqlQueryModel();

    //conn.connOpen5();

    connOpen71();

    //QSqlQuery *qry = new QSqlQuery(conn.db71);

    QSqlQuery *qry = new QSqlQuery(db71);

    qry->prepare("select * from chittaging");
    qry->exec();

    modal->setQuery(*qry);

    ui-> tableView-> setModel(modal);

    //conn.connClose1();
    connClose71();
    qDebug() << (modal->rowCount());
}*/

/*void sevenDialog::on_pushButton_chittagong_clicked()
{

}



void sevenDialog::on_pushButton_saintmartin_clicked()
{



}

void sevenDialog::on_pushButton_sajeck_clicked()
{


}*/

void sevenDialog::on_pushButton_chittagongx_clicked()
{
    chittagongDialog op;
   op.setModal(true);
   op.exec();
}

void sevenDialog::on_pushButton_saintmartinx_clicked()
{
   saintmartinDialog op;
   op.setModal(true);
   op.exec();
}

/*void sevenDialog::on_pushButton_saintmartin_2_clicked()
{
    saintmartinDialog op;
   op.setModal(true);
   op.exec();
}

void sevenDialog::on_pushButton_sajeck_2_clicked()
{

}*/

void sevenDialog::on_pushButton_sajeckx_clicked()
{
   sajeckDialog op;
   op.setModal(true);
   op.exec();
}
