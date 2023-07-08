#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "goods.h"
#include "money.h"
#include "object.h"
#include "level.h"
#include <QTimer>
#include <QMovie>
#include<QMediaplayer>
#include<QAudioOutput>
#include<QPainter>
#include<QKeyEvent>

static double angle = 0.0;// 钩子当前的角度

Gold g1(1,0,0);
Gold g2(1,0,0);
Gold g3(2,0,0);
Gold g4(2,0,0);
Gold g5(3,0,0);
Gold g6(3,0,0);
Gold g7(4,0,0);
Gold g8(4,0,0);
Stone s1(1,0,0);
Stone s2(1,0,0);
Stone s3(2,0,0);
Stone s4(2,0,0);
Diomond d1(0,0);
Diomond d2(0,0);
Lucky_Bag l1(0,0);
Lucky_Bag l2(0,0);
Pig p1(0,0);
Pig p2(0,0);
D_Pig dp1(0,0);
D_Pig dp2(0,0);
TNT tnt1(0,0);
vector<_Object> v={g1,g2,g3,g4,g5,g6,g7,g8,s1,s2,s3,s4,l1,l2,d1,d2,p1,p2,dp1,dp2,tnt1};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    paintgold1(&v);

    //主界面动画
    ui->setupUi(this);
    QMovie *movie1 = new QMovie(":/picture/begingif.gif");
    ui->beginlable->setMovie(movie1);
    movie1->start();

    //主界面按钮
    ui->beginButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->beginButton->setStyleSheet("QPushButton{border-image:url(:/picture/transparent.png);}"
                                   "QPushButton:hover{border-image:url(:/picture/starttext.png);}"
                                   );
    this->ui->stackedWidget->setCurrentIndex(0);

    //游戏界面按钮
    ui->quitButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->quitButton->setStyleSheet("QPushButton{border-image:url(:/picture/transparent.png);}"
                                  "QPushButton:hover{border-image:url(:/picture/quit2.png);}"
                                  "QPushButton:pressed{border-image:url(:/picture/quit3.png);}"
                                  );
    //商店界面按钮
    ui->nextButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->nextButton->setStyleSheet("QPushButton{border-image:url(:/picture/nextbutton1.png);}"
                                  "QPushButton:hover{border-image:url(:/picture/nextbutton2.png);}"
                                  "QPushButton:pressed{border-image:url(:/picture/nextbutton3.png);}");
    //结束界面按钮
    QFont font;
    font.setPointSize(18); // 设置字体大小
    font.setBold(true); // 设置字体加粗
    ui->replayButton->setFont(font);
    ui->replayButton->setStyleSheet("color: #000000;");
    ui->replayButton->setText("重 玩");
    ui->replayButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->replayButton->setStyleSheet("QPushButton{border-image:url(:/picture/endbutton1.png);}"
                                    "QPushButton:hover{border-image:url(:/picture/endbutton2.png);}"
                                    );
    ui->closeButton->setFont(font);
    ui->closeButton->setStyleSheet("color: #000000;");
    ui->closeButton->setText("退 出");
    ui->closeButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->closeButton->setStyleSheet("QPushButton{border-image:url(:/picture/endbutton1.png);}"
                                   "QPushButton:hover{border-image:url(:/picture/endbutton2.png);}"
                                   );

    //倒计时
    remainingTime = 100000;
    ui->timelable->setStyleSheet("font-size: 48px;");
    QFont font1;
    font1.setPointSize(20); // 设置字体大小
    font1.setBold(true); // 设置字体加粗
    ui->timelable->setStyleSheet("background-color: transparent");
    ui->timelable->setFont(font1);
    ui->timelable->setStyleSheet("color: #FF4500;");
    //其他
    ui->levellable->setStyleSheet("background-color: transparent");
    ui->levellable->setFont(font1);
    ui->levellable->setStyleSheet("color: #FF4500;");

    ui->mymoneylable1->setStyleSheet("background-color: transparent");
    ui->mymoneylable1->setFont(font1);
    ui->mymoneylable1->setStyleSheet("color: #227700;");
    ui->mymoneylable1->setText("$");

    ui->mymoneylable2->setStyleSheet("background-color: transparent");
    ui->mymoneylable2->setFont(font1);
    ui->mymoneylable2->setStyleSheet("color: #227700;");

    ui->aimmoneylable1->setStyleSheet("background-color: transparent");
    ui->aimmoneylable1->setFont(font1);
    ui->aimmoneylable1->setStyleSheet("color: #FA8C00;");
    ui->aimmoneylable1->setText("$");

    ui->aimmoneylable2->setStyleSheet("background-color: transparent");
    ui->aimmoneylable2->setFont(font1);
    ui->aimmoneylable2->setStyleSheet("color: #FA8C00;");
    this->setFixedSize(950,701);
    //游戏初始界面
    QPalette palette;
    QPixmap pixmap(":/picture/gamewholeback1.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::judge(){
    f1=rand()%2,f2=rand()%2,f3=rand()%2,f4=rand()%2,f5=rand()%2;
    ed=0,ed2=0,ed3=0,ed4=0,ed5=0;//是否买过
    pr1=rand()%500+1, pr2=rand()%500+1, pr3=rand()%500+1, pr4=rand()%500+1, pr5=rand()%500+1;

    if(mo.money_num>=mo.money[level]){
        return true;
    }
    else{
        return false;
    }
}
void MainWindow::initialization() {
    isSwinging=true;
    flag1=0;
    flag2=0;
    flag3=0;
    flag4=1;//放下时是否更改过人物及播放音乐
    flag5=1;//收回时是否更改过人物及播放音乐
    w=0;

    player4->stop();

    ed=0,ed2=0,ed3=0,ed4=0,ed5=0;
}

