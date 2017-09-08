#include "logindialog.h"
#include "ui_logindialog.h"
#include "mainwindow.h"
#include "QMessageBox"
#include <QString>
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->lineEdit_name->setText(tr("rhys"));
    ui->lineEdit_pw->setText(tr("asdfghjkl"));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{
     //int result = ui->lineEdit_name->text().toInt() +ui->lineEdit_pw->text().toInt();
      if (ui->lineEdit_name->text().trimmed() == tr("rhys") && ui->lineEdit_pw->text().trimmed() == tr("asdfghjkl"))
      {
           this->accept();
           //ui->pushButton->setText(QString::number(result,10));
      }
      else
      {
          QMessageBox::warning(this,tr("error"),tr("your passward or username is wrong"),QMessageBox::Yes);
      }
}
