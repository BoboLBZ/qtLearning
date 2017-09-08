#include "counter.h"
#include "ui_counter.h"
#include <QtDebug>

counter::counter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::counter)
{
    ui->setupUi(this);
    display="";
    tempString="";
    result=0;
    leftOp=0;
    rightOp=0;
    opflag=false;
}
void counter::inputNumber(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' )
    {
      opflag=true;
      op=c;
      tempString="";
      leftOp=result;
    }
    else if ( c != '=')
    {
        tempString.append(c);
    }
    display.append(c);
    ui->label_dispaly->setText(display);
    calculate();
    if (c == '=')
    {
        display=display+QString::number(result);
         ui->label_dispaly->setText(display);
         display="";
         tempString="";
         result=0;
         leftOp=0;
         rightOp=0;
         opflag=false;
    }
}
void counter::calculate()
{
    if (opflag== false)
         result= tempString.toDouble();
    else  if (tempString.length() == 0)
    {
        leftOp=result;
    }
    else{
        rightOp=tempString.toDouble();
        switch (op) {
        case '+':
            result=leftOp+rightOp;
            break;
        case '-':
            result=leftOp-rightOp;
            break;
        case '*':
            result=leftOp*rightOp;
            break;
        case '/':
            result=leftOp/rightOp;
            break;
        default:
            break;
         }
    }
    ui->label_result->setText(QString::number(result));
}

void counter::on_pushButton_del_clicked()
{
    int l=display.length();
    display=display.left(l-1);
    ui->label_dispaly->setText(display);
    std::string cn=display.toStdString();
    const char  *temp=cn.c_str();
    display="";
    tempString="";
    result=0;
    leftOp=0;
    rightOp=0;
    opflag=false;
    for(int i=0;i<l-1;i++)
    {
       // qDebug()<<temp[i];
        inputNumber(temp[i]);
    }
}
void counter::on_pushButton_equal_clicked()
{
     inputNumber('=');
}
counter::~counter()
{
    delete ui;
}

void counter::on_pushButton_7_clicked()
{
    inputNumber('7');
}

void counter::on_pushButton_plus_clicked()
{
    inputNumber('+');
}

void counter::on_pushButton_sub_clicked()
{
     inputNumber('-');
}

void counter::on_pushButton_mul_clicked()
{
     inputNumber('*');
}

void counter::on_pushButton_div_clicked()
{
     inputNumber('/');
}

void counter::on_pushButton_8_clicked()
{
     inputNumber('8');
}

void counter::on_pushButton_9_clicked()
{
     inputNumber('9');
}

void counter::on_pushButton_4_clicked()
{
     inputNumber('4');
}

void counter::on_pushButton_6_clicked()
{
     inputNumber('6');
}

void counter::on_pushButton_3_clicked()
{
     inputNumber('3');
}

void counter::on_pushButton_2_clicked()
{
     inputNumber('2');
}

void counter::on_pushButton_dot_clicked()
{
     inputNumber('.');
}

void counter::on_pushButton_0_clicked()
{
     inputNumber('0');
}


void counter::on_pushButton_1_clicked()
{
     inputNumber('1');
}

void counter::on_pushButton_5_clicked()
{
    inputNumber('5');
}
