#ifndef CTGADMINSHOWDIALOG_H
#define CTGADMINSHOWDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class ctgadminshowDialog;
}

class ctgadminshowDialog : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db715;
    void connClose715()
    {
        db715.close();
        db715.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen715()
    {
        db715 = QSqlDatabase::addDatabase("QSQLITE");
        db715.setDatabaseName("C:/Users/hp/chittagong.db");


       if (db715.open()) {
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
    explicit ctgadminshowDialog(QWidget *parent = nullptr);
    ~ctgadminshowDialog();

private slots:
    void on_pushButton_gong_clicked();

    //void on_pushButton_clicked();

   // void on_pushButton_resortbook_clicked();

    //void on_pushButton_customerbook_clicked();

private:
    Ui::ctgadminshowDialog *ui;
};

#endif // CTGADMINSHOWDIALOG_H
