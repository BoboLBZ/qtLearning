#ifndef TESTUILOADER_H
#define TESTUILOADER_H

#include <QMainWindow>

namespace Ui {
class TestUILoader;
}

class TestUILoader : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestUILoader(QWidget *parent = 0);
    ~TestUILoader();
protected:
    void loaderUI(QString filepath);
private slots:


    void on_actionadd_triggered();

private:
    Ui::TestUILoader *ui;
};

#endif // TESTUILOADER_H
