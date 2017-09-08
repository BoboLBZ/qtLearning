#ifndef READXML_H
#define READXML_H

#include <QDialog>

namespace Ui {
class readXML;
}

class readXML : public QDialog
{
    Q_OBJECT

public:
    explicit readXML(QWidget *parent = 0);
    ~readXML();

private:
    Ui::readXML *ui;
protected:
    void createxml();
    void readxml();
    void readxmlByStream();
    void addnode(QString ititle,QString iauthor);
    bool xmlOperate(QString opType);
private slots:
    void on_pushButton_show_clicked();
    void on_pushButton_add_clicked();

    void on_pushButton_find_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_update_clicked();
};

#endif // READXML_H
