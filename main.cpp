#include "mainwindow.h"
#include <QTimer>
#include <QMovie>
#include<QMediaplayer>
#include <QApplication>
#include<QAudioOutput>
#include "goods.h"
#include "money.h"
#include "object.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
