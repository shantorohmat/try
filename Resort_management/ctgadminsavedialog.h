#ifndef CTGADMINSAVEDIALOG_H
#define CTGADMINSAVEDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class ctgadminsaveDialog;
}

class ctgadminsaveDialog : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase dbctg;
    void connClosectg()
    {
        dbctg.close();
        dbctg.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpenctg()
    {
        dbctg = QSqlDatabase::addDatabase("QSQLITE");
        dbctg.setDatabaseName("C:/Users/hp/chittagong.db");


       if (dbctg.open()) {
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
    explicit ctgadminsaveDialog(QWidget *parent = nullptr);
    ~ctgadminsaveDialog();

private slots:
    void on_pushButton_savec_clicked();

    void on_pushButton_updatec_clicked();

private:
    Ui::ctgadminsaveDialog *ui;
};

#endif // CTGADMINSAVEDIALOG_H
