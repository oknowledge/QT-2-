#include "smart.h"
#include "ui_smart.h"
#include <QMovie>
#include <QPropertyAnimation>
#include <QIcon>

smart::smart(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::smart)
{

    ui->setupUi(this);
    //显示滚轮字幕
    ui->scroll3->setText("本界面由物联网2202班吴金英小组共同开发，小组成员：柳运琪，陈瑞泽，孙炎，QQ，李嘉颖。版权所有，翻录必究",qRgb(71,71,71));
    //显示左上角图标
    this->setWindowIcon(QIcon(":/image/smart.png"));
    //左下角开关相互转换
    connect(ui->pb1, &QPushButton::clicked, this, &smart::on_pb1_clicked);

    // 显示风扇界面的一些情况
    fanmove();
    connect(ui->pushButton_2, &QPushButton::clicked, this, &smart::kongmove);



    ui->label_8->setStyleSheet("border-image: url(:/image/OIP-C.jpg);");
    ui->label_9->setStyleSheet("border-image: url(:/image/780.jpg);");
    ui->label_10->setStyleSheet("border-image: url(:/image/OIP-C.jpg);");
    ui->label_11->setStyleSheet("border-image: url(:/image/780.jpg);");
    ui->label_16->setStyleSheet("border-image: url(:/image/PM2.5.png);");
    ui->label_18->setStyleSheet("border-image: url(:/image/LeYqwaor4E.jpg);");
    ui->label_20->setStyleSheet("border-image: url(:/image/fQSxRnrMhJ_small.jpg);");

    //几个界面跳转
    connect(ui->pb_page1, SIGNAL(clicked()), this, SLOT(onBtnPage1()));
    connect(ui->pb_page2, SIGNAL(clicked()), this, SLOT(onBtnPage2()));
    connect(ui->pb_page3, SIGNAL(clicked()), this, SLOT(onBtnPage3()));
    connect(ui->pb_page4, SIGNAL(clicked()), this, SLOT(onBtnPage4()));
    connect(ui->pb_page5, SIGNAL(clicked()), this, SLOT(onBtnPage5()));
    connect(ui->pb_page6, SIGNAL(clicked()), this, SLOT(onBtnPage6()));
    connect(ui->pb_page7, SIGNAL(clicked()), this, SLOT(onBtnPage7()));
    connect(ui->pb_page8, SIGNAL(clicked()), this, SLOT(onBtnPage8()));
    connect(ui->pb_page9, SIGNAL(clicked()), this, SLOT(onBtnPage9()));
    //汽车界面灯光亮暗
    ui->label_6->setStyleSheet("border-image: url(:/image/car.png);");
    connect(ui->lan1, SIGNAL(clicked()), this, SLOT(on_lan1_clicked()));
    connect(ui->lan2, SIGNAL(clicked()), this, SLOT(on_lan2_clicked()));


    connect(ui->open_fan, &QPushButton::clicked, [this]() {this->on_fan_clicked(1);});
    connect(ui->close_fan, &QPushButton::clicked, [this]() {this->on_fan_clicked(2);});
    connect(ui->first, &QPushButton::clicked, [this]() {this->on_fan_clicked(3);});
    connect(ui->second, &QPushButton::clicked, [this]() {this->on_fan_clicked(4);});
    connect(ui->third, &QPushButton::clicked, [this]() {this->on_fan_clicked(5);});
    ui->lineEdit_3->setText("25℃");
    ui->lineEdit_4->setText("35%");
}

smart::~smart()
{
    delete ui;
    delete fanMovie;
    delete kong;
}

void smart::on_pushButton_clicked()
{

}
void smart::kongmove()
{

    kong = new QMovie(":/image/q.gif");
    ui->label_26->setMovie(kong);
    kong->start();
    kong->setSpeed(30);
    ui->label_26->setScaledContents(true);
    ui->stackedWidget->setCurrentIndex(1);
    ui->label_35->setStyleSheet("border-image: url(:/image/sun.png);");
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(on_lan3_clicked()));
    ui->lcdNumber->display(i);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &smart::on_pushButton_3_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &smart::on_pushButton_4_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &smart::on_pushButton_3_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &smart::on_pushButton_4_clicked);

}

//空调睡眠模式
void smart::on_lan3_clicked()
{
    static bool flag3 = false;
    if (flag3 == false) {
        flag3 = true;
        // 先隐藏当前label，这样就看不到之前的图片了
        ui->label_35->hide();
        ui->label_35->setStyleSheet("border-image: url(:/image/night.jpg);");
        // 再显示设置好新样式的label，显示新图片
        ui->label_35->show();
    }
    else {
        flag3 = false;
        ui->label_35->hide();
        ui->label_35->setStyleSheet("border-image: url(:/image/sun.png);");
        ui->label_35->show();
    }
}

void smart::on_pushButton_8_clicked()
{
    i++;
    ui->lcdNumber->display(i);
}