void MainWindow::updateTimer()
{
    if (beginflag&&remainingTime > 0) {
        ui->timelable->setText(QString::number(remainingTime));
        remainingTime--;
    }
    else if(beginflag&&remainingTime <= 0){
        timer->stop();
        remainingTime = 60;

        initialization();

        ui->timelable->setText("60");
        if(judge()){
            //播放音乐
            QMediaPlayer *player2= new QMediaPlayer(this);
            QAudioOutput *audio2= new QAudioOutput(this);
            player2->setAudioOutput(audio2);
            QString filePath = "qrc:/music/pass+shop.mp3";
            player2->setSource(QUrl(filePath));
            player2->play();
            //主动退出关卡
            QMovie *movie3 = new QMovie(":/picture/passgif.gif");
            ui->passlable->setMovie(movie3);
            movie3->start();
            this->ui->stackedWidget->setCurrentIndex(3);
            QTimer::singleShot(1880, this, SLOT(time_update3()));
        }
        else{
            //失败
            QMovie *movie8 = new QMovie(":/picture/failgif.gif");
            ui->faillable1->setMovie(movie8);
            movie8->start();
            this->ui->stackedWidget->setCurrentIndex(6);
            QTimer::singleShot(3000, this, SLOT(time_update5()));
        }
    }
}

//切换到游戏界面
void MainWindow::time_update1(){
    ++level;

    ui->levellable->setText(QString::number(level));
    ui->mymoneylable2->setText(QString::number(mo.money_num));
    ui->aimmoneylable2->setText(QString::number(mo.money[level]));

    remainingTime = 60;
    ui->timelable->setText("60");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    timer->start(1000);//倒计时定时器

    timer1 = new QTimer(this);
    connect(timer1, &QTimer::timeout, this, &MainWindow::animateHook);
    timer1->start(10); // 每10毫秒触发一次定时器，控制钩子动画速度
    this->ui->stackedWidget->setCurrentIndex(2);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(ui->fireButton == watched) {
        if(QEvent::Enter == event->type()&&f1) {            //鼠标进入
            ui->goodstextlabel->setStyleSheet(tr("border-image: url(:/picture/firecracker3.png);"));
            return 1;
        }
    }
    if(ui->strongButton == watched) {
        if(QEvent::Enter == event->type()&&f2) {
            ui->goodstextlabel->setStyleSheet(tr("border-image:url(:/picture/stronger3.png);"));
            return 1;
        }
    }
    if(ui->luckButton == watched) {
        if(QEvent::Enter == event->type()&&f3) {
            ui->goodstextlabel->setStyleSheet(tr("border-image:url(:/picture/luckier3.png);"));
            return 1;
        }
    }
    if(ui->stoneButton == watched) {
        if(QEvent::Enter == event->type()&&f4) {
            ui->goodstextlabel->setStyleSheet(tr("border-image:url(:/picture/betterstone3.png);"));
            return 1;
        }
    }
    if(ui->diamondButton == watched) {
        if(QEvent::Enter == event->type()&&f5) {
            ui->goodstextlabel->setStyleSheet(tr("border-image:url(:/picture/betterdiamond3.png);"));
            return 1;
        }
    }
    return QWidget::eventFilter(watched, event);
}

void MainWindow::time_update2(){
    //商店人物眨眼动画
    QMovie *movie6 = new QMovie(":/picture/shopmangif.gif");
    ui->shopmanlable->setMovie(movie6);
    movie6->start();
    //固定商店文字
    ui->shoptextlable->setPixmap(QPixmap(":/picture/shoptext.png"));
}

void MainWindow::time_update3(){
    QMovie *movie4 = new QMovie(":/picture/shopmanspeakgif.gif");
    ui->shopmanlable->setMovie(movie4);
    QMovie *movie5 = new QMovie(":/picture/shoptextgif.gif");
    ui->shoptextlable->setMovie(movie5);
    movie4->start();//人物说话
    movie5->start();//打字动画

    ui->fireButton->installEventFilter(this);
    ui->strongButton->installEventFilter(this);
    ui->luckButton->installEventFilter(this);
    ui->stoneButton->installEventFilter(this);
    ui->diamondButton->installEventFilter(this);

    QFont font1;
    font1.setPointSize(20); // 设置字体大小
    font1.setBold(true); // 设置字体加粗

    if(!f1){
        Bomb bomb;
        bomb.disappear(ui);
    }
    else{
        Bomb bomb;
        bomb.appear(pr1, ui);
    }

    if(!f2){
        Generative_Water gen;
        gen.disappear(ui);
    }
    else{
        Generative_Water gen;
        gen.appear(pr2, ui);
    }

    if(!f3){
        Lucky_Clover lu;
        lu.disappear(ui);
    }
    else{
        Lucky_Clover lu;
        lu.appear(pr3, ui);
    }

    if(!f4){
        Stone_Book st;
        st.disappear(ui);
    }
    else{
        Stone_Book st;
        st.appear(pr4, ui);
    }

    if(!f5){
        Nice_Diomond di;
        di.disappear(ui);
    }
    else{
        Nice_Diomond di;
        di.appear(pr5, ui);
    }

    this->ui->stackedWidget->setCurrentIndex(4);
    QTimer::singleShot(1060, this, SLOT(time_update2()));
}

