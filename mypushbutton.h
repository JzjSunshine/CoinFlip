#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QString>


// 自定义按钮类，主要用于实现 start back 按钮
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //    explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString normalImgPath, QString pressImgPath="");

    // 正常显示的图片路径
    QString normalImgPath;
    // 按压时显示的图片路径
    QString pressImgPath;


    //下坠
    void downBounce();
    // 上弹
    void upBounce();

//    //鼠标按下事件
//    void mousePressEvent(QMouseEvent *e);
//    //鼠标释放事件
//    void mouseReleaseEvent(QMouseEvent *e);


signals:

public slots:
};

#endif // MYPUSHBUTTON_H
