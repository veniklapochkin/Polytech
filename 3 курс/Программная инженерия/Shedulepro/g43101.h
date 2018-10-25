#ifndef G43101_H
#define G43101_H

#include <QDialog>

namespace Ui {
class G43101;
}

class G43101 : public QDialog
{
    Q_OBJECT

public:
    explicit G43101(QWidget *parent = 0);
    ~G43101();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::G43101 *ui;
};

#endif // G43101_H
