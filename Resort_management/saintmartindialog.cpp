#include "saintmartindialog.h"
#include "ui_saintmartindialog.h"

#include <customerbooksaintdialog.h>
#include <resortbooksaintdialog.h>

saintmartinDialog::saintmartinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saintmartinDialog)
{
    ui->setupUi(this);
}

saintmartinDialog::~saintmartinDialog()
{
    delete ui;
}

/*void saintmartinDialog::on_pushButton_saintmartin_clicked()
{

}*/

void saintmartinDialog::on_pushButton_saintmartiny_clicked()
{
    //MainWindow conn;

    QSqlQueryModel *modal = new QSqlQueryModel();

    //conn.connOpen5();

    connOpen72();

    //QSqlQuery *qry = new QSqlQuery(conn.db71);

    QSqlQuery *qry = new QSqlQuery(db72);

    qry->prepare("select * from saintmartin");
    qry->exec();

    modal->setQuery(*qry);

    ui-> tableView_saintmartiny-> setModel(modal);

    //conn.connClose1();
    connClose72();
    qDebug() << (modal->rowCount());

}

void saintmartinDialog::on_pushButton_customerbooksaint_clicked()
{
    customerbooksaintDialog op;
    op.setModal(true);
    op.exec();

}

void saintmartinDialog::on_pushButton_resortbooksaint_clicked()
{
    resortbooksaintDialog op;
    op.setModal(true);
    op.exec();

}