void smart::on_pushButton_7_clicked()
{
    i--;
    ui->lcdNumber->display(i);
}
void smart::on_pushButton_3_clicked()
{
    modeIndex = (modeIndex + 1) % 3; // 循环切换模式，0 1 2 循环
    QString modeText;
    switch (modeIndex) {
    case 0:
        modeText = "制热";
        break;
    case 1:
        modeText = "制冷";
        break;
    case 2:
        modeText = "去湿";
        break;
    default:
        break;
    }
    ui->label_30->setText("模式：" + modeText);
}
void smart::on_pushButton_4_clicked()
{
    modeIndex1 = (modeIndex1 + 1) % 4; // 循环切换模式，0 1 2 循环
    QString modeText;
    switch (modeIndex1) {
    case 0:
        modeText = "小风";
        break;
    case 1:
        modeText = "中风";
        break;
    case 2:
        modeText = "大风";
        break;
    case 3:
        modeText = "自动";
        break;
    default:
        break;
    }
    ui->label_32->setText("风速：" + modeText);
}

void smart::on_pushButton_5_clicked()
{
    modeIndex2 = (modeIndex2 + 1) % 4; // 循环切换模式，0 1 2 循环
    QString modeText;
    switch (modeIndex2) {
    case 0:
        modeText = "正常";
        break;
    case 1:
        modeText = "左右";
        break;
    case 2:
        modeText = "上下";
        break;
    case 3:
        modeText = "自动";
        break;
    default:
        break;
    }
    ui->label_33->setText("风向：" + modeText);
}
void smart::on_pushButton_6_clicked()
{
    modeIndex3 = (modeIndex3 + 1) % 2; // 循环切换模式，0 1 2 循环
    QString modeText;
    switch (modeIndex3) {
    case 0:
        modeText = "自动风向";
        break;
    case 1:
        modeText = "手动风向";
        break;
    default:
        break;
    }
    ui->label_34->setText(modeText);
}




















































void smart::fanmove()
{
    fanMovie = new QMovie(":/image/fan.gif");
    ui->l_fan->setMovie(fanMovie);
    fanMovie->start();
    fanMovie->setSpeed(0);
    ui->l_fan->setScaledContents(true);//适应大小
    ui->stackedWidget->setCurrentIndex(0);
}

void smart::on_fan_clicked(int param)
{
    // 处理按下按钮后的逻辑，使用传递的参数
    if (param == 1) {if (fanMovie) {fanMovie->setSpeed(30); }}
    if (param == 2) {if (fanMovie) {fanMovie->setSpeed(0); }}
    if (param == 3) {if (fanMovie) {fanMovie->setSpeed(30); }}
    if (param == 4) {if (fanMovie) {fanMovie->setSpeed(200); }}
    if (param == 5) {if (fanMovie) {fanMovie->setSpeed(500); }}
}
//汽车亮起灯光
void smart::on_lan1_clicked()
{
    static bool flag1 = false;
    if (flag1 == false) {
        flag1 = true;
        // 先隐藏当前label，这样就看不到之前的图片了
        ui->label_7->hide();
        ui->label_7->setStyleSheet("border-image: url(:/image/lan1.png);");
        // 再显示设置好新样式的label，显示新图片
        ui->label_7->show();
    }
    else {
        flag1 = false;
        ui->label_7->hide();
        ui->label_7->setStyleSheet("border-image: url(:/image/lan1.png);");
        ui->label_7->show();
    }
}
//汽车关闭灯光
void smart::on_lan2_clicked()
{
    static bool flag2 = false;
    if (flag2 == false) {
        flag2 = true;
        // 先隐藏当前label，这样就看不到之前的图片了
        ui->label_7->hide();
        ui->label_7->setStyleSheet("border-image: url(:/image/lan2.png);");
        // 再显示设置好新样式的label，显示新图片
        ui->label_7->show();
    }
    else {
        flag2 = false;
        ui->label_7->hide();
        ui->label_7->setStyleSheet("border-image: url(:/image/lan2.png);");
        ui->label_7->show();
    }
}

//开关互转按键
void smart::on_pb1_clicked()
{

    if (flag8 == false) {
        flag8 = true;
        ui->pb1->hide();
        ui->pb1->setStyleSheet("border-image: url(:/image/case1.png);");
        ui->pb1->show();
    }
    else if(flag8==true){
        flag8= false;
        ui->pb1->hide();
        ui->pb1->setStyleSheet("border-image: url(:/image/2.png);");
        ui->pb1->show();
    }
}

//九个跳转界面
void smart::onBtnPage1()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void smart::onBtnPage2()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void smart::onBtnPage3()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void smart::onBtnPage4()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void smart::onBtnPage5()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void smart::onBtnPage6()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void smart::onBtnPage7()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void smart::onBtnPage8()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void smart::onBtnPage9()
{
    ui->stackedWidget->setCurrentIndex(8);
}
