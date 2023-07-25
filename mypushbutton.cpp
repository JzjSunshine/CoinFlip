#include "mypushbutton.h"

#include <QPushButton>
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QString normalImgPath, QString pressImgPath)
{
    //实现重载版本的 MyPushButton
    // 成员变量 normalImgPath 保存正常显示图片路径
    this->normalImgPath = normalImgPath;
    this->pressImgPath = pressImgPath;//按下按钮

    QPixmap pixmap;
    //判断是否能够加载正常显示的图片，若不能加载失败
    bool ret = pixmap.load(normalImgPath);
    if(!ret){
        qDebug() << normalImgPath << "加载失败";
        return;
    }
    //设置图片尺寸
    this->resize(pixmap.width(),pixmap.height());
    //设置不规则图片的样式表
    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pixmap);
    this->setIconSize(pixmap.size());

        
}

void MyPushButton::downBounce()
{
    qDebug() << "按下去";
    //1.创建动态对象
    QPropertyAnimation *ani = new QPropertyAnimation(this,"geometry");

    //2. 设置动画时间间隔
    ani->setDuration(200);

    //3. 起始位置
    ani->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //4. 结束位置
    ani->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    //5. 设置弹跳曲线
    ani->setEasingCurve(QEasingCurve::OutBounce);
    //6. 执行动画
    ani->start();

}

void MyPushButton::upBounce()
{
    qDebug() << "弹起来";
    // 1. 创建动态对象
    QPropertyAnimation *ani = new QPropertyAnimation(this,"geometry");

    // 2. 设置动画时间间隔
    ani->setDuration(200);

    // 3. 起始位置
    ani->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));

    // 4. 结束位置
    ani->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    // 5. 设置弹跳曲线
    ani->setEasingCurve(QEasingCurve::OutBounce);

    // 6. 执行动画
    ani->start();

}

//void MyPushButton::mousePressEvent(QMouseEvent *e)
//{

//}

//void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
//{

//}
