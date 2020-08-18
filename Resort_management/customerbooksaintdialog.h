#ifndef CUSTOMERBOOKSAINTDIALOG_H
#define CUSTOMERBOOKSAINTDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>


namespace Ui {
class customerbooksaintDialog;
}

class customerbooksaintDialog : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase dbcussaint;
    void connClosecussaint()
    {
        dbcussaint.close();
        dbcussaint.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpencussaint()
    {
        dbcussaint = QSqlDatabase::addDatabase("QSQLITE");
        dbcussaint.setDatabaseName("C:/Users/hp/customer.db");


       if (dbcussaint.open()) {
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
    explicit customerbooksaintDialog(QWidget *parent = nullptr);
    ~customerbooksaintDialog();

private slots:
    void on_pushButton_updatecustomersaint_clicked();

private:
    Ui::customerbooksaintDialog *ui;
};

#endif // CUSTOMERBOOKSAINTDIALOG_H
