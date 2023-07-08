#ifndef GOODS_H
#define GOODS_H

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMediaplayer>
#include<QAudioOutput>
#include<QPainter>
#include<QKeyEvent>
using namespace std;

class Bomb {
public:
    void appear(int p, Ui::MainWindow *ui);
    void disappear(Ui::MainWindow *ui);
};

class Generative_Water {
public:
    void appear(int p, Ui::MainWindow *ui);
    void disappear(Ui::MainWindow *ui);
};

class Lucky_Clover {
public:
    void appear(int p, Ui::MainWindow *ui);
    void disappear(Ui::MainWindow *ui);
};

class Stone_Book {
public:
    void appear(int p, Ui::MainWindow *ui);
    void disappear(Ui::MainWindow *ui);
};

class Nice_Diomond {
public:
    void appear(int p, Ui::MainWindow *ui);
    void disappear(Ui::MainWindow *ui);
};

#endif // GOODS_H
