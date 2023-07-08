#include "mainwindow.h"
#include "object.h"

_Object::_Object() { }
_Object::~_Object() { }
_Object::_Object(int _grade, int _x, int _y): grade(_grade), x_position(_x), y_position(_y) { }

Gold::Gold() { }
Gold::~Gold(){ }
Gold::Gold(int _grade, int _x, int _y): _Object(_grade, _x, _y), grade(_grade), x_position(_x), y_position(_y) {
    switch(grade) {
    case 1: {
        size = 15;
        value = 50;
        lift_speed = 4.5;
        rect.setRect(x_position-size, y_position-size, 2*size, 2*size);
        num=1;
        break;
    }
    case 2:{
        size = 30;
        value = 100;
        lift_speed = 2.0;
        rect.setRect(x_position-size, y_position-size, 2*size, 2*size);
        num=1;
        break;
    }
    case 3:{
        size = 50;
        value = 250;
        lift_speed = 0.7;
        rect.setRect(x_position-size, y_position-size, 2*size, 2*size);
        num=1;
        break;
    }
    case 4:{
        size = 60;
        value = 500;
        lift_speed = 0.3;
        rect.setRect(x_position-size, y_position-size, 2*size, 2*size);
        num=2;
        break;
    }
    }
    ex_speed = lift_speed;

    _Object::ex_speed = ex_speed;
    _Object::size = size;
    _Object::value = value;
    _Object::lift_speed = lift_speed;
    _Object::name = name;
}

Stone::Stone() { }
Stone::~Stone() { }
Stone::Stone(int _grade, int _x, int _y): _Object(_grade, _x, _y), grade(_grade), x_position(_x), y_position(_y) {
    if(grade == 1) {
        size = 35;
        value = 11;
        lift_speed = 0.7;
        rect.setRect(x_position-size, y_position-size, 2*size, 2*size);
        num=3;
    }
    else {
        size = 40;
        value = 20;
        lift_speed = 0.3;
        rect.setRect(x_position-size, y_position-size, 2*size, 2*size);
        num=3;
    }
    ex_speed = lift_speed;

    _Object::ex_speed = ex_speed;
    _Object::size = size;
    _Object::value = value;
    _Object::lift_speed = lift_speed;
    _Object::name = name;
}

Diomond::Diomond() { }
Diomond::~Diomond() { }
Diomond::Diomond(int _x, int _y): _Object(0, _x, _y), x_position(_x), y_position(_y) {
    size = 15;
    value = 600;
    lift_speed = 4.5;
    ex_speed = lift_speed;
    rect.setRect(x_position-size, y_position-size, 2*size, 2*size);
    num=2;

    _Object::ex_speed = ex_speed;
    _Object::size = size;
    _Object::value = value;
    _Object::lift_speed = lift_speed;
    _Object::name = name;
}

Lucky_Bag::Lucky_Bag() { }
Lucky_Bag::~Lucky_Bag() { }
Lucky_Bag::Lucky_Bag(int _x, int _y): _Object(0, _x, _y), x_position(_x), y_position(_y) {
    size = 30;
    value = rand() % 600 + 1;
    lift_speed =double(rand()%100) / 50 + 0.2;
    ex_speed = lift_speed;
    rect.setRect(x_position-size, y_position-size, 2*size, 2*size);
    num=1;

    _Object::ex_speed = ex_speed;
    _Object::size = size;
    _Object::value = value;
    _Object::lift_speed = lift_speed;
    _Object::name = name;
}

Pig::Pig() { }
Pig::~Pig() { }
Pig::Pig(int _x, int _y): _Object(0, _x, _y), x_position(_x), y_position(_y) {
    size = 20;
    value = 2;
    lift_speed = 3;
    ex_speed = lift_speed;
    rect.setRect(x_position-size, y_position-size, 2*size, 2*size);
    num=3;

    ex_x=x_position;
    ex_y=y_position;
    _Object::ex_x=x_position;
    _Object::ex_y=y_position;

    _Object::ex_speed = ex_speed;
    _Object::size = size;
    _Object::value = value;
    _Object::lift_speed = lift_speed;
    _Object::name = name;
}

