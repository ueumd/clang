#include "mainwindow.h"
#include "Widget05.h"
#include "Contact.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* QSQLITE QODBC QPLSQL */
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("51134642");
    db.setDatabaseName("d0718");
    bool bRet = db.open();
    if(bRet == false)
    {
        qDebug() << "error open database" << db.lastError().text();
        exit(0);
    }
    qDebug() << "open database success";

 //   Widget05 w;
 //   w.show();

   MainWindow w;
   w.show();

    return a.exec();
}
