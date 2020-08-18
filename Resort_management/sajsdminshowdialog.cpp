#include "sajsdminshowdialog.h"
#include "ui_sajsdminshowdialog.h"

sajsdminshowDialog::sajsdminshowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sajsdminshowDialog)
{
    ui->setupUi(this);
}

sajsdminshowDialog::~sajsdminshowDialog()
{
    delete ui;
}

void sajsdminshowDialog::on_pushButton_sjc_clicked()
{
    //MainWindow conn;

    QSqlQueryModel *modal = new QSqlQueryModel();

    //conn.connOpen5();

    connOpen717();

    //QSqlQuery *qry = new QSqlQuery(conn.db71);

    QSqlQuery *qry = new QSqlQuery(db717);

    qry->prepare("select *from sajeck");
    qry->exec();

    modal->setQuery(*qry);

    ui-> tableView_sjc-> setModel(modal);

    //conn.connClose1();
    connClose717();
    qDebug() << (modal->rowCount());
}
