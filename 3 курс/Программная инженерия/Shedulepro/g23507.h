#ifndef G23507_H
#define G23507_H

#include <QDialog>

namespace Ui {
class G23507;
}

class G23507 : public QDialog
{
    Q_OBJECT

public:
    explicit G23507(QWidget *parent = 0);
    ~G23507();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::G23507 *ui;
};

#endif // G23507_H
