#ifndef CUSTOMERBOOKCTGDIALOG_H
#define CUSTOMERBOOKCTGDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class customerbookctgDialog;
}

class customerbookctgDialog : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase dbcusctg;
    void connClosecusctg()
    {
        dbcusctg.close();
        dbcusctg.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpencusctg()
    {
        dbcusctg = QSqlDatabase::addDatabase("QSQLITE");
        dbcusctg.setDatabaseName("C:/Users/hp/customer.db");


       if (dbcusctg.open()) {
        qDebug()<<("Database connected succesfully");
        return true;

       }
       else
       {
            qDebug()<<("Database not connected ");
            return false;
        }
    }

public:
    explicit customerbookctgDialog(QWidget *parent = nullptr);
    ~customerbookctgDialog();

private slots:
    void on_pushButton_updatecustomerctg_clicked();

private:
    Ui::customerbookctgDialog *ui;
};

#endif // CUSTOMERBOOKCTGDIALOG_H