void MainWindow::on_fireButton_clicked()
{
    if(f1 && mo.money_num>=pr1){
        mo.money_num-=pr1;
        f1=0;ed=1;ed1++;

        ui->fireButton->setStyleSheet("QPushButton{border-image:url(:/picture/transparent.png);}"
                                      "QPushButton:hover{border-image:url(:/picture/transparent.png);}"
                                      );
        ui->firelabel1->setText(" ");
        ui->firelabel2->setText(" ");
        QMediaPlayer *player= new QMediaPlayer(this);
        QAudioOutput *audio= new QAudioOutput(this);
        player->setAudioOutput(audio);
        QString filePath = "qrc:/music/buy.mp3";
        player->setSource(QUrl(filePath));
        player->play();
    }
}

void MainWindow::on_strongButton_clicked()
{
    if(f2 && mo.money_num>=pr2){
        mo.money_num-=pr2;
        f2=0;ed=1;ed2=1;
        ui->strongButton->setStyleSheet("QPushButton{border-image:url(:/picture/transparent.png);}"
                                        "QPushButton:hover{border-image:url(:/picture/transparent.png);}"
                                        );
        ui->stronglabel1->setText(" ");
        ui->stronglabel2->setText(" ");
        QMediaPlayer *player= new QMediaPlayer(this);
        QAudioOutput *audio= new QAudioOutput(this);
        player->setAudioOutput(audio);
        QString filePath = "qrc:/music/buy.mp3";
        player->setSource(QUrl(filePath));
        player->play();
    }
}

void MainWindow::on_luckButton_clicked()
{
    if(f3 && mo.money_num>=pr3){
        mo.money_num-=pr3;
        f3=0;ed=1;ed3=1;
        ui->luckButton->setStyleSheet("QPushButton{border-image:url(:/picture/transparent.png);}"
                                      "QPushButton:hover{border-image:url(:/picture/transparent.png);}"
                                      );
        ui->lucklabel1->setText(" ");
        ui->lucklabel2->setText(" ");
        QMediaPlayer *player= new QMediaPlayer(this);
        QAudioOutput *audio= new QAudioOutput(this);
        player->setAudioOutput(audio);
        QString filePath = "qrc:/music/buy.mp3";
        player->setSource(QUrl(filePath));
        player->play();
    }
}

void MainWindow::on_stoneButton_clicked()
{
    if(f4 && mo.money_num>=pr4){
        mo.money_num-=pr4;
        f4=0;ed=1;ed4=1;
        ui->stoneButton->setStyleSheet("QPushButton{border-image:url(:/picture/transparent.png);}"
                                       "QPushButton:hover{border-image:url(:/picture/transparent.png);}"
                                       );
        ui->stonelabel1->setText(" ");
        ui->stonelabel2->setText(" ");
        QMediaPlayer *player= new QMediaPlayer(this);
        QAudioOutput *audio= new QAudioOutput(this);
        player->setAudioOutput(audio);
        QString filePath = "qrc:/music/buy.mp3";
        player->setSource(QUrl(filePath));
        player->play();
    }
}

void MainWindow::on_diamondButton_clicked()
{
    if(f5 && mo.money_num>=pr5){
        mo.money_num-=pr5;
        f5=0;ed=1;ed5=1;
        ui->diamondButton->setStyleSheet("QPushButton{border-image:url(:/picture/transparent.png);}"
                                         "QPushButton:hover{border-image:url(:/picture/transparent.png);}"
                                         );
        ui->diomondlabel1->setText(" ");
        ui->diomondlabel2->setText(" ");
        QMediaPlayer *player= new QMediaPlayer(this);
        QAudioOutput *audio= new QAudioOutput(this);
        player->setAudioOutput(audio);
        QString filePath = "qrc:/music/buy.mp3";
        player->setSource(QUrl(filePath));
        player->play();
    }
}

void MainWindow::time_update4(){
    QFont font2;
    font2.setPointSize(43); // 设置字体大小
    font2.setBold(true); // 设置字体加粗
    ui->moneylable1->setStyleSheet("background-color: transparent");
    ui->moneylable1->setFont(font2);
    ui->moneylable1->setStyleSheet("color: #00CA00;");
    ui->moneylable1->setText("$");
    ui->moneylable2->setStyleSheet("background-color: transparent");
    ui->moneylable2->setFont(font2);
    ui->moneylable2->setStyleSheet("color: #00CA00;");
    ui->moneylable2->setText(QString::number(mo.money[level+1]));

    this->ui->stackedWidget->setCurrentIndex(1);
    QTimer::singleShot(1400, this, SLOT(time_update1())); //返回关卡前
}

void MainWindow::time_update5(){this->ui->stackedWidget->setCurrentIndex(7);}

