#include "customercaredialog.h"
#include "ui_customercaredialog.h"

#include <QMessageBox>

customercareDialog::customercareDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customercareDialog)
{
    ui->setupUi(this);
}

customercareDialog::~customercareDialog()
{
    delete ui;
}

void customercareDialog::on_pushButton_clicked()
{
    //MainWindow conn;

    QSqlQueryModel *modal = new QSqlQueryModel();

    //conn.connOpen5();

    connOpen715care();

    //QSqlQuery *qry = new QSqlQuery(conn.db71);

    QSqlQuery *qry = new QSqlQuery(db715care);

    qry->prepare("select * from customer");
    qry->exec();

    modal->setQuery(*qry);

    ui-> tableView_custoercare-> setModel(modal);

    //conn.connClose1();
    connClose715care();
    qDebug() << (modal->rowCount());
}
