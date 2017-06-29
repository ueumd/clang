#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPoint>
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
     QVBoxLayout * lay = new QVBoxLayout(this);
#if 0

    QPushButton* button2;

    lay->addWidget( button = new QPushButton("ok", this));
    lay->addWidget( button2 = new QPushButton("button2", this));

    button->setDefault(true);//键盘事件阻止冒泡

    //信号 槽
    connect(button, SIGNAL(clicked()), this,SLOT(slotButtonClicked()));
    connect(button2, SIGNAL(clicked()), this,SLOT(slotButtonClicked()));

    this->setMouseTracking(true);//鼠标移动时响应 不需要按下 mousemove
#endif

  QPushButton* button2;
    lay->addWidget(edit = new QLineEdit());
     lay->addWidget( button2 = new QPushButton("button2", this));
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
 * 可以重载具体的虚函数，来实现对消息的响应
 * 可以重载event函数，用来处理或者截取消息
*/


void MainWindow::slotButtonClicked()
{
    QPushButton * button = (QPushButton*) sender();//获取槽函数被谁激发

    qDebug() << button->text();
}
/*截取消息*/
bool MainWindow::event(QEvent *ev)
{
    if(ev->type() == QEvent::MouseButtonDblClick)
        return true;
    return QWidget::event(ev);
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    QPoint pt = ev->pos();
    qDebug() << pt;
    if(ev->button() == Qt::LeftButton)
    {
         qDebug() << "left button";
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    QPoint pt = ev->pos();
    qDebug() << "mouse move:" << pt;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    ev->modifiers();
    int key = ev->key();
    qDebug() << key;
    char a = key;
    qDebug() << (char)a;
}
