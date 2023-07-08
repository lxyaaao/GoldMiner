#ifndef OBJECT_H
#define OBJECT_H

#include <QMainWindow>
#include <iostream>
#include <cstring>
#include<QRect>
using namespace std;

class _Object {
public:
    string name;
    int grade;
    int size;//离中心点上下左右的距离
    int value;
    double lift_speed;
    int x_position;
    int y_position;
    int ex_speed;
    int num;

    int ex_x;
    int ex_y;
    bool caugh=0;
    int pig_speed=1;
    int boom=0;

    QRectF rect;
    QRectF rect_up;
    QRectF rect_r1, rect_r2, rect_r3, rect_l1, rect_l2, rect_l3;

    QRectF rect_boom;

    _Object();
    _Object(int _grade, int _x, int _y);

    virtual ~_Object();
};

class Gold : public _Object{
public:
    string name = "gold";
    int grade; // 分为1,2,3,4四种等级大小
    int x_position;
    int y_position;

    Gold();
    Gold(int _grade, int _x, int _y);

    ~Gold();
};

class Stone : public _Object{
public:
    string name = "stone";
    int grade; // 分为1,2三种等级大小
    int x_position;
    int y_position;

    Stone();
    Stone(int _grade, int _x, int _y);

    ~Stone();
};

class Diomond : public _Object{
public:
    string name = "diomond";
    int x_position;
    int y_position;

    Diomond();
    Diomond(int _x, int _y);

    ~Diomond();
};

class Lucky_Bag : public _Object{
public:
    string name = "lucky_bag";
    int x_position;
    int y_position;
    Lucky_Bag();
    Lucky_Bag(int _x, int _y);

    ~Lucky_Bag();
};

class Pig : public _Object{
public:
    string name = "pig";
    int x_position;
    int y_position;
    Pig();
    Pig(int _x, int _y);

    ~Pig();
};

class D_Pig : public _Object{
public:
    string name = "d_pig";
    int x_position;
    int y_position;
    D_Pig();
    D_Pig(int _x, int _y);

    ~D_Pig();
};

class TNT: public _Object{
public:
    string name = "TNT";
    int x_position;
    int y_position;
    TNT();
    TNT(int _x, int _y);

    ~TNT();
};

void paint_pig(std::vector<_Object>::iterator itt);
void clear_pig(std::vector<_Object>::iterator itt);

#endif // OBJECT_H
