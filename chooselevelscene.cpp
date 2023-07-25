#include "chooselevelscene.h"
#include <QPixmap>
#include <QPainter>
#include <QTime>
#include <QCoreApplication>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //1. 设置新窗口
    this->setFixedSize(420,680);
    this->setWindowTitle("Level");
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    //2. 创建菜单栏

    // 3. 创建菜单栏开始

    // 4. 创建菜单项退出

    // 5. 退出

    //选择关卡按钮音效

    // 6. Back按钮

    // 7. 20关卡按钮

    // 8. 点击关卡数字，响应
}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");

    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);


}

void ChooseLevelScene::sleep(int ms)
{
    QTime  reachTime = QTime::currentTime().addMSecs(ms);
    while(QTime::currentTime() < reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 50);
    }
}
