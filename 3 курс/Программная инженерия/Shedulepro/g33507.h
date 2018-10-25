#ifndef G33507_H
#define G33507_H

#include <QDialog>

namespace Ui {
class G33507;
}

class G33507 : public QDialog
{
    Q_OBJECT

public:
    explicit G33507(QWidget *parent = 0);
    ~G33507();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::G33507 *ui;
};

#endif // G33507_H
