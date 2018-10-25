#ifndef SENICHENKOV_Y_B_H
#define SENICHENKOV_Y_B_H

#include <QDialog>

namespace Ui {
class senichenkov_y_b;
}

class senichenkov_y_b : public QDialog
{
    Q_OBJECT

public:
    explicit senichenkov_y_b(QWidget *parent = 0);
    ~senichenkov_y_b();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::senichenkov_y_b *ui;
};

#endif // SENICHENKOV_Y_B_H
