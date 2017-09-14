#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdialog.h"
#include "mywidget.h"
#include "counter.h"

#include <QMouseEvent>
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>
#include <QWidget>
#include <QPainter>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("new button");

   //timer by singal and slot
    QTimer *t=new QTimer(this);
    connect(t,&QTimer::timeout,this,&MainWindow::timeupdate);
    t->start(1000);

    //timerevent
    timer1=startTimer(4000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    ui->pushButton->setText("click");
//   QDialog *dlg=new QDialog(this);
//   dlg->show();
    myWidget *wid=new myWidget();
    wid->show();
}
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    ui->pushButton->setText(tr("%1,%2").arg(e->x()).arg(e->y()));
}
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    int x=ui->pushButton->x();
    int y=ui->pushButton->y();
    switch(e->key())
    {
    case Qt::Key_W:
             ui->pushButton->move(x,y-20);
        break;
    case Qt::Key_S:
             ui->pushButton->move(x,y+20);
        break;
    case Qt::Key_A:
        ui->pushButton->move(x-20,y);
   break;
    case Qt::Key_D:
        ui->pushButton->move(x+20,y);
   break;
    default:
         ui->pushButton->move(x+66,y+66);
        break;
    }
    ui->pushButton->setText(tr("%1,%2").arg(ui->pushButton->x()).arg(ui->pushButton->y()));
}
void MainWindow::timeupdate()
{
    QDateTime time=QDateTime::currentDateTime();
    ui->label->setText(time.toString("yyyy-MM-dd hh:mm:ss dddd"));
    update();
//    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
//    int rand=qrand() % 200;
//      ui->pushButton->setText(tr("%1,%2").arg(rand).arg(rand));
//     ui->pushButton->move(rand,rand);
}
void MainWindow::timerEvent(QTimerEvent *e)
{
    killTimer(timer1);
//    QMessageBox message(QMessageBox::NoIcon,tr("%1 event").arg(e->timerId()),tr("boom"),QMessageBox::Yes|QMessageBox::No,NULL);
//    if (message.exec() == QMessageBox::Yes)
//          timer1=startTimer(4000);
}

void MainWindow::on_action_open_triggered()
{
    counter *coun=new counter();
    coun->show();
}
void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    //center (300,200)
    painter.setPen(QPen(QColor(0, 0, 0),4));
    painter.drawEllipse(220,120,160,160);

    painter.setPen(QPen(QColor(0, 0, 0)));
    painter.setBrush(QBrush(QColor(0,0,0)));
    painter.drawEllipse(295,195,10,10);

    qreal bx,by,ex,ey;
    for(int i=0;i<12;i++)
    {
        bx=300+qCos(qDegreesToRadians(double(i*30)))*80;
        by=200+qSin(qDegreesToRadians(double(i*30)))*80;
        if( i % 3 == 0)
       {
            ex=300+qCos(qDegreesToRadians(double(i*30)))*60;
            ey=200+qSin(qDegreesToRadians(double(i*30)))*60;
            painter.setPen(QPen(QColor(0, 0, 0),2));
        }
        else
        {
            ex=300+qCos(qDegreesToRadians(double(i*30)))*70;
            ey=200+qSin(qDegreesToRadians(double(i*30)))*70;
            painter.setPen(QPen(QColor(0, 0, 0),1));
        }
        painter.drawLine(bx,by,ex,ey);
    }

    //show time:second
    int second=QDateTime::currentDateTime().time().second();
    float minute=QDateTime::currentDateTime().time().minute() +(float)second/60;
    float hour=QDateTime::currentDateTime().time().hour()%12+minute/60;

    painter.setPen(QPen(QColor(0, 125, 0),2));
    bx=300+qSin(qDegreesToRadians(double(second*6)))*50;
    by=200-qCos(qDegreesToRadians(double(second*6)))*50;
    ex=300-qSin(qDegreesToRadians(double(second*6)))*10;
    ey=200+qCos(qDegreesToRadians(double(second*6)))*10;
 painter.drawLine(bx,by,ex,ey);

    painter.setPen(QPen(QColor(0, 75, 0),4));
    bx=300+qSin(qDegreesToRadians(double(minute*6)))*40;
    by=200-qCos(qDegreesToRadians(double(minute*6)))*40;
    ex=300-qSin(qDegreesToRadians(double(minute*6)))*6;
    ey=200+qCos(qDegreesToRadians(double(minute*6)))*6;
 painter.drawLine(bx,by,ex,ey);

    painter.setPen(QPen(QColor(0, 0, 0),6));
    bx=300+qSin(qDegreesToRadians(double(hour*30)))*20;
    by=200-qCos(qDegreesToRadians(double(hour*30)))*20;
    ex=300-qSin(qDegreesToRadians(double(hour*30)))*6;
    ey=200+qCos(qDegreesToRadians(double(hour*30)))*6;
    painter.drawLine(bx,by,ex,ey);
}
