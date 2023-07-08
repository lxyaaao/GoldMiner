#include "object.h"
#include "level.h"

void paintgold1(vector<_Object> *v) {
    QRectF* GRect;
    QRectF* GRect_up;

    int count = 0;
    for(std::vector<_Object>::iterator itt=v->begin();itt!=v->end();itt++){
        itt->caugh=0;

        GRect_up=&itt->rect_up;
        GRect_up->setRect(0,0,0,0);
        itt->rect_l1.setRect(0,0,0,0);
        itt->rect_l2.setRect(0,0,0,0);
        itt->rect_l3.setRect(0,0,0,0);
        itt->rect_r1.setRect(0,0,0,0);
        itt->rect_r2.setRect(0,0,0,0);
        itt->rect_r3.setRect(0,0,0,0);

        GRect=&itt->rect;
        GRect->setRect(0,0,0,0);

        switch(count){
        case 0:
            GRect->setRect(200,200,2*itt->size,2*itt->size);
            break;
        case 1:
            GRect->setRect(700,300,2*itt->size,2*itt->size);
            break;
        case 2:
            GRect->setRect(450,500,2*itt->size,2*itt->size);
            break;
        case 3:
            GRect->setRect(500,300,2*itt->size,2*itt->size);
            break;
        case 4:
            GRect->setRect(200,350,2*itt->size,2*itt->size);
            break;
        case 5:
            itt->caugh=1;
            break;
        case 6:
            GRect->setRect(750,450,2*itt->size,2*itt->size);
            break;
        case 7:
            itt->caugh=1;
            break;
        case 8:
            GRect->setRect(100,250,2*itt->size,2*itt->size);
            break;
        case 9:
            GRect->setRect(600,600,2*itt->size,2*itt->size);
            break;
        case 10:
            GRect->setRect(250,550,2*itt->size,2*itt->size);
            break;
        case 11:
            GRect->setRect(550,400,2*itt->size,2*itt->size);
            break;
        case 12:
            GRect->setRect(800,200,2*itt->size,2*itt->size);
            break;
        case 13:
            itt->caugh=1;
            break;
        case 14:
            GRect->setRect(400,200,2*itt->size,2*itt->size);
            break;
        }

        if(count>14)
            itt->caugh=1;

        itt->x_position=GRect->x();
        itt->y_position=GRect->y();
        itt->ex_x=GRect->x();
        itt->ex_y=GRect->y();

        ++count;
    }


}

void paintgold2(vector<_Object> *v) {
    QRectF* GRect;
    QRectF* GRect_up;

    int count = 0;
    for(std::vector<_Object>::iterator itt=v->begin();itt!=v->end();itt++){
        itt->caugh=0;

        GRect_up=&itt->rect_up;
        GRect_up->setRect(0,0,0,0);
        itt->rect_l1.setRect(0,0,0,0);
        itt->rect_l2.setRect(0,0,0,0);
        itt->rect_l3.setRect(0,0,0,0);
        itt->rect_r1.setRect(0,0,0,0);
        itt->rect_r2.setRect(0,0,0,0);
        itt->rect_r3.setRect(0,0,0,0);

        GRect=&itt->rect;
        GRect->setRect(0,0,0,0);

        switch(count){
        case 0:
            GRect->setRect(200,400,2*itt->size,2*itt->size);
            break;
        case 4:
            GRect->setRect(800,400,2*itt->size,2*itt->size);
            break;
        case 5:
            GRect->setRect(400,300,2*itt->size,2*itt->size);
            break;
        case 6:
            GRect->setRect(250,500,2*itt->size,2*itt->size);
            break;
        case 8:
            GRect->setRect(300,200,2*itt->size,2*itt->size);
            break;
        case 10:
            GRect->setRect(100,550,2*itt->size,2*itt->size);
            break;
        case 11:
            GRect->setRect(600,300,2*itt->size,2*itt->size);
            break;
        case 12:
            GRect->setRect(100,250,2*itt->size,2*itt->size);
            break;
        case 13:
            GRect->setRect(700,600,2*itt->size,2*itt->size);
            break;
        case 18:
            GRect->setRect(500,200,2*itt->size,2*itt->size);
            break;
        case 19:
            GRect->setRect(400,500,2*itt->size,2*itt->size);
            break;
        }

        if(count ==16 || count == 17)
            itt->caugh=1;

        itt->x_position=GRect->x();
        itt->y_position=GRect->y();
        itt->ex_x=GRect->x();
        itt->ex_y=GRect->y();
        ++count;
    }
}

