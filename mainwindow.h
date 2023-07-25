#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //重写绘画函数
    void paintEvent(QPaintEvent *);
    //延时方法
    void sleep(int ms);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
