#ifndef TIMOFEEV_D_A_H
#define TIMOFEEV_D_A_H

#include <QDialog>

namespace Ui {
class timofeev_d_a;
}

class timofeev_d_a : public QDialog
{
    Q_OBJECT

public:
    explicit timofeev_d_a(QWidget *parent = 0);
    ~timofeev_d_a();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::timofeev_d_a *ui;
};

#endif // TIMOFEEV_D_A_H
