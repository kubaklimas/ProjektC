#include "rejestracja.h"
#include "ui_rejestracja.h"
#include "mainwindow.h"
#include <QMessageBox>

Rejestracja::Rejestracja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rejestracja)
{
    ui->setupUi(this);
    MainWindow conn;
        if(!conn.connectOpen())
            ui->connlabel->setText("Disconnected");
        else
            ui->connlabel->setText("Connected to database");
}

Rejestracja::~Rejestracja()
{
    delete ui;
}

void Rejestracja::on_pushButton_clicked()
{
    MainWindow conn;
    QString log, pass;
    log = ui->linelogin->text();
    pass = ui->linepassword->text();

    if(!conn.connectOpen())
    {
        qDebug()<<"Błąd połączenia z bazą danych";
        return;
    }

    conn.connectOpen();
    QSqlQuery qr;
    qr.prepare("insert into testowa (login,password) values ('"+log+"','"+pass+"')");

    if(qr.exec())
    {
        QMessageBox::critical(this,tr("Info"),tr("Zapisano dane"));
        conn.connectClose();
    }
    else
    {
       QMessageBox::critical(this,tr("error::"),qr.lastError().text()) ;
    }
}
