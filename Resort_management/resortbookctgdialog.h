#ifndef RESORTBOOKCTGDIALOG_H
#define RESORTBOOKCTGDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class resortbookctgDialog;
}

class resortbookctgDialog : public QDialog
{
    Q_OBJECT

 public:

    QSqlDatabase dbresctg;
    void connCloseresctg()
    {
        dbresctg.close();
        dbresctg.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpenresctg()
    {
        dbresctg = QSqlDatabase::addDatabase("QSQLITE");
        dbresctg.setDatabaseName("C:/Users/hp/chittagong.db");


       if (dbresctg.open()) {
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
    explicit resortbookctgDialog(QWidget *parent = nullptr);
    ~resortbookctgDialog();

private slots:
    void on_pushButton_identityresctg_clicked();

private:
    Ui::resortbookctgDialog *ui;
};

#endif // RESORTBOOKCTGDIALOG_H
