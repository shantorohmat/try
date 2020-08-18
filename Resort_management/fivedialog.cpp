#include "fivedialog.h"
#include "ui_fivedialog.h"

#include <ctgadminshowdialog.h>
#include <saintadminshowdialog.h>
#include <sajsdminshowdialog.h>

fiveDialog::fiveDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fiveDialog)
{
    ui->setupUi(this);
}

fiveDialog::~fiveDialog()
{
    delete ui;
}

/*void fiveDialog::on_pushButton_showresort_clicked()
{
    //MainWindow conn;

    QSqlQueryModel *modal = new QSqlQueryModel();

    //conn.connOpen5();

    connOpen5();

    //QSqlQuery *qry = new QSqlQuery(conn.db5);

    QSqlQuery *qry = new QSqlQuery(db5);

    qry->prepare("select * from resort");
    qry->exec();

    modal->setQuery(*qry);

    ui-> tableView-> setModel(modal);

    //conn.connClose1();
    connClose5();
    qDebug() << (modal->rowCount());
}*/

void fiveDialog::on_pushButton_chit_clicked()
{
    ctgadminshowDialog op;
    op.setModal(true);
    op.exec();
}

void fiveDialog::on_pushButton_martin_clicked()
{
    saintadminshowDialog op;
    op.setModal(true);
    op.exec();

}

void fiveDialog::on_pushButton_sajeck_clicked()
{
    sajsdminshowDialog op;
    op.setModal(true);
    op.exec();

}
