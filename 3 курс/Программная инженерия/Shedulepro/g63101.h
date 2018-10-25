#ifndef G63101_H
#define G63101_H

#include <QDialog>

namespace Ui {
class G63101;
}

class G63101 : public QDialog
{
    Q_OBJECT

public:
    explicit G63101(QWidget *parent = 0);
    ~G63101();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::G63101 *ui;
};

#endif // G63101_H
