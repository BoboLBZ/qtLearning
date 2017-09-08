#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myWidget(QWidget *parent = 0);
    ~myWidget();

private:
    Ui::myWidget *ui;
    QPixmap pix;
    QPixmap temppix;
    QPoint lastPoint;
    QPoint endPoint;
    bool isDrawing;
protected:
    void paintEvent(QPaintEvent *event);
    //Graffiti board
    void  mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
};

#endif // MYWIDGET_H
