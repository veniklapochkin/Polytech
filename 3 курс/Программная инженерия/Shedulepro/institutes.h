#ifndef INSTITUTES_H
#define INSTITUTES_H

#include <QDialog>

namespace Ui {
class institutes;
}

class institutes : public QDialog
{
    Q_OBJECT

public:
    explicit institutes(QWidget *parent = 0);
    ~institutes();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::institutes *ui;
};

#endif // INSTITUTES_H
