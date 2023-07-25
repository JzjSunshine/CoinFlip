#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    // 重写绘画事件函数
    void paintEvent(QPaintEvent *);

    //

    // 延时方法
    void sleep(int ms);

signals:
    // 选择返回的信号函数
    void chooseBackSence();

public slots:
};

#endif // CHOOSELEVELSCENE_H
