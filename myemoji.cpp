#include "myemoji.h"
#include "ui_myemoji.h"

#include <QPainter>

MyEmoji::MyEmoji(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyEmoji)
{
    ui->setupUi(this);
    resize(420,420);
}

MyEmoji::~MyEmoji()
{
    delete ui;
}
void MyEmoji::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //center (300,200)
    painter.setPen(QPen(QColor(255,215,0)));
    painter.setBrush(QBrush(QColor(255,215,0)));
    painter.drawEllipse(0,0,200,200);
    //128,42,42 zongse
    painter.setPen(QPen(QColor(128,42,42)));
    painter.setBrush(QBrush(QColor(128,42,42)));
    painter.drawEllipse(35,85,30,30);
    painter.drawEllipse(135,85,30,30);
    //smile
    painter.setPen(QPen(QColor(255,255,255)));
    painter.setBrush(QBrush(QColor(255,255,255)));
    painter.drawPie(QRectF(50,110,100,60),180*16,180*16);

    //
    //x->220
    painter.setPen(QPen(QColor(255,215,0)));
    painter.setBrush(QBrush(QColor(255,215,0)));
    painter.drawEllipse(0+220,0,200,200);
    //128,42,42 zongse
    painter.setPen(QPen(QColor(128,42,42)));
    painter.setBrush(QBrush(QColor(128,42,42)));
    painter.drawEllipse(35+220,85,30,30);
    painter.drawEllipse(135+220,85,30,30);
     painter.drawPie(QRectF(50+220+15,140,70,60),0*16,180*16);

     //y ->220
     painter.setPen(QPen(QColor(255,215,0)));
     painter.setBrush(QBrush(QColor(255,215,0)));
     painter.drawEllipse(0,0+220,200,200);
     //128,42,42 zongse
     painter.setPen(QPen(QColor(128,42,42)));
     painter.setBrush(QBrush(QColor(128,42,42)));
     painter.drawPie(QRectF(30,80+220,40,40),0*16,180*16);
     painter.drawPie(QRectF(30+100,80+220,40,40),0*16,180*16);

     painter.setPen(QPen(QColor(255,255,255)));
     painter.setBrush(QBrush(QColor(255,255,255)));
     painter.drawPie(QRectF(50,110+220,100,60),180*16,180*16);

     painter.setPen(QPen(QColor(108,178,204)));
     painter.setBrush(QBrush(QColor(108,178,204)));
     painter.drawRoundedRect(QRectF(0,0+220,200,30),15,15);

     //y->220,x->200
     painter.setPen(QPen(QColor(255,215,0)));
     painter.setBrush(QBrush(QColor(255,215,0)));
     painter.drawEllipse(0+220,0+220,200,200);
     //128,42,42 zongse
     painter.setPen(QPen(QColor(128,42,42)));
     painter.setBrush(QBrush(QColor(128,42,42)));

     painter.drawPie(QRectF(30+220,80+220,40,40),0*16,180*16);
     painter.drawPie(QRectF(30+220+100,80+220,40,40),0*16,180*16);

     painter.drawPie(QRectF(50+220,110+220,100,60),180*16,180*16);

     int r1=42,x=64+220,y=68+220,angle1=85,angle2=60;
     QPen pen(QColor(128,42,42),16);
     pen.setCapStyle(Qt::RoundCap);
     painter.setPen(pen);
     painter.drawArc(QRectF(x-r1,y-r1,r1*2,r1*2),angle1*16,angle2*16);
     painter.drawArc(QRectF(x-r1+72,y-r1,r1*2,r1*2),(180-angle1-angle2)*16,angle2*16);

     painter.setPen(QPen(QColor( 138,43,226),5));
     painter.setFont(QFont("Times", 20, QFont::Bold));
     painter.drawText(150,215,"Hahaha Rhys --->");
}