void MainWindow::on_beginButton_clicked() {
    beginflag=1;
    ed1=0;
    // 播放音乐
    QMediaPlayer *player1= new QMediaPlayer(this);
    QAudioOutput *audio1= new QAudioOutput(this);
    player1->setAudioOutput(audio1);
    QString filePath = "qrc:/music/break.mp3";
    player1->setSource(QUrl(filePath));
    player1->play();
    //主界面切换到关卡前界面
    QMovie *movie2 = new QMovie(":/picture/breakgif.gif");
    ui->breaklable->setMovie(movie2);
    movie2->start();

    QFont font2;
    font2.setPointSize(43); // 设置字体大小
    font2.setBold(true); // 设置字体加粗
    ui->moneylable1->setStyleSheet("background-color: transparent");
    ui->moneylable1->setFont(font2);
    ui->moneylable1->setStyleSheet("color: #00CA00;");
    ui->moneylable1->setText("$");
    ui->moneylable2->setStyleSheet("background-color: transparent");
    ui->moneylable2->setFont(font2);
    ui->moneylable2->setStyleSheet("color: #00CA00;");
    ui->moneylable2->setText(QString::number(mo.money[level+1]));


    this->ui->stackedWidget->setCurrentIndex(1);
    QTimer::singleShot(1400, this, SLOT(time_update1()));
}

void MainWindow::on_quitButton_clicked()
{
    timer->stop();
    remainingTime = 60;
    ui->timelable->setText("60");

    initialization();

    if(judge()){
        //播放音乐
        QMediaPlayer *player2= new QMediaPlayer(this);
        QAudioOutput *audio2= new QAudioOutput(this);
        player2->setAudioOutput(audio2);
        QString filePath = "qrc:/music/pass+shop.mp3";
        player2->setSource(QUrl(filePath));
        player2->play();
        //过关动画
        QMovie *movie3 = new QMovie(":/picture/passgif.gif");
        ui->passlable->setMovie(movie3);
        movie3->start();
        this->ui->stackedWidget->setCurrentIndex(3);
        QTimer::singleShot(1880, this, SLOT(time_update3()));
    }
    else{
        //失败
        QMovie *movie8 = new QMovie(":/picture/failgif.gif");
        ui->faillable1->setMovie(movie8);
        movie8->start();
        this->ui->stackedWidget->setCurrentIndex(6);
        QTimer::singleShot(3000, this, SLOT(time_update5()));
    }
}

void MainWindow::on_nextButton_clicked() {
    //播放音乐
    QMediaPlayer *player1= new QMediaPlayer(this);
    QAudioOutput *audio1= new QAudioOutput(this);
    player1->setAudioOutput(audio1);
    QString filePath = "qrc:/music/break.mp3";
    player1->setSource(QUrl(filePath));
    player1->play();

    switch(level%6) {
    case 0:
        paintgold1(&v);
        break;
    case 1:
        paintgold2(&v);
        break;
    case 2:
        paintgold3(&v);
        break;
    case 3:
        paintgold4(&v);
        break;
    case 4:
        paintgold5(&v);
        break;
    case 5:
        paintgold6(&v);
        break;
    }
    //商店结算动画
    if(ed){
        QMovie *movie7 = new QMovie(":/picture/shopbyegif.gif");
        ui->shopendlable->setMovie(movie7);
        movie7->start();
        ed=0;
        QMediaPlayer *player9= new QMediaPlayer(this);
        QAudioOutput *audio9= new QAudioOutput(this);
        player9->setAudioOutput(audio9);
        QString filePath = "qrc:/music/buy.mp3";
        player9->setSource(QUrl(filePath));
        player9->play();
    }
    else{
        ui->shopendlable->setPixmap(QPixmap(":/picture/shopnobuy.png"));
        QMediaPlayer *player9= new QMediaPlayer(this);
        QAudioOutput *audio9= new QAudioOutput(this);
        player9->setAudioOutput(audio9);
        QString filePath = "qrc:/music/stone.mp3";
        player9->setSource(QUrl(filePath));
        player9->play();
    }
    ui->goodstextlabel->setStyleSheet(tr("border-image:url(:/picture/goodstext.png);"));
    this->ui->stackedWidget->setCurrentIndex(5);
    QTimer::singleShot(400, this, SLOT(time_update4()));
}

void MainWindow::on_replayButton_clicked() {
    this->ui->stackedWidget->setCurrentIndex(0);
    mo.money_num=0;
    beginflag=0;
    level=0;

    paintgold1(&v);
}

void MainWindow::on_closeButton_clicked() {
    this->close();
}

void MainWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    // 绘制钩子
    painter.setPen(Qt::black);
    painter.drawLine(hookStart, hookEnd);

    // 绘制黄金
    painter.setBrush(Qt::yellow);
    for (std::vector<_Object>::iterator it = v.begin(); it != v.end(); it++) {
        QPixmap pixmapp(":/picture/boom.png");
        painter.drawPixmap(
            it->rect_boom.x(),     // x 坐标
            it->rect_boom.y(),     // y 坐标
            it->rect_boom.width(), // 宽度
            it->rect_boom.height(),// 高度
            pixmapp           // 贴图对象
            );

        QPixmap pixmap1;
        if(it->name=="gold"){
            QPixmap pixmap(":/picture/gold4.png");
            pixmap1 = pixmap;
        }
        else if(it->name=="stone"){
            if(it->grade == 1) {
                QPixmap pixmap(":/picture/stone2.png");
                pixmap1 = pixmap;
            }
            else {
                QPixmap pixmap(":/picture/stone1.png");
                pixmap1 = pixmap;
            }
        }
        else if(it->name=="lucky_bag"){
            QPixmap pixmap(":/picture/random.png");
            pixmap1 = pixmap;
        }
        else if(it->name=="diomond"){
            QPixmap pixmap(":/picture/diamond.png");
            pixmap1 = pixmap;
        }
        else if(it->name=="pig" || it->name=="d_pig") {
            QPixmap pixmap(":/picture/transparent.png");
            pixmap1 = pixmap;
        }
        else if(it->name=="TNT") {
            QPixmap pixmap(":/picture/TNT.png");
            pixmap1 = pixmap;
        }

        painter.drawPixmap(
            it->rect.x(),     // x 坐标
            it->rect.y(),     // y 坐标
            it->rect.width(), // 宽度
            it->rect.height(),// 高度
            pixmap1           // 贴图对象
            );

        if(it->name=="pig") {
            QPixmap pixmap1(":/picture/pig_1.png");
            painter.drawPixmap(
                it->rect_r1.x(),     // x 坐标
                it->rect_r1.y(),     // y 坐标
                it->rect_r1.width(), // 宽度
                it->rect_r1.height(),// 高度
                pixmap1           // 贴图对象
                );
            QPixmap pixmap2(":/picture/pig_2.png");
            painter.drawPixmap(
                it->rect_r2.x(),     // x 坐标
                it->rect_r2.y(),     // y 坐标
                it->rect_r2.width(), // 宽度
                it->rect_r2.height(),// 高度
                pixmap2           // 贴图对象
                );
            QPixmap pixmap3(":/picture/pig_3.png");
            painter.drawPixmap(
                it->rect_r3.x(),     // x 坐标
                it->rect_r3.y(),     // y 坐标
                it->rect_r3.width(), // 宽度
                it->rect_r3.height(),// 高度
                pixmap3           // 贴图对象
                );
            QPixmap pixmap4(":/picture/pig1.png");
            painter.drawPixmap(
                it->rect_l1.x(),     // x 坐标
                it->rect_l1.y(),     // y 坐标
                it->rect_l1.width(), // 宽度
                it->rect_l1.height(),// 高度
                pixmap4           // 贴图对象
                );
            QPixmap pixmap5(":/picture/pig2.png");
            painter.drawPixmap(
                it->rect_l2.x(),     // x 坐标
                it->rect_l2.y(),     // y 坐标
                it->rect_l2.width(), // 宽度
                it->rect_l2.height(),// 高度
                pixmap5           // 贴图对象
                );
            QPixmap pixmap6(":/picture/pig3.png");
            painter.drawPixmap(
                it->rect_l3.x(),     // x 坐标
                it->rect_l3.y(),     // y 坐标
                it->rect_l3.width(), // 宽度
                it->rect_l3.height(),// 高度
                pixmap6           // 贴图对象
                );
        }

        if(it->name=="d_pig") {
            QPixmap pixmap1(":/picture/diomondpig_1.png");
            painter.drawPixmap(
                it->rect_r1.x(),     // x 坐标
                it->rect_r1.y(),     // y 坐标
                it->rect_r1.width(), // 宽度
                it->rect_r1.height(),// 高度
                pixmap1           // 贴图对象
                );
            QPixmap pixmap2(":/picture/diomondpig_2.png");
            painter.drawPixmap(
                it->rect_r2.x(),     // x 坐标
                it->rect_r2.y(),     // y 坐标
                it->rect_r2.width(), // 宽度
                it->rect_r2.height(),// 高度
                pixmap2           // 贴图对象
                );
            QPixmap pixmap3(":/picture/diomondpig_3.png");
            painter.drawPixmap(
                it->rect_r3.x(),     // x 坐标
                it->rect_r3.y(),     // y 坐标
                it->rect_r3.width(), // 宽度
                it->rect_r3.height(),// 高度
                pixmap3           // 贴图对象
                );
            QPixmap pixmap4(":/picture/diomondpig1.png");
            painter.drawPixmap(
                it->rect_l1.x(),     // x 坐标
                it->rect_l1.y(),     // y 坐标
                it->rect_l1.width(), // 宽度
                it->rect_l1.height(),// 高度
                pixmap4           // 贴图对象
                );
            QPixmap pixmap5(":/picture/diomondpig2.png");
            painter.drawPixmap(
                it->rect_l2.x(),     // x 坐标
                it->rect_l2.y(),     // y 坐标
                it->rect_l2.width(), // 宽度
                it->rect_l2.height(),// 高度
                pixmap5           // 贴图对象
                );
            QPixmap pixmap6(":/picture/diomondpig3.png");
            painter.drawPixmap(
                it->rect_l3.x(),     // x 坐标
                it->rect_l3.y(),     // y 坐标
                it->rect_l3.width(), // 宽度
                it->rect_l3.height(),// 高度
                pixmap6           // 贴图对象
                );
        }

    }

    // 绘制钩子头部
    QPixmap pixmap(":/picture/hook.png");

    //头部旋转
    //保存绘制的状态
    painter.save();
    painter.translate(hookEnd.x(), hookEnd.y());
    painter.rotate(angle/3.14*180 - 90);
    painter.translate(-hookEnd.x(), -hookEnd.y());
    //绘制在新的画布位置上
    painter.drawPixmap(
        hookEnd.x() - 15, hookEnd.y(), hookRect.width(), hookRect.height(), pixmap
        );

    for (std::vector<_Object>::iterator it = v.begin(); it != v.end(); it++) {
        QPixmap pixmap1;
        if(it->name=="gold"){
            if(it->grade == 4) {
                QPixmap pixmap_up(":/picture/upgold4.png");
                pixmap1 = pixmap_up;
            }
            if(it->grade == 3) {
                QPixmap pixmap_up(":/picture/upgold3.png");
                pixmap1 = pixmap_up;
            }
            if(it->grade == 2) {
                QPixmap pixmap_up(":/picture/upgold2.png");
                pixmap1 = pixmap_up;
            }
            if(it->grade == 1) {
                QPixmap pixmap_up(":/picture/upgold1.png");
                pixmap1 = pixmap_up;
            }
        }

        if(it->name=="stone"){
            if(it->grade == 2) {
                QPixmap pixmap_up(":/picture/upstone1.png");
                pixmap1 = pixmap_up;
            }
            if(it->grade == 1) {
                QPixmap pixmap_up(":/picture/upstone2.png");
                pixmap1 = pixmap_up;
            }
        }

        if(it->name=="lucky_bag"){
            QPixmap pixmap_up(":/picture/uprandom.png");
            pixmap1 = pixmap_up;
        }

        if(it->name=="diomond"){
            QPixmap pixmap_up(":/picture/updiamond.png");
            pixmap1 = pixmap_up;
        }

        if(it->name=="pig"){
            QPixmap pixmap_up(":/picture/uppig.png");
            pixmap1 = pixmap_up;
        }

        if(it->name=="d_pig"){
            QPixmap pixmap_up(":/picture/updiomondpig.png");
            pixmap1 = pixmap_up;
        }

        painter.drawPixmap(
            it->rect_up.x(),     // x 坐标
            it->rect_up.y(),     // y 坐标
            it->rect_up.width(), // 宽度
            it->rect_up.height(),// 高度
            pixmap1           // 贴图对象
            );

    }

}

