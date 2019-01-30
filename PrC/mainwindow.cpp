#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(!connectOpen())
        ui->label->setText("Disconnected");
    else
        ui->label->setText("Connected to database");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username, password;
    username=ui->lineEdit_login->text();
    password=ui->lineEdit_haslo->text();

    if(!connectOpen())
    {
        qDebug()<<"Błąd połączenia z bazą danych";
        return;
    }

    connectOpen();
    QSqlQuery qr;
    qr.prepare("select * from testowa where login='"+username+"' and password='"+password+"'");

    if(qr.exec())
    {
        int a = 0;
        while(qr.next())
        {
            a++;
        }
        if (a==1)
        {
            ui->Sprawdzanko->setText("Zalogowano");

            connectClose();

            this->hide();
            cennik Cennik;
            Cennik.setModal(true);
            Cennik.exec();
        }
        if (a>1)
            ui->Sprawdzanko->setText("Zdublowana nazwa użytkownika");
        if (a<1)
            ui->Sprawdzanko->setText("Błędny dane");
    }

}

void MainWindow::on_regbutton_clicked()
{
    Rejestracja reje;
    reje.setModal(true);
    reje.exec();
}
