#ifndef G33101_H
#define G33101_H

#include <QDialog>

namespace Ui {
class G33101;
}

class G33101 : public QDialog
{
    Q_OBJECT

public:
    explicit G33101(QWidget *parent = 0);
    ~G33101();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::G33101 *ui;
};

#endif // G33101_H
