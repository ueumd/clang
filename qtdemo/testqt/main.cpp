#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <MyWidget.h>
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget w;

    w.setWindowTitle("hello world");

    QPushButton button ;
    button.setText("button");
    button.setParent(&w);

    //QT对c++的扩展 前面两个叫信号 后面两个叫槽
    QObject::connect(&button, SIGNAL(clicked()), &w , SLOT(close()));

    QLineEdit edit;
    edit.setParent(&w);
    edit.setEchoMode(QLineEdit::Password);
    edit.text();
    edit.setPlaceholderText("please input password");
    //edit.setGeometry(100,100,220,30);//前面两个是坐标 后面是宽高

    QHBoxLayout layout;
    layout.addWidget(&button);
    layout.addWidget(&edit);



    w.show();
    w.setLayout(&layout);

    //MyWidget w2;
   // w2.show();

    return app.exec();
}
