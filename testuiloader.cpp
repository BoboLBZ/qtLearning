#include "testuiloader.h"
#include "ui_testuiloader.h"

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
