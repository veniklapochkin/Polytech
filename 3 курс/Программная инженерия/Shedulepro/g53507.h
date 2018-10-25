#ifndef G53507_H
#define G53507_H

#include <QDialog>

namespace Ui {
class G53507;
}

class G53507 : public QDialog
{
    Q_OBJECT

public:
    explicit G53507(QWidget *parent = 0);
    ~G53507();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::G53507 *ui;
};

#endif // G53507_H