void paintgold3(vector<_Object> *v) {
    QRectF* GRect;
    QRectF* GRect_up;

    int count = 0;
    for(std::vector<_Object>::iterator itt=v->begin();itt!=v->end();itt++){
        itt->caugh=0;

        GRect_up=&itt->rect_up;
        GRect_up->setRect(0,0,0,0);
        itt->rect_l1.setRect(0,0,0,0);
        itt->rect_l2.setRect(0,0,0,0);
        itt->rect_l3.setRect(0,0,0,0);
        itt->rect_r1.setRect(0,0,0,0);
        itt->rect_r2.setRect(0,0,0,0);
        itt->rect_r3.setRect(0,0,0,0);

        GRect=&itt->rect;
        GRect->setRect(0,0,0,0);

        switch(count){
        case 0:
            GRect->setRect(800,290,2*itt->size,2*itt->size);
            break;
        case 2:
            GRect->setRect(400,250,2*itt->size,2*itt->size);
            break;
        case 4:
            GRect->setRect(150,200,2*itt->size,2*itt->size);
            break;
        case 5:
            GRect->setRect(250,500,2*itt->size,2*itt->size);
            break;
        case 6:
            GRect->setRect(650,350,2*itt->size,2*itt->size);
            break;
        case 8:
            GRect->setRect(160,350,2*itt->size,2*itt->size);
            break;
        case 10:
            GRect->setRect(100,500,2*itt->size,2*itt->size);
            break;
        case 12:
            GRect->setRect(600,200,2*itt->size,2*itt->size);
            break;
        case 13:
            GRect->setRect(300,350,2*itt->size,2*itt->size);
            break;
        case 16:
            GRect->setRect(500,550,2*itt->size,2*itt->size);
            break;
        case 20:
            GRect->setRect(300,250,2*itt->size,2*itt->size);
            break;
        }

        if(count >= 17 && count != 20)
            itt->caugh=1;

        itt->x_position=GRect->x();
        itt->y_position=GRect->y();
        itt->ex_x=GRect->x();
        itt->ex_y=GRect->y();
        ++count;
    }

}

void paintgold4(vector<_Object> *v) {
    QRectF* GRect;
    QRectF* GRect_up;

    int count = 0;
    for(std::vector<_Object>::iterator itt=v->begin();itt!=v->end();itt++){
        itt->caugh=0;

        GRect_up=&itt->rect_up;
        GRect_up->setRect(0,0,0,0);
        itt->rect_l1.setRect(0,0,0,0);
        itt->rect_l2.setRect(0,0,0,0);
        itt->rect_l3.setRect(0,0,0,0);
        itt->rect_r1.setRect(0,0,0,0);
        itt->rect_r2.setRect(0,0,0,0);
        itt->rect_r3.setRect(0,0,0,0);

        GRect=&itt->rect;
        GRect->setRect(0,0,0,0);

        switch(count){
        case 1:
            GRect->setRect(800,300,2*itt->size,2*itt->size);
            break;
        case 2:
            GRect->setRect(250,350,2*itt->size,2*itt->size);
            break;
        case 3:
            GRect->setRect(200,200,2*itt->size,2*itt->size);
            break;
        case 4:
            GRect->setRect(100,450,2*itt->size,2*itt->size);
            break;
        case 5:
            GRect->setRect(450,500,2*itt->size,2*itt->size);
            break;
        case 6:
            GRect->setRect(750,450,2*itt->size,2*itt->size);
            break;
        case 8:
            GRect->setRect(600,200,2*itt->size,2*itt->size);
            break;
        case 10:
            GRect->setRect(300,500,2*itt->size,2*itt->size);
            break;
        case 11:
            GRect->setRect(550,300,2*itt->size,2*itt->size);
            break;
        case 12:
            GRect->setRect(850,150,2*itt->size,2*itt->size);
            break;
        case 14:
            GRect->setRect(400,200,2*itt->size,2*itt->size);
            break;
        case 15:
            GRect->setRect(700,350,2*itt->size,2*itt->size);
            break;
        case 20:
            GRect->setRect(300,200,2*itt->size,2*itt->size);
            break;
        }

        if(count>=16&&count<=19)
            itt->caugh=1;

        itt->x_position=GRect->x();
        itt->y_position=GRect->y();
        itt->ex_x=GRect->x();
        itt->ex_y=GRect->y();

        ++count;
    }


}

