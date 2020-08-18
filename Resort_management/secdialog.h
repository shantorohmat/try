#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT
public:
    QSqlDatabase db;
    void connClose()
    {
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/hp/adminlogin.db");




       if (db.open()) {
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
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SecDialog *ui;

};

#endif // SECDIALOG_H
