#include "readxml.h"
#include "ui_readxml.h"
#include <QtXml/qdom.h>
#include <QtXml/QtXml>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
readXML::readXML(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::readXML)
{
    ui->setupUi(this);
    writexmlByStream();
  //  createxml();
//    readxml();
}

readXML::~readXML()
{
    delete ui;
}
void readXML::createxml()
{
    QFile file("first.xml");
    if( !file.open(QIODevice::WriteOnly|QIODevice::Truncate))
        return;
    QDomDocument doc;
    QDomProcessingInstruction instruction;
    instruction=doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);

    QDomElement root=doc.createElement("bookstore");
    doc.appendChild(root);

    //first
    QDomElement book=doc.createElement("book");
    QDomAttr id=doc.createAttribute("id");
    QDomElement title=doc.createElement("title");
    QDomElement author=doc.createElement("author");

    QDomText text;
    text=doc.createTextNode("123");
    title.appendChild(text);
    text=doc.createTextNode("rhys");
    author.appendChild(text);
    id.setValue("1");

    book.setAttributeNode(id);
    book.appendChild(title);
    book.appendChild(author);

    root.appendChild(book);

    //second
     book=doc.createElement("book");
     id=doc.createAttribute("id");
     title=doc.createElement("title");
     author=doc.createElement("author");

    text=doc.createTextNode("456");
    title.appendChild(text);
    text=doc.createTextNode("liu");
    author.appendChild(text);
    id.setValue("2");

    book.setAttributeNode(id);
    book.appendChild(title);
    book.appendChild(author);

    root.appendChild(book);

    //save file
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}
void readXML::readxml(QString filename)
{
     QFile file(filename);
     if( !file.open(QIODevice::ReadOnly)) return;
     QDomDocument doc;
     if( !doc.setContent(&file))
     {
         file.close();
         return;
     }
     file.close();

     QDomElement docElem=doc.documentElement();
     QDomNode node=docElem.firstChild();
     while( !node.isNull())
     {
         if( node.isElement())
         {
             QDomElement elem=node.toElement();
             ui->listWidget_showXML->addItem(elem.tagName() + elem.attribute(tr("id")));
             QDomNodeList lists=elem.childNodes();
             for(int i=0;i<lists.length();i++)
             {
                 QDomNode n=lists.at(i);
                 if( n.isElement())
                 {
                     ui->listWidget_showXML->addItem("    " + n.toElement().tagName()+":"+n.toElement().text());
                 }
             }
         }
         node=node.nextSibling();
     }
}
void readXML::readxmlByStream()
{
    QFile file("first.xml");
    if ( !file.open(QFile::ReadOnly|QFile::Text))
        return;
    QXmlStreamReader reader;
    reader.setDevice(&file);
    while( !reader.atEnd())
    {
        QXmlStreamReader::TokenType type=reader.readNext();
        QString dis="";
        if (type == QXmlStreamReader::StartDocument)
        {
            dis+=reader.documentEncoding().toString() + " "+reader.documentVersion().toString();
        }
        else  if(type == QXmlStreamReader::StartElement)
        {
            dis+="< "+reader.name().toString()+" > ";
            if (reader.attributes().hasAttribute("id"))
                dis+=reader.attributes().value("id").toString();
        }
        else if(type == QXmlStreamReader::EndElement)
        {
            dis+="";
        }
        else if(type ==QXmlStreamReader::Characters && !reader.isWhitespace())
        {
            dis+=reader.text().toString();
        }
        if ( dis.length() > 0)
            ui->listWidget_showXML->addItem(dis);
    }
    if (reader.hasError())
        ui->listWidget_showXML->addItem("error:"+reader.errorString());
    file.close();
}
void readXML::writexmlByStream()
{
    QFile file("xmlwriteByStream.xml");
    if (!file.open(QFile::WriteOnly|QFile::Text))
        return ;
    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("books");
    writer.writeStartElement("book");
    writer.writeAttribute("id","1");
    writer.writeTextElement("title","110");
    writer.writeTextElement("author","ttt");
    writer.writeEndElement();
    writer.writeEndElement();
    writer.writeEndDocument();
    file.close();
}

