#ifndef SEVENDIALOG_H
#define SEVENDIALOG_H

#include <QDialog>

#include <QtSql>
#include <QDebug>
#include <QSqlDatabase>
#include <QFileInfo>


namespace Ui {
class sevenDialog;
}

class sevenDialog : public QDialog
{
    Q_OBJECT






public:
    explicit sevenDialog(QWidget *parent = nullptr);
    ~sevenDialog();

private slots:
    //void on_pushButton_clicked();

    //void on_pushButton_chittagong_clicked();

    //void on_pushButton_saintmartin_clicked();

    //void on_pushButton_3_clicked();

    //void on_pushButton_sajeck_clicked();

    void on_pushButton_chittagongx_clicked();

    void on_pushButton_saintmartinx_clicked();

    //void on_pushButton_saintmartin_2_clicked();

    //void on_pushButton_sajeck_2_clicked();

    void on_pushButton_sajeckx_clicked();

private:
    Ui::sevenDialog *ui;
};

#endif // SEVENDIALOG_H
