#ifndef G63507_H
#define G63507_H

#include <QDialog>

namespace Ui {
class G63507;
}

class G63507 : public QDialog
{
    Q_OBJECT

public:
    explicit G63507(QWidget *parent = 0);
    ~G63507();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::G63507 *ui;
};

#endif // G63507_H
