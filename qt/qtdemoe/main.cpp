#include "mainwindow.h"
#include <QApplication>
#include <QFile>
//设置皮肤样式
 static void SetStyle(const QString &styleName)
 {
     QFile file(QString(":/static/css/%1.css").arg(styleName));
     file.open(QFile::ReadOnly);
     QString qss = QLatin1String(file.readAll());
     qApp->setStyleSheet(qss);
     qApp->setPalette(QPalette(QColor("#F0F0F0")));
 }

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SetStyle("blue");
    MainWindow w;
    w.show();

    return a.exec();
}
