#ifndef FIVEDIALOG_H
#define FIVEDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class fiveDialog;
}

class fiveDialog : public QDialog
{
    Q_OBJECT

/*public:
    QSqlDatabase db5;
    void connClose5()
    {
        db5.close();
        db5.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen5()
    {
        db5 = QSqlDatabase::addDatabase("QSQLITE");
        db5.setDatabaseName("C:/Users/hp/resort.db");




       if (db5.open()) {
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
    explicit fiveDialog(QWidget *parent = nullptr);
    ~fiveDialog();

private slots:
    //void on_pushButton_showresort_clicked();

    void on_pushButton_chit_clicked();

    void on_pushButton_martin_clicked();

    void on_pushButton_sajeck_clicked();

private:
    Ui::fiveDialog *ui;
};

#endif // FIVEDIALOG_H
