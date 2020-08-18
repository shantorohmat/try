#ifndef SAINTADMINSAVEDIALOG_H
#define SAINTADMINSAVEDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>


namespace Ui {
class saintadminsaveDialog;
}

class saintadminsaveDialog : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase dbsaint;
    void connClosesaint()
    {
        dbsaint.close();
        dbsaint.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpensaint()
    {
        dbsaint = QSqlDatabase::addDatabase("QSQLITE");
        dbsaint.setDatabaseName("C:/Users/hp/saintmartin.db");


       if (dbsaint.open()) {
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
    explicit saintadminsaveDialog(QWidget *parent = nullptr);
    ~saintadminsaveDialog();

private slots:
    void on_pushButton_saves_clicked();

    void on_pushButton_updates_clicked();

private:
    Ui::saintadminsaveDialog *ui;
};

#endif // SAINTADMINSAVEDIALOG_H
