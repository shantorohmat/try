#ifndef SAINTMARTINDIALOG_H
#define SAINTMARTINDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class saintmartinDialog;
}

class saintmartinDialog : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db72;
    void connClose72()
    {
        db72.close();
        db72.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen72()
    {
        db72 = QSqlDatabase::addDatabase("QSQLITE");
        db72.setDatabaseName("C:/Users/hp/saintmartin.db");




       if (db72.open()) {
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
    explicit saintmartinDialog(QWidget *parent = nullptr);
    ~saintmartinDialog();

private slots:
    //void on_pushButton_saintmartin_clicked();

    void on_pushButton_saintmartiny_clicked();

    void on_pushButton_customerbooksaint_clicked();

    void on_pushButton_resortbooksaint_clicked();

private:
    Ui::saintmartinDialog *ui;
};

#endif // SAINTMARTINDIALOG_H
