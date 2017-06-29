#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QWidget>


class MyWidget : public QWidget
{
public:
    MyWidget();

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

    QVector<QVector<QPoint>> _lines;
};

#endif // MYWIDGET_H
