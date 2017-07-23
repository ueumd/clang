#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QApplication>
#include <QDebug>
#include <QBuffer>
#include <QLabel>
#include <QTextStream>
#include <QDataStream>
#include <QString>
#include <QPoint>
/*
QFile
QBuffer

QTcpSocket
QUdpSocket

QDataStream // io method 方便读和写
QTextStream //方便写

*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#if 0

    QFile file("./Mytext.txt");
    file.open(QIODevice::ReadWrite);

    file.write(QByteArray("abc"));

    file.close();
#endif
#if 0
    QByteArray ba("day");
    QString str("sunhello");
    qDebug() << ba.size() <<str.size();
#endif
#if 0
    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);
    buffer.write("Abc");
    buffer.write("123aaa");

    buffer.close();

    qDebug() << buffer.buffer();
 #endif
#if 0
    // send side 内存文件
    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);
    QPixmap pixmap("../kt.jpg");
    pixmap.save(&buffer, "JPG");
    buffer.close();
    qDebug() << buffer.buffer().size();

    // recv side
    QPixmap pixmap2;
    pixmap2.loadFromData(buffer.buffer(), "JPG");

    QLabel* label = new QLabel(this);
    label->setPixmap(pixmap2);
#endif
#if 0
    QFile file("../teststream.txt");
    file.open(QIODevice::ReadWrite);

    QTextStream textStream(&file);
    textStream << 1 << 1.2 << "abc"; //写入 不会有乱码 写日志方便
    file.close();
#endif
#if 0
    QFile file("../datastream.txt");
    file.open(QIODevice::ReadWrite);

    QDataStream dataStream(&file);
    // 会有乱码
    dataStream << 1 << "abc" << 1.2 << QString("abc") << QPoint(1,1);
    file.close();
#endif

    //读取
    QFile file("../datastream.txt");
    file.open(QIODevice::ReadWrite);

    QDataStream dataStream(&file);

    int i;
    char* buf;
    double d;
    QString str;
    QPoint pt;

    //写读都用 QDataStream 就不会存在大端小端问题
    dataStream >> i >> buf >> d >>str >> pt;

    delete[] buf;

    qDebug() << i << buf << d << str << pt;

    file.close();


}

MainWindow::~MainWindow()
{
    delete ui;
}
