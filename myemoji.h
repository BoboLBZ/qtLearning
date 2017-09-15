#ifndef MYEMOJI_H
#define MYEMOJI_H

#include <QWidget>

namespace Ui {
class MyEmoji;
}

class MyEmoji : public QWidget
{
    Q_OBJECT

public:
    explicit MyEmoji(QWidget *parent = 0);
    ~MyEmoji();
protected:
    void paintEvent(QPaintEvent *);
private:
    Ui::MyEmoji *ui;
};

#endif // MYEMOJI_H
