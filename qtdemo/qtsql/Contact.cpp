#include "Contact.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSqlRecord>
#include <QCompleter>
#include <QDebug>
Contact::Contact(QWidget *parent) :
    QWidget(parent)
{
    _model = new QSqlTableModel;
    _view = new QTableView;
    _view->setModel(_model);

    _model->setTable("tcontact");
    _model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    connect(_model, SIGNAL(dataChanged(QModelIndex,QModelIndex)),
            this, SLOT(slotModelDataChanged(QModelIndex,QModelIndex)));

    _model->select();

    // set Layout
    QVBoxLayout* vBox = new QVBoxLayout(this);
    vBox->addWidget(_view);

    QHBoxLayout* hBox = new QHBoxLayout;
    vBox->addLayout(hBox);

    hBox->addWidget(_filter = new QLineEdit, 1);
    hBox->addWidget(_add=new QPushButton("Add"));
    hBox->addWidget(_del=new QPushButton("Del"));
    hBox->addWidget(_reset=new QPushButton("Reset"));
    hBox->addWidget(_submit=new QPushButton("Submit"));

    connect(_add, &QPushButton::clicked, [&](){
        QSqlRecord record = _model->record();
        _model->insertRecord(-1, record);
    });
    connect(_del, &QPushButton::clicked, [&](){});
    connect(_reset, &QPushButton::clicked, [&](){});
    connect(_submit, &QPushButton::clicked, [&](){
        _model->submitAll();
    });

    connect(_filter, SIGNAL(textChanged(QString)),
            this, SLOT(slotFilterChanged(QString)));

    slotModelDataChanged(QModelIndex(), QModelIndex());
}

void Contact::slotFilterChanged(QString filter)
{
    if(filter.isEmpty())
    {
        _model->setFilter("");
        _model->select();
        return;
    }
 //  username like filter or password like  filter .......
    QSqlRecord record = _model->record();
    QString modelFilter;
    for(int i=0; i<record.count(); ++i)
    {
        if(i!=0)
        {
            modelFilter += " or ";
        }
        QString field = record.fieldName(i);
        QString subFilter = QString().sprintf("%s like '%%%s%%'", field.toUtf8().data(), filter.toUtf8().data());
      //  qDebug() << subFilter;

        modelFilter += subFilter;

    }
    qDebug() << modelFilter;
    _model->setFilter(modelFilter);
    _model->select();
}

void Contact::slotModelDataChanged(QModelIndex,QModelIndex)
{
    QStringList strList;
    for(int i=0; i<_model->rowCount(); ++i)
    {
        QSqlRecord record = _model->record(i);
        for(int j=0; j<record.count(); ++j)
        {
            QVariant var = record.value(j);
            if(var.isNull()) continue;
            strList << var.toString();
        }
    }
    qDebug() << strList;
    QCompleter* completer=new QCompleter(strList);
    _filter->setCompleter(completer);

}
