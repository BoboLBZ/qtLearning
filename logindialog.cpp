#include "logindialog.h"
#include "ui_logindialog.h"
#include "mainwindow.h"
#include "QMessageBox"
#include <QString>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->lineEdit_name->setText(tr("rhys"));
    ui->lineEdit_pw->setText(tr("123456"));
    //connect database
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("myuserinfo");
    db.setUserName("root");
    db.setPassword("");
    if ( !db.open())
    {
        QMessageBox::warning(this,tr("error"),tr("connect database error"),QMessageBox::Yes);
    }
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{
     //int result = ui->lineEdit_name->text().toInt() +ui->lineEdit_pw->text().toInt();

        QSqlQuery query;
        query.exec("select * from user where name=\""+ui->lineEdit_name->text().trimmed() + "\"");
         if(query.next())
        {
            if(query.value(1).toString() == ui->lineEdit_pw->text().trimmed())
                this->accept();
        }
         QMessageBox::warning(this,tr("error"),tr("your passward or username is wrong"),QMessageBox::Yes);

        //without database;
//      if (ui->lineEdit_name->text().trimmed() == tr("rhys") && ui->lineEdit_pw->text().trimmed() == tr("asdfghjkl"))
//      {
//           this->accept();
//           //ui->pushButton->setText(QString::number(result,10));
//      }
//      else
//      {
//          QMessageBox::warning(this,tr("error"),tr("your passward or username is wrong"),QMessageBox::Yes);
//      }

}
