#ifndef CUSTOMERBOOKSAJECKDIALOG_H
#define CUSTOMERBOOKSAJECKDIALOG_H

#include <QDialog>


#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class customerbooksajeckDialog;
}

class customerbooksajeckDialog : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase dbcussajeck;
    void connClosecussajeck()
    {
        dbcussajeck.close();
        dbcussajeck.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpencussajeck()
    {
        dbcussajeck = QSqlDatabase::addDatabase("QSQLITE");
        dbcussajeck.setDatabaseName("C:/Users/hp/customer.db");


       if (dbcussajeck.open()) {
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
    explicit customerbooksajeckDialog(QWidget *parent = nullptr);
    ~customerbooksajeckDialog();

private slots:
    void on_pushButton_updatecustomersajeck_clicked();

private:
    Ui::customerbooksajeckDialog *ui;
};

#endif // CUSTOMERBOOKSAJECKDIALOG_H
