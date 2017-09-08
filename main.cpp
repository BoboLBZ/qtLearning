#include "mainwindow.h"
#include <QApplication>
#include <logindialog.h>
#include <readxml.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
    //last
//    LoginDialog ld;
//    if(ld.exec() == QDialog::Accepted)
//    {
//        MainWindow w;
//        w.show();
//        return a.exec();
//    }
//    else
//        return 0;
    //current ,test readXML
    readXML r;
    r.show();
    return a.exec();
}
