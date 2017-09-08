#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
    resize(600,600);
    pix=QPixmap(600,600);
    pix.fill(Qt::white);
    isDrawing=false;
}

myWidget::~myWidget()
{
    delete ui;
}
void myWidget::paintEvent(QPaintEvent *event)
{
//   QPainter painter(this);
//    painter.drawLine(QPointF(0, 0), QPointF(100, 100));

    //矩形
//    QPainter painter(this);
//    QPen pen;
//    pen.setColor(QColor(255, 0, 0));
//    QBrush brush(QColor(0, 255, 0, 125)); //画刷
//    painter.setPen(pen); //添加画笔
//    painter.setBrush(brush); //添加画刷
//    painter.drawRect(50, 50, 200, 100); //绘制矩形

    //弧线
//      QRectF rectangle(10.0, 20.0, 80.0, 60.0); //矩形
//       int startAngle = 30 * 16;     //起始角度
//       int spanAngle = 120 * 16;   //跨越度数
//       QPainter painter(this);
//       painter.drawArc(rectangle, startAngle, spanAngle);

   //文字
//   painter.drawText(100,200,"hello world!");

   //路径
//   QPainterPath path;
//   path.addEllipse(100,100,50,50);
//    path.lineTo(300,300);
//   painter.setPen(Qt::red);
//   painter.setBrush(Qt::yellow);
//   painter.drawPath(path);
//   //copy path
//   QPainterPath pathcopy;
//   pathcopy.addPath(path);
//   pathcopy.translate(200,0);
//   painter.drawPath(pathcopy);

   //Graffiti board
//  QPainter pp(&pix);
//  pp.drawLine(lastPoint,endPoint);
//  lastPoint=endPoint;
//  QPainter painter(this);
//  painter.drawPixmap(0,0,pix);

    //double buffers
    int x,y,w,h;
    x=lastPoint.x();
    y=lastPoint.y();
    w=endPoint.x()-x;
    h=endPoint.y()-y;
     QPainter painter(this);
     if (isDrawing)
     {
       temppix=pix;
       QPainter pp(&temppix);
        pp.drawRect(x,y,w,h);
        painter.drawPixmap(0,0,temppix);
    }
     else
     {
         QPainter pp(&pix);
          pp.drawRect(x,y,w,h);
          painter.drawPixmap(0,0,pix);
     }
}
void myWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
       {
        lastPoint=e->pos();
        isDrawing=true; //for double
       }
    //endPoint=lastPoint;
}
void myWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        endPoint=e->pos();
        isDrawing=false;//for double
        update();
    }
}
void myWidget::mouseMoveEvent(QMouseEvent * e)
{
    if (e->buttons() & Qt::LeftButton)
    {
        endPoint=e->pos();
        update();
    }
}
