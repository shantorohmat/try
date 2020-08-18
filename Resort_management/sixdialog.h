#ifndef SIXDIALOG_H
#define SIXDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>


namespace Ui {
class sixDialog;
}

class sixDialog : public QDialog
{
    Q_OBJECT
public:
    QSqlDatabase db6;
    void connClose6()
    {
        db6.close();
        db6.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen6()
    {
        db6 = QSqlDatabase::addDatabase("QSQLITE");
        db6.setDatabaseName("C:/Users/hp/customer.db");


       if (db6.open()) {
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
    explicit sixDialog(QWidget *parent = nullptr);
    ~sixDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::sixDialog *ui;
};

#endif // SIXDIALOG_H
