#include "chittagongdialog.h"
#include "ui_chittagongdialog.h"


#include <resortbookctgdialog.h>
#include <customerbookctgdialog.h>


chittagongDialog::chittagongDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chittagongDialog)
{
    ui->setupUi(this);
}

chittagongDialog::~chittagongDialog()
{
    delete ui;
}

/*void chittagongDialog::on_pushButton_showresort_clicked()
{

}*/

void chittagongDialog::on_pushButton_showresortz_clicked()
{
    //MainWindow conn;

    QSqlQueryModel *modal = new QSqlQueryModel();

    //conn.connOpen5();

    connOpen71();

    //QSqlQuery *qry = new QSqlQuery(conn.db71);

    QSqlQuery *qry = new QSqlQuery(db71);

    qry->prepare("select * from chittagong");
    qry->exec();

    modal->setQuery(*qry);

    ui-> tableView_showresortz-> setModel(modal);

    //conn.connClose1();
    connClose71();
    qDebug() << (modal->rowCount());

}
/*void ctgadminshowDialog::on_pushButton_resortbook_clicked()
{
    resortbookctgDialog op;
    op.setModal(true);
    op.exec();

}

void ctgadminshowDialog::on_pushButton_customerbook_clicked()
{
    customerbookctgDialog op;
    op.setModal(true);
    op.exec();


}*/

void chittagongDialog::on_pushButton_resortbook_clicked()
{
    resortbookctgDialog op;
    op.setModal(true);
    op.exec();
}

void chittagongDialog::on_pushButton_customerbook_clicked()
{
    customerbookctgDialog op;
    op.setModal(true);
    op.exec();

}
