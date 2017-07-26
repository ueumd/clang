#ifndef WIDGET05_H
#define WIDGET05_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QTableView>
class Widget05 : public QWidget
{
    Q_OBJECT
public:
    explicit Widget05(QWidget *parent = 0);

    QSqlQueryModel* _model;
    QTableView *_view;

signals:

public slots:

};

#endif // WIDGET05_H