bool b_flag=0;
void MainWindow::keyPressEvent(QKeyEvent *event) {
    pressedKeys.insert(event->key());

    // 按下键盘方向键 "下"
    if (pressedKeys.contains(Qt::Key_Down)) {

        QPalette palette;
        QPixmap pixmap(":/picture/gamewholeback2.png");
        palette.setBrush(QPalette::Window, QBrush(pixmap));
        this->setPalette(palette);

        isSwinging = false;
            //timer1->start(10);
    }
    if (pressedKeys.contains(Qt::Key_Up)) {
        if(ed1&&(!isSwinging)&&flag3) {
            b_flag=1;
        }
    }

}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    pressedKeys.remove(event->key());
}
static double c;
static double sin1;
static double cos1;

// 碰撞检测，返回true即为成功
bool MainWindow::collision_detection(QRectF rect){
    int x = hookEnd.x() - 10 * cos(angle);
    int y = hookEnd.y() - 5 * sin(angle);
    if(rect.intersects(QRect(x,y,16,10)))
        return true;
    else
        return false;
}

void MainWindow::time_update6(){
    if(w){
        QPalette palette;
        QPixmap pixmap(":/picture/gamewholeback3.png");
        palette.setBrush(QPalette::Window, QBrush(pixmap));
        this->setPalette(palette);
        QTimer::singleShot(500, this, SLOT(time_update7()));
    }
}
void MainWindow::time_update7(){
    if(w){
        QPalette palette;
        QPixmap pixmap(":/picture/gamewholeback4.png");
        palette.setBrush(QPalette::Window, QBrush(pixmap));
        this->setPalette(palette);
        QTimer::singleShot(500, this, SLOT(time_update6()));
    }
}

