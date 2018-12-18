#include "cennik.h"
#include "ui_cennik.h"


cennik::cennik(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cennik)
{
    ui->setupUi(this);
    MainWindow conn;
        if(!conn.connectOpen())
            ui->connstatus->setText("Disconnected");
        else
            ui->connstatus->setText("Conected to database");
}

cennik::~cennik()
{
    delete ui;
}
