#ifndef REJESTRACJA_H
#define REJESTRACJA_H

#include <QDialog>

namespace Ui {
class Rejestracja;
}

class Rejestracja : public QDialog
{
    Q_OBJECT

public:
    explicit Rejestracja(QWidget *parent = 0);
    ~Rejestracja();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Rejestracja *ui;
};

#endif // REJESTRACJA_H
