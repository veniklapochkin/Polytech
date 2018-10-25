#ifndef G43507_H
#define G43507_H

#include <QDialog>

namespace Ui {
class G43507;
}

class G43507 : public QDialog
{
    Q_OBJECT

public:
    explicit G43507(QWidget *parent = 0);
    ~G43507();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::G43507 *ui;
};

#endif // G43507_H
