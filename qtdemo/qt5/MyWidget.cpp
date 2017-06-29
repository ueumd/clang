#include "MyWidget.h"
#include <QApplication>
#include <QPainter>
#include <QVector>
#include <QMouseEvent>

MyWidget::MyWidget()
{

}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    p.setPen(QPen(Qt::red, 2));

    for(int i=0; i<_lines.size(); i++)
    {
       const QVector<QPoint>& line = _lines.at(i);
       for(int j=0; j<line.size()-1; ++j)
       {
          p.drawLine(line.at(j), line.at(j+1));
       }

    }
}

void MyWidget::mouseMoveEvent(QMouseEvent *ev)
{
    QVector<QPoint>& lastLine=_lines.last();
    lastLine.append(ev->pos());

    update();//开始绘画
}

void MyWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    QVector<QPoint>& lastLine=_lines.last();
    lastLine.append(ev->pos());
}

void MyWidget::mousePressEvent(QMouseEvent *ev)
{
    QVector<QPoint> line;
    _lines.append(line);

    QVector<QPoint>& lastLine=_lines.last();
    lastLine.append(ev->pos());
}


int main(int argc, char ** argv)
{
    QApplication app(argc, argv);
    MyWidget w;
    w.show();
    return app.exec();
}
