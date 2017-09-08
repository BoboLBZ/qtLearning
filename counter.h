#ifndef COUNTER_H
#define COUNTER_H

#include <QDialog>
#include <QStack>

namespace Ui {
class counter;
}

class counter : public QDialog
{
    Q_OBJECT

public:
    explicit counter(QWidget *parent = 0);
    ~counter();
protected:
    void inputNumber(char c);
    void calculate();
private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::counter *ui;
    QString display;
    QString tempString;
    double  result;
    double  leftOp;
    double  rightOp;
    char op;
    bool opflag;
};

#endif // COUNTER_H
