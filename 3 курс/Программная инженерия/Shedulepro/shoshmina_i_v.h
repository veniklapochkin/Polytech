#ifndef SHOSHMINA_I_V_H
#define SHOSHMINA_I_V_H

#include <QDialog>

namespace Ui {
class shoshmina_i_v;
}

class shoshmina_i_v : public QDialog
{
    Q_OBJECT

public:
    explicit shoshmina_i_v(QWidget *parent = 0);
    ~shoshmina_i_v();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::shoshmina_i_v *ui;
};

#endif // SHOSHMINA_I_V_H
