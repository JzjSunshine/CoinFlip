#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mypushbutton.h"
#include "chooselevelscene.h"
#include <QPixmap>
#include <QPushButton>
#include <QAction>
#include <QPainter>
#include <QTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗口标题
    this->setWindowTitle("CoinFilp");
    //设置大小
    this->setFixedSize(420, 680);
    // 设置开始图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    //退出
    connect(ui->actionQuit,&QAction::triggered,this,[=](){
        this->close();
    });

    //创建开始按钮
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5, this->height()*0.7);

    ChooseLevelScene *choice = new ChooseLevelScene();

    connect(choice, &ChooseLevelScene::chooseBackSence,this,[=]()->void{

    });
    // 开始按钮跳跃特效实现
    connect(startBtn, &QPushButton::clicked, this,[=](){
        //添加音效
        //按下按钮
        qDebug() << "点击开始";
        startBtn->downBounce();// 向下跳跃
        startBtn->upBounce(); // 向上跳跃
        
        // 设置窗口固定
        choice->setGeometry(this->geometry());
//        qDebug() << QTime::currentTime();
        // 延时0.5秒，进入选择关卡场景
        sleep(500);
        this->hide();
        choice->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
//绘制图片背景
void MainWindow::paintEvent(QPaintEvent *)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建 QPixmap
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    //绘制背景
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.8,pix.height()*0.8);
    painter.drawPixmap(10,30,pix);


}

void MainWindow::sleep(int ms)
{
    QTime reachTime = QTime::currentTime().addSecs(ms);
    while(QTime::currentTime() <reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents,50);
    }

}
