#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("51134642");
    db.setDatabaseName("myjava");

    bool bRet = db.open();

    if(bRet == false)
    {
        qDebug() << "error open database" << db.lastError();
        exit(0);
    }

    qDebug() << "open database success";

    QSqlTableModel model;
    model.setTable("account");
    // 条件
    model.setFilter("id = 4");
    model.select();
    int ret = model.rowCount();

    for(int i = 0; i<ret; i++)
    {
        // 每一行
        QSqlRecord record = model.record(i);

        // 每一行中的列
        qDebug() << record.value("money").toInt();
        qDebug() << record.value("accountName").toString();

        // 每一行中的列
        for(int j=0; j<record.count(); j++)
        {
            // qDebug() << record.value(j);
        }
    }

    //update
  //  model.setData(model.index(0, 1), "hello");
  //  model.submitAll();

    // 新的一条记录
    QSqlRecord record = model.record();
    record.setValue("money", 3000);
    record.setValue("accountName", "xw");

  //  model.insertRecord(-1,record);
 //   model.submitAll();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
