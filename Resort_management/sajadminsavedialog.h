#ifndef SAJADMINSAVEDIALOG_H
#define SAJADMINSAVEDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>



namespace Ui {
class sajadminsaveDialog;
}

class sajadminsaveDialog : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase dbsajk;
    void connClossajk()
    {
        dbsajk.close();
        dbsajk.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpensajk()
    {
        dbsajk = QSqlDatabase::addDatabase("QSQLITE");
        dbsajk.setDatabaseName("C:/Users/hp/sajeck.db");


       if (dbsajk.open()) {
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
    explicit sajadminsaveDialog(QWidget *parent = nullptr);
    ~sajadminsaveDialog();

private slots:
    void on_pushButton_savesaj_clicked();

    void on_pushButton_updatesaj_clicked();

private:
    Ui::sajadminsaveDialog *ui;
};

#endif // SAJADMINSAVEDIALOG_H
