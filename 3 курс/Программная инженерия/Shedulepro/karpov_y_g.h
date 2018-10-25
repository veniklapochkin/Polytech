#ifndef KARPOV_Y_G_H
#define KARPOV_Y_G_H

#include <QDialog>

namespace Ui {
class karpov_y_g;
}

class karpov_y_g : public QDialog
{
    Q_OBJECT

public:
    explicit karpov_y_g(QWidget *parent = 0);
    ~karpov_y_g();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::karpov_y_g *ui;
};

#endif // KARPOV_Y_G_H
