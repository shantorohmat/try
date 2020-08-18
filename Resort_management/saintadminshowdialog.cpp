#include "saintadminshowdialog.h"
#include "ui_saintadminshowdialog.h"

saintadminshowDialog::saintadminshowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saintadminshowDialog)
{
    ui->setupUi(this);
}

saintadminshowDialog::~saintadminshowDialog()
{
    delete ui;
}

void saintadminshowDialog::on_pushButton_sm_clicked()
{
    //MainWindow conn;

    QSqlQueryModel *modal = new QSqlQueryModel();

    //conn.connOpen5();

    connOpen716();

    //QSqlQuery *qry = new QSqlQuery(conn.db71);

    QSqlQuery *qry = new QSqlQuery(db716);

    qry->prepare("select * from saintmartin");
    qry->exec();

    modal->setQuery(*qry);

    ui-> tableView_sm-> setModel(modal);

    //conn.connClose1();
    connClose716();
    qDebug() << (modal->rowCount());
}