void MainWindow::mediaplay() {
    if(!r){
        r=1;
        player3->setAudioOutput(audio3);
        player4->setAudioOutput(audio4);
        player5->setAudioOutput(audio5);
        player6->setAudioOutput(audio6);
        player7->setAudioOutput(audio7);
        player8->setAudioOutput(audio8);
        player9->setAudioOutput(audio9);
        QString filePath3 = "qrc:/music/put.mp3";
        QString filePath4 = "qrc:/music/up.mp3";
        QString filePath5 = "qrc:/music/gold.mp3";
        QString filePath6 = "qrc:/music/biggold.mp3";
        QString filePath7 = "qrc:/music/stone.mp3";
        QString filePath8 = "qrc:/music/boom.mp3";
        QString filePath9 = "qrc:/music/addmoney.mp3";
        player3->setSource(QUrl(filePath3));
        player4->setSource(QUrl(filePath4));
        player5->setSource(QUrl(filePath5));
        player6->setSource(QUrl(filePath6));
        player7->setSource(QUrl(filePath7));
        player8->setSource(QUrl(filePath8));
        player9->setSource(QUrl(filePath9));

    }
}
void MainWindow::animatepig() {
    for(std::vector<_Object>::iterator itt=v.begin();itt!=v.end();itt++){
        if((itt->name=="pig" || itt->name=="d_pig") && itt->caugh==0) {
            if(itt->x_position>itt->ex_x+300 || itt->x_position<itt->ex_x) {
                itt->pig_speed=-itt->pig_speed;
                if(itt->pig_speed>0)
                    itt->x_position=itt->ex_x;
                else
                    itt->x_position=itt->ex_x+300;
            }

            itt->x_position+=itt->pig_speed;
            itt->rect.setRect(itt->x_position,itt->ex_y,2*itt->size,2*itt->size);
            paint_pig(itt);
        }
    }

}
void MainWindow::animateboom() {
    for(std::vector<_Object>::iterator itt=v.begin();itt!=v.end();itt++){
        if(itt->boom) {
            if(itt->name=="TNT")
                expand=15;
            else
                expand=8;

            boom_x+=expand;
            boom_y+=expand;
            itt->rect_boom.setRect(itt->x_position-boom_x/2+itt->size,itt->y_position-boom_y/2+itt->size,boom_x,boom_y);
            itt->rect_up.setRect(0,0,0,0);
            itt->rect.setRect(0,0,0,0);
            itt->rect_l1.setRect(0,0,0,0);
            itt->rect_l2.setRect(0,0,0,0);
            itt->rect_l3.setRect(0,0,0,0);
            itt->rect_r1.setRect(0,0,0,0);
            itt->rect_r2.setRect(0,0,0,0);
            itt->rect_r3.setRect(0,0,0,0);
            itt->caugh=1;

            if(itt->name=="TNT") {
                if(boom_x>500) {
                    itt->boom=0;
                    itt->rect_boom.setRect(0,0,0,0);
                    boom_x=80;
                    boom_y=80;
                }
            }
            else {
                if(boom_x>100*itt->size/20) {
                    itt->boom=0;
                    itt->rect_boom.setRect(0,0,0,0);
                    boom_x=80;
                    boom_y=80;
                }
            }
        }
    }

}

