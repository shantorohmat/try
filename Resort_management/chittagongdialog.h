#ifndef CHITTAGONGDIALOG_H
#define CHITTAGONGDIALOG_H

#include <QDialog>


#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>


namespace Ui {
class chittagongDialog;
}

class chittagongDialog : public QDialog
{
    Q_OBJECT
public:
    QSqlDatabase db71;
    void connClose71()
    {
        db71.close();
        db71.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen71()
    {
        db71 = QSqlDatabase::addDatabase("QSQLITE");
        db71.setDatabaseName("C:/Users/hp/chittagong.db");


       if (db71.open()) {
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
    explicit chittagongDialog(QWidget *parent = nullptr);
    ~chittagongDialog();

private slots:
    //void on_pushButton_showresort_clicked();

    void on_pushButton_showresortz_clicked();

    void on_pushButton_resortbook_clicked();

    void on_pushButton_customerbook_clicked();

private:
    Ui::chittagongDialog *ui;
};

#endif // CHITTAGONGDIALOG_H
