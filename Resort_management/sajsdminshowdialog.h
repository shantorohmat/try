#ifndef SAJSDMINSHOWDIALOG_H
#define SAJSDMINSHOWDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class sajsdminshowDialog;
}

class sajsdminshowDialog : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db717;
    void connClose717()
    {
        db717.close();
        db717.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen717()
    {
        db717 = QSqlDatabase::addDatabase("QSQLITE");
        db717.setDatabaseName("C:/Users/hp/sajeck.db");


       if (db717.open()) {
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
    explicit sajsdminshowDialog(QWidget *parent = nullptr);
    ~sajsdminshowDialog();

private slots:
    void on_pushButton_sjc_clicked();

private:
    Ui::sajsdminshowDialog *ui;
};

#endif // SAJSDMINSHOWDIALOG_H
