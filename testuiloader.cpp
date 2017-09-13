#include "testuiloader.h"
#include "ui_testuiloader.h"
#include  <QtUiTools/QUiLoader>
#include <QFile>
#include <QWidget>
#include <QListWidget>
#include <QDebug>
#include <QVBoxLayout>
TestUILoader::TestUILoader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestUILoader)
{

    ui->setupUi(this);
}

TestUILoader::~TestUILoader()
{
    delete ui;
}

void TestUILoader::loaderUI(QString filepath)
{
    QUiLoader loader;
    QFile uifile(filepath);
    uifile.open(QFile::ReadOnly);
    QWidget *qwidget=loader.load(&uifile, this);
     uifile.close();
    //qwidget->showNormal();
    qwidget->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    qwidget->move(0,0);
    qwidget->show();
//     QVBoxLayout *layout=new QVBoxLayout;
//     layout->addWidget(qwidget);
//     setLayout(layout);
}

void TestUILoader::on_actionadd_triggered()
{
    loaderUI("E:\\RhysCode\\myWindows\\readxml.ui");
}
