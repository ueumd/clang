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
#include <QPainter>

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
    if(ev->button() == Qt::RightButton)
    {
         qDebug() << "left RightButton";
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

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "hello";
}

//画图
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    p.translate(50, 50);//整体坐标向下移

    //消除锯齿
    p.setRenderHint(QPainter::Antialiasing);

    //color
    p.setPen(QPen(Qt::red, 2, Qt::DashLine));

    //封闭图形的内部 相当于填充
    p.setBrush(Qt::yellow);

    p.drawLine(QPoint(0, 0),QPoint(100,100));

    p.drawEllipse(QPoint(95, 300), 50, 50);
    p.drawText(QPoint(300, 50), "Hello");

    p.drawRect(QRect(40, 60, 100, 50));
}
