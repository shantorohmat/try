#ifndef SAINTADMINSHOWDIALOG_H
#define SAINTADMINSHOWDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class saintadminshowDialog;
}

class saintadminshowDialog : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db716;
    void connClose716()
    {
        db716.close();
        db716.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen716()
    {
        db716 = QSqlDatabase::addDatabase("QSQLITE");
        //db716.setDatabaseName("C:/Users/hp/saintmartin.db");
        db716.setDatabaseName("C:/Users/hp/saintmartin.db");



       if (db716.open()) {
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
    explicit saintadminshowDialog(QWidget *parent = nullptr);
    ~saintadminshowDialog();

private slots:
    void on_pushButton_sm_clicked();

private:
    Ui::saintadminshowDialog *ui;
};

#endif // SAINTADMINSHOWDIALOG_H