D_Pig::D_Pig() { }
D_Pig::~D_Pig() { }
D_Pig::D_Pig(int _x, int _y): _Object(0, _x, _y), x_position(_x), y_position(_y) {
    size = 20;
    value = 602;
    lift_speed = 3;
    ex_speed = lift_speed;
    rect.setRect(x_position-size, y_position-size, 2*size, 2*size);
    num=2;

    ex_x=x_position;
    ex_y=y_position;
    _Object::ex_x=x_position;
    _Object::ex_y=y_position;

    _Object::ex_speed = ex_speed;
    _Object::size = size;
    _Object::value = value;
    _Object::lift_speed = lift_speed;
    _Object::name = name;
}

TNT::TNT() { }
TNT::~TNT() { }
TNT::TNT(int _x, int _y): _Object(0, _x, _y), x_position(_x), y_position(_y) {
    size = 30;
    lift_speed = 10;
    rect.setRect(x_position-size, y_position-size, 2*size, 2*size);
    num=4;

    ex_x=x_position;
    ex_y=y_position;
    _Object::ex_x=x_position;
    _Object::ex_y=y_position;

    _Object::ex_speed = ex_speed;
    _Object::size = size;
    _Object::value = value;
    _Object::lift_speed = lift_speed;
    _Object::name = name;
}

void paint_pig(std::vector<_Object>::iterator itt) {
    if(itt->pig_speed>0) {
        if((itt->x_position-itt->ex_x)%30<=10) {
            itt->rect_r1.setRect(itt->x_position,itt->y_position,2*itt->size,2*itt->size);
            itt->rect_r2.setRect(0,0,0,0);
            itt->rect_r3.setRect(0,0,0,0);
            itt->rect_l1.setRect(0,0,0,0);
            itt->rect_l2.setRect(0,0,0,0);
            itt->rect_l3.setRect(0,0,0,0);
        }
        else if((itt->x_position-itt->ex_x)%30>=20) {
            itt->rect_r3.setRect(itt->x_position,itt->y_position,2*itt->size,2*itt->size);
            itt->rect_r2.setRect(0,0,0,0);
            itt->rect_r1.setRect(0,0,0,0);
            itt->rect_l1.setRect(0,0,0,0);
            itt->rect_l2.setRect(0,0,0,0);
            itt->rect_l3.setRect(0,0,0,0);
        }
        else {
            itt->rect_r2.setRect(itt->x_position,itt->y_position,2*itt->size,2*itt->size);
            itt->rect_r1.setRect(0,0,0,0);
            itt->rect_r3.setRect(0,0,0,0);
            itt->rect_l1.setRect(0,0,0,0);
            itt->rect_l2.setRect(0,0,0,0);
            itt->rect_l3.setRect(0,0,0,0);
        }
    }
    else {
        if((itt->x_position-itt->ex_x)%30<=10) {
            itt->rect_l1.setRect(itt->x_position,itt->y_position,2*itt->size,2*itt->size);
            itt->rect_r2.setRect(0,0,0,0);
            itt->rect_r3.setRect(0,0,0,0);
            itt->rect_r1.setRect(0,0,0,0);
            itt->rect_l2.setRect(0,0,0,0);
            itt->rect_l3.setRect(0,0,0,0);
        }
        else if((itt->x_position-itt->ex_x)%30>=20) {
            itt->rect_l3.setRect(itt->x_position,itt->y_position,2*itt->size,2*itt->size);
            itt->rect_r2.setRect(0,0,0,0);
            itt->rect_r1.setRect(0,0,0,0);
            itt->rect_r3.setRect(0,0,0,0);
            itt->rect_l2.setRect(0,0,0,0);
            itt->rect_l1.setRect(0,0,0,0);
        }
        else {
            itt->rect_l2.setRect(itt->x_position,itt->y_position,2*itt->size,2*itt->size);
            itt->rect_r1.setRect(0,0,0,0);
            itt->rect_r3.setRect(0,0,0,0);
            itt->rect_r2.setRect(0,0,0,0);
            itt->rect_l1.setRect(0,0,0,0);
            itt->rect_l3.setRect(0,0,0,0);
        }
    }
}
void clear_pig(std::vector<_Object>::iterator itt) {
    itt->rect_r1.setRect(0,0,0,0);
    itt->rect_r2.setRect(0,0,0,0);
    itt->rect_r3.setRect(0,0,0,0);
    itt->rect_l1.setRect(0,0,0,0);
    itt->rect_l2.setRect(0,0,0,0);
    itt->rect_l3.setRect(0,0,0,0);
}

