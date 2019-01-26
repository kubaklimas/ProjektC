#include "cennik.h"
#include "ui_cennik.h"
#include <QMessageBox>

cennik::cennik(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cennik)
{
    ui->setupUi(this);
    MainWindow conn;
        if(!conn.connectOpen())
            ui->connstatus->setText("Disconnected");
        else
            ui->connstatus->setText("Connected to database");
}

cennik::~cennik()
{
    delete ui;
}

void cennik::on_savebutton_clicked()
{
    MainWindow conn;
    QString nazwa, adres,pb95,pb98,ON,LPG;
    nazwa = ui->linenazwa->text();
    adres = ui->lineadres->text();
    pb95 = ui->linepb95->text();
    pb98 = ui->linepb98->text();
    ON = ui->lineON->text();
    LPG = ui->linelpg->text();

    if(!conn.connectOpen())
    {
        qDebug()<<"Błąd połączenia z bazą danych";
        return;
    }

    conn.connectOpen();
    QSqlQuery qr;
    qr.prepare("insert into testp (name,adress,paliwo95,paliwo98,olej,lpg) values ('"+nazwa+"','"+adres+"','"+pb95+"','"+pb98+"','"+ON+"','"+LPG+"')");

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

void cennik::on_loadbutton_clicked()
{
    MainWindow tabela;
    QSqlQueryModel * nowy = new QSqlQueryModel();
    tabela.connectOpen();
    QSqlQuery* qr=new QSqlQuery(tabela.mydb);

    qr->prepare("select * from testp");
    qr->exec();

    nowy->setQuery(*qr);
    ui->tableView->setModel(nowy);

    tabela.connectClose();
    qDebug() << (nowy->rowCount());
}

void cennik::on_editbutton_clicked()
{
    MainWindow conn;
    QString nazwa, adres,pb95,pb98,ON,LPG;
    nazwa = ui->linenazwa->text();
    adres = ui->lineadres->text();
    pb95 = ui->linepb95->text();
    pb98 = ui->linepb98->text();
    ON = ui->lineON->text();
    LPG = ui->linelpg->text();

    if(!conn.connectOpen())
    {
        qDebug()<<"Błąd połączenia z bazą danych";
        return;
    }

    conn.connectOpen();
    QSqlQuery qr;
    qr.prepare("update testp set name='"+nazwa+"',adress='"+adres+"',paliwo95='"+pb95+"',paliwo98='"+pb98+"',olej='"+ON+"',lpg='"+LPG+"' where adress='"+adres+"'");

    if(qr.exec())
    {
        QMessageBox::critical(this,tr("Info"),tr("Zaktualizowano dane"));
        conn.connectClose();
    }
    else
    {
       QMessageBox::critical(this,tr("error::"),qr.lastError().text()) ;
    }
}

void cennik::on_deletebutton_clicked()
{
    MainWindow conn;
    QString nazwa, adres,pb95,pb98,ON,LPG;
    adres = ui->lineadres->text();


    if(!conn.connectOpen())
    {
        qDebug()<<"Błąd połączenia z bazą danych";
        return;
    }

    conn.connectOpen();
    QSqlQuery qr;
    qr.prepare("delete from testp where adress='"+adres+"'");

    if(qr.exec())
    {
        QMessageBox::critical(this,tr("Info"),tr("Usunięto dane"));
        conn.connectClose();
    }
    else
    {
       QMessageBox::critical(this,tr("error::"),qr.lastError().text()) ;
    }
}

void cennik::on_listbutton_clicked()
{
    MainWindow tabela;
    QSqlQueryModel * nowy = new QSqlQueryModel();
    tabela.connectOpen();
    QSqlQuery* qr=new QSqlQuery(tabela.mydb);

    qr->prepare("select name from testp");
    qr->exec();

    nowy->setQuery(*qr);
    ui->tabela_mala->setModel(nowy);
    ui->comboBox->setModel(nowy);

    tabela.connectClose();
    qDebug() << (nowy->rowCount());
}

void cennik::on_tableView_activated(const QModelIndex &index)
{
    QString var=ui->tableView->model()->data(index).toString();

    MainWindow conn;
    if(!conn.connectOpen())
    {
        qDebug()<<"Błąd połączenia z bazą danych";
        return;
    }

    conn.connectOpen();
    QSqlQuery qr;
    qr.prepare("select * from testp where name='"+var+"' or adress='"+var+"' or paliwo95='"+var+"' or paliwo98='"+var+"' or olej='"+var+"' or lpg='"+var+"'");

    if(qr.exec())
    {
        while(qr.next())
        {
          ui->linenazwa->setText(qr.value(0).toString());
          ui->lineadres->setText(qr.value(1).toString());
          ui->linepb95->setText(qr.value(2).toString());
          ui->linepb98->setText(qr.value(3).toString());
          ui->lineON->setText(qr.value(4).toString());
          ui->linelpg->setText(qr.value(5).toString());
        }
        conn.connectClose();
    }
    else
    {
       QMessageBox::critical(this,tr("error::"),qr.lastError().text()) ;
    }
}

void cennik::on_tabela_mala_activated(const QModelIndex &index)
{

}

void cennik::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString name=ui->comboBox->currentText();

    MainWindow conn;


    if(!conn.connectOpen())
    {
        qDebug()<<"Błąd połączenia z bazą danych";
        return;
    }

    conn.connectOpen();
    QSqlQuery qr;
    qr.prepare("select * from testp where name='"+name+"'");

    if(qr.exec())
    {
        while(qr.next())
        {
          ui->linenazwa->setText(qr.value(0).toString());
          ui->lineadres->setText(qr.value(1).toString());
          ui->linepb95->setText(qr.value(2).toString());
          ui->linepb98->setText(qr.value(3).toString());
          ui->lineON->setText(qr.value(4).toString());
          ui->linelpg->setText(qr.value(5).toString());
        }
        conn.connectClose();
    }
    else
    {
       QMessageBox::critical(this,tr("error::"),qr.lastError().text()) ;
    }
}
