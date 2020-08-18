#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class ThirdDialog;
}

class ThirdDialog : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db3rd;
    void connClose3rd()
    {
        db3rd.close();
        db3rd.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen3rd()
    {
        db3rd = QSqlDatabase::addDatabase("QSQLITE");
        db3rd.setDatabaseName("C:/Users/hp/adminlogin.db");


       if (db3rd.open()) {
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
    explicit ThirdDialog(QWidget *parent = nullptr);
    ~ThirdDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::ThirdDialog *ui;
};

#endif // THIRDDIALOG_H
