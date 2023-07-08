#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "money.h"
#include <QMainWindow>
#include <QTimer>
#include <QMovie>
#include<QMediaplayer>
#include<QAudioOutput>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void animateHook();
    void paint_hook(QPainter painter);
    void updateHook();

    bool collision_detection(QRectF rect);
    bool judge();

    void initialization();
    void mediaplay();
    void animatepig();
    void animateboom();

private slots:

    void time_update1();
    void time_update2();
    void time_update3();
    void time_update4();
    void time_update5();
    void time_update6();
    void time_update7();

    void on_beginButton_clicked();
    void on_quitButton_clicked();
    void on_nextButton_clicked();

    void updateTimer();
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);


    void on_replayButton_clicked();
    void on_closeButton_clicked();

    void on_fireButton_clicked();
    void on_strongButton_clicked();
    void on_luckButton_clicked();
    void on_stoneButton_clicked();
    void on_diamondButton_clicked();

    bool eventFilter(QObject *watched, QEvent *event);

private:
    void paint_countdown(MainWindow* m);

    QTimer *timer;
    QTimer* timer1;
    int remainingTime;

    QSet<int> pressedKeys; // 存储当前按下的键盘方向键
    Ui::MainWindow *ui;

    const double radius = 60.0; // 圆的半径
    const double angularSpeed = 0.015; // 角速度，控制圆周运动的速度
    bool isSwinging = true; // 钩子的摆动状态
    bool swingDirection = true; // 摆动方向，true 为向下，false 为向上
    double hook_speed_down=2;
    double hook_speed_up=4.5;
    double hook_speed;
    bool beginflag=0;
    int level=0;
    Money mo;

    int boom_x=80, boom_y=80;
    int expand=8;

    QPointF hookStart ; // 钩子起点的初始位置
    QPointF hookEnd ; // 钩子终点的初始位置
    QRectF hookRect;

    int f1=rand()%2,f2=rand()%2,f3=rand()%2,f4=rand()%2,f5=rand()%2;//是否出现
    int ed=0,ed1=0,ed2=0,ed3=0,ed4=0,ed5=0;//是否买过（12345分别对应摆放顺序，ed1表示买过几个，用过要--）
    int pr1=rand()%500+1, pr2=rand()%500+1, pr3=rand()%500+1, pr4=rand()%500+1, pr5=rand()%500+1; //价格

    bool flag=0;
    bool flag1=0; //为1时则持续收回
    bool flag2=0; //是否碰撞
    bool flag3=0; //是否已经发生过碰撞

    QRectF* goldRect;
    int size_tem;
    int value_tem;
    int* boom_tem;
    int* ex_x_tem;
    int* ex_y_tem;

    bool flag4=1;//放下时是否更改过人物及播放音乐
    bool flag5=1;//收回时是否更改过人物及播放音乐
    int w=0;
    int r=0; //音乐重复

    QMediaPlayer *player3= new QMediaPlayer;
    QMediaPlayer *player4= new QMediaPlayer;
    QMediaPlayer *player5= new QMediaPlayer;
    QMediaPlayer *player6= new QMediaPlayer;
    QMediaPlayer *player7= new QMediaPlayer;
    QMediaPlayer *player8= new QMediaPlayer;
    QMediaPlayer *player9= new QMediaPlayer;
    QAudioOutput *audio3= new QAudioOutput;
    QAudioOutput *audio4= new QAudioOutput;
    QAudioOutput *audio5= new QAudioOutput;
    QAudioOutput *audio6= new QAudioOutput;
    QAudioOutput *audio7= new QAudioOutput;
    QAudioOutput *audio8= new QAudioOutput;
    QAudioOutput *audio9= new QAudioOutput;

};
#endif // MAINWINDOW_H
