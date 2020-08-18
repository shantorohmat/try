#ifndef FOURTHDIALOG_H
#define FOURTHDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class fourthDialog;
}

class fourthDialog : public QDialog
{
    Q_OBJECT
/*public:
    QSqlDatabase db1;
    void connClose1()
    {
        db1.close();
        db1.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen1()
    {
        db1 = QSqlDatabase::addDatabase("QSQLITE");
        db1.setDatabaseName("C:/Users/hp/resort.db");


       if (db1.open()) {
        qDebug()<<("Database connected succesfully");
        return true;

       }
       else
       {
            qDebug()<<("Database not connected ");
            return false;
        }
    }*/

public:
    explicit fourthDialog(QWidget *parent = nullptr);
    ~fourthDialog();

private slots:
    //void on_pushButton_2_clicked();

    //void on_pushButton_clicked();

    void on_pushButton_chittagongo_clicked();

    void on_pushButton_saintmartino_clicked();

    void on_pushButton_sajecko_clicked();

    //void on_label_linkActivated(const QString &link);

private:
    Ui::fourthDialog *ui;
};

#endif // FOURTHDIALOG_H
