#include "MyDialog.h"
#include <QApplication>
#include "QPushButton"
#include "QDebug"
#include "QFileDialog"
#include "QFontDialog"
#include "QMessageBox"

MyDialog::MyDialog(QDialog *parent) : QDialog(parent)
{
    QPushButton* button = new QPushButton("click me", this);

    connect(button,SIGNAL(clicked()),this, SLOT(slotButtonClick()));
}

void MyDialog::slotButtonClick()
{
   #if 0
    QDialog* dlg = new QDialog;
    //模态对话框中exec有自己的有消息循环，并且把app的消息循环接管了，所以别的对话框就没有消息了

 //   QPushButton* button = new QPushButton(dlg);
   // connect(button, SIGNAL(clicked()), dlg, SLOT(accept()));

    /*
        如果Dialog是通过exec来显示，那么可以通过accet或者reject来关闭窗口
        如果Dialog是通过show来显示，那么可以通过close来关闭窗口,这个和QWidget一样的
    */

    /*
    有许多特殊的dialog:文件选择 MessageBox，颜色选择，字体选择 打印预览 打印
    */

    int ret = dlg->exec();

    if(ret == QDialog::Accepted)
    {
        qDebug()<<"accepted";
    }
    if(ret == QDialog::Rejected)
    {
        qDebug()<<"rejected";
    }
#endif

#if 0
    QString strFileName = QFileDialog::getSaveFileName(NULL,"slect file for save",_strDir, "pic file(*.png, *.jpg)");
   // QString strFileName = QFileDialog::getOpenFileName(NULL,"slect file for save",_strDir, "pic file(*.png, *.jpg)");

    if(strFileName.isEmpty())
    {
        qDebug() << "select none";
        return;
    }

    qDebug() << strFileName;

    QFileInfo fileInfo(strFileName);
    _strDir =  fileInfo.filePath(); //记住上次选择目录
#endif
#if 0
    QFontDialog fontDialog;
    fontDialog.exec();
    QFont font = fontDialog.selectedFont();

    qDebug() << font;
#endif

    QMessageBox::warning(this,"Error", "Error mesages...");
    QMessageBox::information(this,"Error", "Error mesages...");
    QMessageBox::critical(this,"Error", "Error mesages..."); //致命问题
    int ret = QMessageBox::question(this,"????", "realy do...", QMessageBox::Yes, QMessageBox::YesAll, QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
        qDebug() << "yes";
    }
    if(ret == QMessageBox::No)
    {
        qDebug() << "No";
    }

}

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);
    //QDialog 没有最小化和最大化
    MyDialog dlg;
    dlg.show();

    return app.exec();
}
