#include "Widget05.h"
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QSqlDatabase>
Widget05::Widget05(QWidget *parent) :
    QWidget(parent)
{
    _model = new QSqlQueryModel;
    _view = new QTableView(this);
    _view->setModel(_model);

    _model->setQuery("select * from tuser");
    _model->query();

   // _model->setEditStrategy(QSqlTableModel::OnManualSubmit);

     _model->setHeaderData(0, Qt::Horizontal, "编号");
     _model->setHeaderData(1, Qt::Horizontal, "用户名");
     _model->setHeaderData(2, Qt::Horizontal, "密码");
     _model->setHeaderData(3, Qt::Horizontal, "性别");

    QVBoxLayout* lay = new QVBoxLayout(this);
    lay->addWidget(_view);
}