void MainWindow::animateHook()
{
    mediaplay();

    for(int i=1; i<=ed1; ++i){
        switch(i) {
        case 1:
            ui->bomblabel1->setStyleSheet(tr("border-image: url(:/picture/firecracker1.png);"));
            break;
        case 2:
            ui->bomblabel2->setStyleSheet(tr("border-image: url(:/picture/firecracker1.png);"));
            break;
        case 3:
            ui->bomblabel3->setStyleSheet(tr("border-image: url(:/picture/firecracker1.png);"));
            break;
        case 4:
            ui->bomblabel4->setStyleSheet(tr("border-image: url(:/picture/firecracker1.png);"));
            break;
        case 5:
            ui->bomblabel5->setStyleSheet(tr("border-image: url(:/picture/firecracker1.png);"));
            break;
        }
        update();
    }

    for(int i=ed1+1; i<=5; ++i){
        switch(i) {
        case 1:
            ui->bomblabel1->setStyleSheet(tr("border-image: url(:/picture/transparent.png);"));
            break;
        case 2:
            ui->bomblabel2->setStyleSheet(tr("border-image: url(:/picture/transparent.png);"));
            break;
        case 3:
            ui->bomblabel3->setStyleSheet(tr("border-image: url(:/picture/transparent.png);"));
            break;
        case 4:
            ui->bomblabel4->setStyleSheet(tr("border-image: url(:/picture/transparent.png);"));
            break;
        case 5:
            ui->bomblabel5->setStyleSheet(tr("border-image: url(:/picture/transparent.png);"));
            break;
        }
        update();
    }

    // 钩子动画的逻辑
    // 更新钩子起点和终点的坐标，使钩子移动或摆动

    // 在 paintEvent() 中使用的钩子起点和终点坐标
    // hookStart 和 hookEnd 是 QPoint 对象，可以根据需要进行初始化
    if(isSwinging){
        QPalette palette;
        QPixmap pixmap(":/picture/gamewholeback1.png");
        palette.setBrush(QPalette::Window, QBrush(pixmap));
        this->setPalette(palette);

        hookRect.setRect(hookEnd.x() - 15, hookEnd.y(),30,30);

        if (swingDirection) {
            angle += angularSpeed; // 增加摆动角度
            if (angle >= 2.9) {
                swingDirection = false; // 到达最大角度后改变摆动方向
            }
        } else {
            angle -= angularSpeed; // 减小摆动角度
            if (angle <= 0.28) {
                swingDirection = true; // 到达最小角度后改变摆动方向
            }
        }
        // 计算钩子起点和终点的坐标
        c=sqrt((hookStart.x()-hookEnd.x())*(hookStart.x()-hookEnd.x())+(hookStart.y()-hookEnd.y())*(hookStart.y()-hookEnd.y()));
        cos1=-(hookStart.x()-hookEnd.x())/c;
        sin1=-(hookStart.y()-hookEnd.y())/c;
        hookStart = QPointF(width() / 2, 80); // 圆心位置
        hookEnd = hookStart + QPointF(radius * cos(angle), radius * sin(angle)); // 计算终点坐标

        // 更新界面
        update();
    }

    else{
        //收回

        if(hookEnd.x()>width()-25||hookEnd.x()<25||hookEnd.y()>691-35||flag1==1||b_flag==1){
            if(b_flag) {
                player8->play();
                b_flag=0;
                ed1--;
                flag1=1;
                flag2=0;
                flag3=0;
                *boom_tem=1;
            }

            if(flag5) {
                w=1;
                time_update6();
                player4->play();
                player4->setLoops(-1);
                flag4=1;
                flag5=0;
            }

            hookRect.setRect(hookEnd.x() - 15, hookEnd.y(),30,30);
            flag1=1;
            hookEnd = hookEnd - QPointF((float)hook_speed_up*cos(angle), (float)hook_speed_up*sin(angle));

            // 钩子回收成功（空钩子）
            if(hookEnd.y()<(hookStart.y()+radius * sin(angle))) {
                QPalette palette;
                QPixmap pixmap(":/picture/gamewholeback1.png");
                palette.setBrush(QPalette::Window, QBrush(pixmap));
                this->setPalette(palette);
                player4->stop();
                flag5=1;
                w=0;

                isSwinging=true;
                hookEnd = hookStart + QPointF(radius * cos(angle), radius * sin(angle));
                flag1=0;
                update();
            }
            else
                update();
        }

        else {
            string name_tem;

            for(std::vector<_Object>::iterator itt=v.begin();itt!=v.end();itt++){
                // 如果与其中任何一个物体发生了碰撞
                // flag2：是否碰撞
                // flag3：是否已经发生过碰撞

                if (collision_detection(itt->rect)&&flag3==0&&itt->caugh==0){
                    switch(itt->num){
                    case 1:
                        player5->play();
                        break;
                    case 2:
                        player6->play();
                        break;
                    case 3:
                        player7->play();
                        break;
                    case 4:
                        player8->play();
                        break;
                    }

                    if(itt->name=="TNT") {
                        flag1=1;
                        flag2=0;
                        flag3=0;
                        for(std::vector<_Object>::iterator it=v.begin();it!=v.end();it++) {
                            if(it->rect.intersects(QRect(itt->rect.x()-150,itt->rect.y()-150,2*(itt->size+150),2*(itt->size+150)))) {
                                it->boom=1;
                                it->caugh=1;
                            }
                        }
                        break;
                    }

                    hookRect.setRect(hookEnd.x() - 15, hookEnd.y(),0,0);
                    itt->rect.setRect(0,0,0,0);
                    clear_pig(itt);
                    goldRect=&itt->rect_up;
                    goldRect->setRect(hookEnd.x() - itt->size, hookEnd.y(), 1.9*itt->size, 1.9*itt->size);

                    boom_tem=&itt->boom;
                    ex_x_tem=&itt->x_position;
                    ex_y_tem=&itt->y_position;

                    flag2=1;
                    flag3=1;
                    hook_speed=itt->lift_speed;
                    value_tem=itt->value;
                    if(ed2!=0){
                        hook_speed=4.5;
                    }
                    size_tem=2 * itt->size;
                    if(ed3==1&&itt->name=="lucky bag"){
                        value_tem=rand()%500+300;
                    }
                    if(ed4!=0&&itt->name=="stone"){
                        value_tem*=3;
                    }
                    if(ed5!=0&&(itt->name=="diomond" ||itt->name=="d_pig")){
                        value_tem+=200;
                    }

                    name_tem=itt->name;
                    itt->caugh=1;

                    break;
                }
            }

            if (flag2==1) {

                if(flag5){

                    w=1;
                    time_update6();
                    player4->play();
                    player4->setLoops(-1);
                    flag4=1;
                    flag5=0;

                }

                hookRect.setRect(hookEnd.x() - 15, hookEnd.y(),0,0);
                hookEnd = hookEnd - QPointF((float)hook_speed*cos(angle), (float)hook_speed*sin(angle));
                // 以angle角把gold举上来
                goldRect->setRect(-(float)hook_speed*cos(angle)+goldRect->x(),-(float)hook_speed*sin(angle)+goldRect->y(),size_tem ,size_tem);
                *ex_x_tem=goldRect->x();
                *ex_y_tem=goldRect->y();

                // 成功收回来（连带物品）
                if(hookEnd.y()<(hookStart.y()+radius * sin(angle))){

                    QPalette palette;
                    QPixmap pixmap(":/picture/gamewholeback1.png");
                    palette.setBrush(QPalette::Window, QBrush(pixmap));
                    this->setPalette(palette);
                    player4->stop();
                    flag5=1;
                    w=0;

                    player9->play();//如果福袋开出炸药或其他东西需要换音频

                    isSwinging=true;
                    hookEnd = hookStart + QPointF(radius * cos(angle), radius * sin(angle));
                    flag2=0;
                    flag3=0;
                    goldRect->setRect(0,0,0,0);
                    hookRect.setRect(hookEnd.x() - 15, hookEnd.y(),30,30);
                    mo.money_num+=value_tem;
                    ui->mymoneylable2->setText(QString::number(mo.money_num));
                    update();
                }

                update();
            }
            else{
                if(flag4){
                    QPalette palette;
                    QPixmap pixmap(":/picture/gamewholeback2.png");
                    palette.setBrush(QPalette::Window, QBrush(pixmap));
                    this->setPalette(palette);
                    player3->play();
                    flag4=0;
                }
                hookEnd = hookEnd + QPointF((float)hook_speed_down*cos(angle), (float)hook_speed_down*sin(angle));

            }
            update();
        }
    }

    //猪的动画
    animatepig();
    //爆炸动画
    animateboom();

    update();
}
