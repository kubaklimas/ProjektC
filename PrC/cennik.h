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

private:
    Ui::cennik *ui;
};

#endif // CENNIK_H
