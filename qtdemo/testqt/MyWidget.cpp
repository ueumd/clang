#include "MyWidget.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QTextEdit> // multi lines , rich text
#include <QGroupBox> //分类
#include <QSlider>//模拟方式显示数值
#include <QSpinBox> //数字
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QTabWidget>

#include <QVBoxLayout>



MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * lay=new QVBoxLayout(this);
    QLabel* label;

    QComboBox* combo;

    lay->addWidget(label=new QLabel("label"));
    lay->addWidget(new QPushButton("button"));
    lay->addWidget(new QRadioButton("Radio"));
    lay->addWidget(new QCheckBox("check box"));
    lay->addWidget(combo =new QComboBox());
    combo->addItem("select item1");
    combo->addItem("select item2");

     lay->addWidget(new QTextEdit);
     lay->addWidget(new QGroupBox);
     lay->addWidget(new QSlider);
     lay->addWidget(new QSpinBox);
     lay->addWidget(new QDateTimeEdit);
     lay->addWidget(new QTextEdit);
     lay->addWidget(new QTextEdit);

}

