#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void timeupdate();

    void on_action_open_triggered();

private:
    Ui::MainWindow *ui;
    int timer1;
protected:
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void timerEvent(QTimerEvent *e);
    void paintEvent(QPaintEvent *e);
};

#endif // MAINWINDOW_H
