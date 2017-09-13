#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdialog.h"
#include "mywidget.h"
#include "counter.h"
#include "testaddwidget.h"
#include <QMouseEvent>
#include <QTimer>
#include <QDateTime>
#include <QMessageBox>
#include <QWidget>

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
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int rand=qrand() % 200;
      ui->pushButton->setText(tr("%1,%2").arg(rand).arg(rand));
     ui->pushButton->move(rand,rand);
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