void readXML::addnode(QString ititle, QString iauthor)
{
    QFile file("first.xml");
    if( !file.open(QIODevice::ReadOnly)) return;
    QDomDocument doc;
    if( !doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root=doc.documentElement();
    QDomElement book=doc.createElement("book");
    QDomAttr id=doc.createAttribute("id");
    QDomElement title=doc.createElement("title");
    QDomElement author=doc.createElement("author");
    QDomText text;

    QString num=root.lastChild().toElement().attribute("id");
    id.setValue(QString::number(num.toInt()+1));
    text=doc.createTextNode(ititle);
    title.appendChild(text);
    text=doc.createTextNode(iauthor);
    author.appendChild(text);

    book.setAttributeNode(id);
    book.appendChild(title);
    book.appendChild(author);

    root.appendChild(book);

    //save file
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
            return ;
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}
bool readXML::xmlOperate(QString opType)
{
    QFile file("first.xml");
    if( !file.open(QIODevice::ReadOnly)) return false;
    QDomDocument doc;
    if( !doc.setContent(&file))
    {
        file.close();
        return false;
    }
    file.close();

    QDomNodeList lists=doc.elementsByTagName("book");
    for(int i=0;i<lists.length();i++)
    {
        QDomElement e=lists.at(i).toElement();
        if(e.attribute("id") == ui->lineEdit_id->text())
        {
            if(opType == "delete")
            {
                  QDomElement root=doc.documentElement();
                  root.removeChild(lists.at(i));
                  //save
                  QFile file("first.xml");
                 if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
                      return false ;
                  QTextStream out(&file);
                  doc.save(out,4);
                  file.close();
                  return true;
            }
            else if(opType == "update")
            {
                QDomNodeList childlist=lists.at(i).childNodes();
                childlist.at(0).toElement().firstChild().setNodeValue(ui->lineEdit_title->text());
                childlist.at(1).toElement().firstChild().setNodeValue(ui->lineEdit_author->text());
                //save
                QFile file("first.xml");
               if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
                    return false ;
                QTextStream out(&file);
                doc.save(out,4);
                file.close();
                return true;
            }
            else
            {
                QDomNodeList childlist=e.childNodes();
                ui->listWidget_showXML->clear();
                ui->listWidget_showXML->addItem(e.tagName() + e.attribute(tr("id")));
                for(int i=0;i<childlist.length();i++)
                {
                    QDomNode n=childlist.at(i);
                    if( n.isElement())
                    {
                        ui->listWidget_showXML->addItem("    " + n.toElement().tagName()+":"+n.toElement().text());
                    }
                }
                return true;
            }
        }
    }
}

void readXML::on_pushButton_show_clicked()
{
   ui->listWidget_showXML->clear();
   readxml( ui->lineEdit_filename->text() );
   // readxml("xmlwriteByStream.xml");
   //readxmlByStream();
}

void readXML::on_pushButton_add_clicked()
{
       addnode(ui->lineEdit_title->text(),ui->lineEdit_author->text());
       ui->listWidget_showXML->clear();
       readxml("first.xml");
}

void readXML::on_pushButton_find_clicked()
{
    ui->listWidget_showXML->clear();
    if ( !xmlOperate("find"))
         ui->listWidget_showXML->addItem("can't find the book");
}

void readXML::on_pushButton_delete_clicked()
{
    ui->listWidget_showXML->clear();
    if ( !xmlOperate("delete"))
         ui->listWidget_showXML->addItem("delete book failed");
    else
        ui->listWidget_showXML->addItem("success to delete the book");
}

void readXML::on_pushButton_update_clicked()
{
    ui->listWidget_showXML->clear();
    if ( !xmlOperate("update"))
         ui->listWidget_showXML->addItem("update book information failed");
    else
        ui->listWidget_showXML->addItem("success to update the book");
}
