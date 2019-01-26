#ifndef CENNIK_H
#define CENNIK_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class cennik;
}

class cennik : public QDialog
{
    Q_OBJECT

public:

    explicit cennik(QWidget *parent = 0);
    ~cennik();

private slots:
    void on_savebutton_clicked();

    void on_loadbutton_clicked();

    void on_editbutton_clicked();

    void on_deletebutton_clicked();

    void on_listbutton_clicked();

    void on_tabela_mala_activated(const QModelIndex &index);

    void on_tableView_activated(const QModelIndex &index);

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::cennik *ui;
};

#endif // CENNIK_H
