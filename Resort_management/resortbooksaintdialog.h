#ifndef RESORTBOOKSAINTDIALOG_H
#define RESORTBOOKSAINTDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>


namespace Ui {
class resortbooksaintDialog;
}

class resortbooksaintDialog : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase dbressaint;
    void connCloseressaint()
    {
        dbressaint.close();
        dbressaint.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpenressaint()
    {
        dbressaint = QSqlDatabase::addDatabase("QSQLITE");
        dbressaint.setDatabaseName("C:/Users/hp/saintmartin.db");


       if (dbressaint.open()) {
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
    explicit resortbooksaintDialog(QWidget *parent = nullptr);
    ~resortbooksaintDialog();

private slots:
    void on_pushButton_identityressaint_clicked();

private:
    Ui::resortbooksaintDialog *ui;
};

#endif // RESORTBOOKSAINTDIALOG_H
