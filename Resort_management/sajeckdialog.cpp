#include "sajeckdialog.h"
#include "ui_sajeckdialog.h"

#include <resortbooksajeckdialog.h>
#include <customerbooksajeckdialog.h>

sajeckDialog::sajeckDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sajeckDialog)
{
    ui->setupUi(this);
}

sajeckDialog::~sajeckDialog()
{
    delete ui;
}

void sajeckDialog::on_pushButton_showresorta_clicked()
{
    //MainWindow conn;

    QSqlQueryModel *modal = new QSqlQueryModel();

    //conn.connOpen5();

    connOpen73();

    //QSqlQuery *qry = new QSqlQuery(conn.db73);

    QSqlQuery *qry = new QSqlQuery(db73);

    qry->prepare("select * from sajeck");
    qry->exec();

    modal->setQuery(*qry);

    ui-> tableView_showresortb-> setModel(modal);

    //conn.connClose1();
    connClose73();
    qDebug() << (modal->rowCount());
}

void sajeckDialog::on_pushButton_resortbook_clicked()
{
    resortbooksajeckDialog op;
    op.setModal(true);
    op.exec();

}

void sajeckDialog::on_pushButton_customerbook_clicked()
{
    customerbooksajeckDialog op;
    op.setModal(true);
    op.exec();
}
