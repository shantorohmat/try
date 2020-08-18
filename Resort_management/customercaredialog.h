#ifndef CUSTOMERCAREDIALOG_H
#define CUSTOMERCAREDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class customercareDialog;
}

class customercareDialog : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db715care;
    void connClose715care()
    {
        db715care.close();
        db715care.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen715care()
    {
        db715care = QSqlDatabase::addDatabase("QSQLITE");
        db715care.setDatabaseName("C:/Users/hp/customer.db");


       if (db715care.open()) {
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
    explicit customercareDialog(QWidget *parent = nullptr);
    ~customercareDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::customercareDialog *ui;
};

#endif // CUSTOMERCAREDIALOG_H
