#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase db1;
    void connClose1()
    {
        db1.close();
        db1.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen1()
    {
        db1 = QSqlDatabase::addDatabase("QSQLITE");
        db1.setDatabaseName("C:/Users/hp/place.db");




       if (db1.open()) {
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
    QSqlDatabase db10;
    void connClose10()
    {
        db10.close();
        db10.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen10()
    {
        db10 = QSqlDatabase::addDatabase("QSQLITE");
        db10.setDatabaseName("C:/Users/hp/customer.db");




       if (db10.open()) {
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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
