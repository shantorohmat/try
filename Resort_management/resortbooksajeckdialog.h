#ifndef RESORTBOOKSAJECKDIALOG_H
#define RESORTBOOKSAJECKDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>

namespace Ui {
class resortbooksajeckDialog;
}

class resortbooksajeckDialog : public QDialog
{
    Q_OBJECT

public:

   QSqlDatabase dbressajeck;
   void connCloseressajeck()
   {
       dbressajeck.close();
       dbressajeck.removeDatabase(QSqlDatabase::defaultConnection);
   }
   bool connOpenressajeck()
   {
       dbressajeck = QSqlDatabase::addDatabase("QSQLITE");
       dbressajeck.setDatabaseName("C:/Users/hp/sajeck.db");


      if (dbressajeck.open()) {
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
    explicit resortbooksajeckDialog(QWidget *parent = nullptr);
    ~resortbooksajeckDialog();

private slots:
    void on_pushButton_identityressajeck_clicked();

private:
    Ui::resortbooksajeckDialog *ui;
};

#endif // RESORTBOOKSAJECKDIALOG_H
