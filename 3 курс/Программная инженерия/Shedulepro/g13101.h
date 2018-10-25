#ifndef G13101_H
#define G13101_H

#include <QDialog>

namespace Ui {
class G13101;
}

class G13101 : public QDialog
{
    Q_OBJECT

public:
    explicit G13101(QWidget *parent = 0);
    ~G13101();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::G13101 *ui;
};

#endif // G13101_H
