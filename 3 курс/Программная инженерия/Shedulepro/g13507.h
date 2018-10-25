#ifndef G13507_H
#define G13507_H

#include <QDialog>

namespace Ui {
class G13507;
}

class G13507 : public QDialog
{
    Q_OBJECT

public:
    explicit G13507(QWidget *parent = 0);
    ~G13507();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::G13507 *ui;
};

#endif // G13507_H
