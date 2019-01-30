#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "cennik.h"
#include "rejestracja.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    QSqlDatabase mydb;

    void connectClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connectOpen()
    {
        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/sqlite/loginy.db");

        if(!mydb.open()){
            qDebug()<<("Disconnected");
            return false;
        }
        else
        {
            qDebug()<<("Conected to database");
            return true;
        }
    }

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_regbutton_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
