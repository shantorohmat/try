#ifndef SAJECKDIALOG_H
#define SAJECKDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class sajeckDialog;
}

class sajeckDialog : public QDialog
{
    Q_OBJECT


public:
    QSqlDatabase db73;
    void connClose73()
    {
        db73.close();
        db73.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen73()
    {
        db73 = QSqlDatabase::addDatabase("QSQLITE");
        db73.setDatabaseName("C:/Users/hp/sajeck.db");




       if (db73.open()) {
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
    explicit sajeckDialog(QWidget *parent = nullptr);
    ~sajeckDialog();

private slots:
    void on_pushButton_showresorta_clicked();

    void on_pushButton_resortbook_clicked();

    void on_pushButton_customerbook_clicked();

private:
    Ui::sajeckDialog *ui;
};

#endif // SAJECKDIALOG_H
