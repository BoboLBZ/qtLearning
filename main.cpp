#include "mainwindow.h"
#include <QApplication>
#include <logindialog.h>
#include <readxml.h>
#include <testuiloader.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
    //last
    LoginDialog ld;
    if(ld.exec() == QDialog::Accepted)
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    else
        return 0;
    //current ,test readXML
    //xml
//    readXML r;
//    r.show();
//    return a.exec();

    //test ui loader
//    TestUILoader l;
//    l.show();

//    MainWindow w;
//    w.show();

    return a.exec();
}
