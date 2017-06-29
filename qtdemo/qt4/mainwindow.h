#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool event(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

    void keyPressEvent(QKeyEvent *);

    QPushButton *button;
    QLineEdit* edit;


public slots:
    void slotButtonClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
