#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QByteArray>
#include <QDebug>
#include <QCryptographicHash>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //  QT解析QJsonObject和QJsonArray以及和QByteArray之间的相互转换
    //http://blog.csdn.net/qq1263292336/article/details/50379317
#if 0
    QByteArray md5 = QCryptographicHash::hash(QByteArray("xgl123"),QCryptographicHash::Md5);

    QJsonObject obj;
    obj.insert("username", QString("xgl"));
    obj.insert("password", QString(md5.toHex()));
    obj.insert("male", true);
    obj.insert("age", 36);

    QJsonDocument doc(obj);
    QByteArray json = doc.toJson(QJsonDocument::Compact);

    qDebug() << json;

    //解析

    QJsonDocument doc2 = QJsonDocument::fromJson(json);
    QJsonObject obj2 = doc2.object();
    if(obj2.value("username").toString() == "xgl")
    {
        qDebug() << obj2.value("username").toString();
    }
#endif

    QJsonArray jsonArray;
    QJsonObject obj;
    obj.insert("username", QString("xgl"));
    obj.insert("password", QString("xgl123"));
    obj.insert("male", true);
    obj.insert("age", 36);
    jsonArray.insert(0, obj);

    // 转换成QByteArray
    QByteArray byteArray = QJsonDocument(jsonArray).toJson(QJsonDocument::Compact);
  //  qDebug() << byte_array; //"[{\"age\":36,\"male\":true,\"password\":\"xgl123\",\"username\":\"xgl\"}]"

    //解析
    QJsonArray jsonArray2 = QJsonDocument::fromJson(byteArray).array();

    for(int i = 0; i < jsonArray2.size(); i++) {
           QJsonObject json = jsonArray2.at(i).toObject();
           qDebug() << json.value("age").toInt();
           qDebug() << json.value("male").toBool();
           qDebug() << json.value("password").toString();
           qDebug() << json.value("username").toString();
       }


}

MainWindow::~MainWindow()
{
    delete ui;
}
