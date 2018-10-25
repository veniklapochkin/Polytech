#ifndef G23101_H
#define G23101_H

#include <QDialog>

namespace Ui {
class G23101;
}

class G23101 : public QDialog
{
    Q_OBJECT

public:
    explicit G23101(QWidget *parent = 0);
    ~G23101();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::G23101 *ui;
};

#endif // G23101_H
