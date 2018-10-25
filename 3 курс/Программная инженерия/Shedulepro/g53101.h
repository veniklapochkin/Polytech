#ifndef G53101_H
#define G53101_H

#include <QDialog>

namespace Ui {
class G53101;
}

class G53101 : public QDialog
{
    Q_OBJECT

public:
    explicit G53101(QWidget *parent = 0);
    ~G53101();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::G53101 *ui;
};

#endif // G53101_H
