#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = 0);

    QSqlTableModel* _model;
    QTableView* _view;

    QLineEdit* _filter;
    QPushButton* _add;
    QPushButton* _del;
    QPushButton* _reset;
    QPushButton* _submit;
signals:

public slots:

    void slotModelDataChanged(QModelIndex,QModelIndex);
    void slotFilterChanged(QString filter);

};

#endif // CONTACT_H
