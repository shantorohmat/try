#include "ctgadminshowdialog.h"
#include "ui_ctgadminshowdialog.h"



ctgadminshowDialog::ctgadminshowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ctgadminshowDialog)
{
    ui->setupUi(this);
}

ctgadminshowDialog::~ctgadminshowDialog()
{
    delete ui;
}

void ctgadminshowDialog::on_pushButton_gong_clicked()
{
    //MainWindow conn;

    QSqlQueryModel *modal = new QSqlQueryModel();

    //conn.connOpen5();

    connOpen715();

    //QSqlQuery *qry = new QSqlQuery(conn.db71);

    QSqlQuery *qry = new QSqlQuery(db715);

    qry->prepare("select * from chittagong");
    qry->exec();

    modal->setQuery(*qry);

    ui-> tableView_gong-> setModel(modal);

    //conn.connClose1();
    connClose715();
    qDebug() << (modal->rowCount());
}

/*void ctgadminshowDialog::on_pushButton_clicked()
{

}*/