void paintgold5(vector<_Object> *v) {
    QRectF* GRect;
    QRectF* GRect_up;

    int count = 0;
    for(std::vector<_Object>::iterator itt=v->begin();itt!=v->end();itt++){
        itt->caugh=0;

        GRect_up=&itt->rect_up;
        GRect_up->setRect(0,0,0,0);
        itt->rect_l1.setRect(0,0,0,0);
        itt->rect_l2.setRect(0,0,0,0);
        itt->rect_l3.setRect(0,0,0,0);
        itt->rect_r1.setRect(0,0,0,0);
        itt->rect_r2.setRect(0,0,0,0);
        itt->rect_r3.setRect(0,0,0,0);

        GRect=&itt->rect;
        GRect->setRect(0,0,0,0);

        switch(count){
        case 3:
            GRect->setRect(850,150,2*itt->size,2*itt->size);
            break;
        case 4:
            GRect->setRect(750,450,2*itt->size,2*itt->size);
            break;
        case 6:
            GRect->setRect(100,500,2*itt->size,2*itt->size);
            break;
        case 8:
            GRect->setRect(600,200,2*itt->size,2*itt->size);
            break;
        case 10:
            GRect->setRect(350,180,2*itt->size,2*itt->size);
            break;
        case 11:
            GRect->setRect(150,210,2*itt->size,2*itt->size);
            break;
        case 12:
            GRect->setRect(450,300,2*itt->size,2*itt->size);
            break;
        case 13:
            GRect->setRect(300,500,2*itt->size,2*itt->size);
            break;
        case 15:
            GRect->setRect(150,400,2*itt->size,2*itt->size);
            break;
        case 16:
            GRect->setRect(550,280,2*itt->size,2*itt->size);
            break;
        case 17:
            GRect->setRect(300,400,2*itt->size,2*itt->size);
            break;
        case 18:
            GRect->setRect(100,300,2*itt->size,2*itt->size);
            break;
        case 19:
            GRect->setRect(450,580,2*itt->size,2*itt->size);
            break;
        }

        itt->x_position=GRect->x();
        itt->y_position=GRect->y();
        itt->ex_x=GRect->x();
        itt->ex_y=GRect->y();

        ++count;
    }


}

void paintgold6(vector<_Object> *v) {
    QRectF* GRect;
    QRectF* GRect_up;

    int count = 0;
    for(std::vector<_Object>::iterator itt=v->begin();itt!=v->end();itt++){
        itt->caugh=0;

        GRect_up=&itt->rect_up;
        GRect_up->setRect(0,0,0,0);
        itt->rect_l1.setRect(0,0,0,0);
        itt->rect_l2.setRect(0,0,0,0);
        itt->rect_l3.setRect(0,0,0,0);
        itt->rect_r1.setRect(0,0,0,0);
        itt->rect_r2.setRect(0,0,0,0);
        itt->rect_r3.setRect(0,0,0,0);

        GRect=&itt->rect;
        GRect->setRect(0,0,0,0);

        switch(count){
        case 0:
            GRect->setRect(800,180,2*itt->size,2*itt->size);
            break;
        case 1:
            GRect->setRect(80,550,2*itt->size,2*itt->size);
            break;
        case 3:
            GRect->setRect(200,200,2*itt->size,2*itt->size);
            break;
        case 4:
            GRect->setRect(480,450,2*itt->size,2*itt->size);
            break;
        case 8:
            GRect->setRect(150,450,2*itt->size,2*itt->size);
            break;
        case 9:
            GRect->setRect(300,290,2*itt->size,2*itt->size);
            break;
        case 10:
            GRect->setRect(600,250,2*itt->size,2*itt->size);
            break;
        case 12:
            GRect->setRect(700,350,2*itt->size,2*itt->size);
            break;
        case 15:
            GRect->setRect(350,450,2*itt->size,2*itt->size);
            break;
        case 18:
            GRect->setRect(500,550,2*itt->size,2*itt->size);
            break;
        case 19:
            GRect->setRect(150,600,2*itt->size,2*itt->size);
            break;
        case 20:
            GRect->setRect(450,350,2*itt->size,2*itt->size);
            break;
        }

        if(count==16||count==17) {
            itt->caugh=1;
        }

        itt->x_position=GRect->x();
        itt->y_position=GRect->y();
        itt->ex_x=GRect->x();
        itt->ex_y=GRect->y();

        ++count;
    }


}
