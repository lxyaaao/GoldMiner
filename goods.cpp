#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "goods.h"
#include<QMediaplayer>
#include<QAudioOutput>
#include<QPainter>
#include<QKeyEvent>

using namespace std;

void Bomb::appear(int p, Ui::MainWindow *ui) {
    QFont font1;
    font1.setPointSize(20); // 设置字体大小
    font1.setBold(true); // 设置字体加粗

    ui->fireButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->fireButton->setStyleSheet("QPushButton{border-image:url(:/picture/firecracker1.png);}"
                                  "QPushButton:hover{border-image:url(:/picture/firecracker2.png);}");

    ui->firelabel1->setStyleSheet("background-color: transparent");
    ui->firelabel1->setFont(font1);
    ui->firelabel1->setStyleSheet("color: #227700;");
    ui->firelabel1->setText("$");

    ui->firelabel2->setStyleSheet("background-color: transparent");
    ui->firelabel2->setFont(font1);
    ui->firelabel2->setStyleSheet("color: #227700;");
    ui->firelabel2->setText(QString::number(p));
}

void Bomb::disappear(Ui::MainWindow *ui) {
    ui->fireButton->setCursor(QCursor(Qt::ArrowCursor));
    ui->fireButton->setStyleSheet("QPushButton{border-image:url(:/picture/transparent.png);}"
                                  "QPushButton:hover{border-image:url(:/picture/transparent.png);}");

    ui->firelabel1->setText(" ");
    ui->firelabel2->setText(" ");
}

void Generative_Water::appear(int p, Ui::MainWindow *ui) {
    QFont font1;
    font1.setPointSize(20); // 设置字体大小
    font1.setBold(true); // 设置字体加粗

    ui->strongButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->strongButton->setStyleSheet("QPushButton{border-image:url(:/picture/stronger1.png);}"
                                    "QPushButton:hover{border-image:url(:/picture/stronger2.png);}");

    ui->stronglabel1->setStyleSheet("background-color: transparent");
    ui->stronglabel1->setFont(font1);
    ui->stronglabel1->setStyleSheet("color: #227700;");
    ui->stronglabel1->setText("$");

    ui->stronglabel2->setStyleSheet("background-color: transparent");
    ui->stronglabel2->setFont(font1);
    ui->stronglabel2->setStyleSheet("color: #227700;");
    ui->stronglabel2->setText(QString::number(p));
}

void Generative_Water::disappear(Ui::MainWindow *ui) {
    ui->strongButton->setCursor(QCursor(Qt::ArrowCursor));
    ui->strongButton->setStyleSheet("QPushButton{border-image:url(:/picture/transparent.png);}"
                                    "QPushButton:hover{border-image:url(:/picture/transparent.png);}");

    ui->stronglabel1->setText(" ");
    ui->stronglabel2->setText(" ");
}

void Lucky_Clover::appear(int p, Ui::MainWindow *ui) {
    QFont font1;
    font1.setPointSize(20); // 设置字体大小
    font1.setBold(true); // 设置字体加粗

    ui->luckButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->luckButton->setStyleSheet("QPushButton{border-image:url(:/picture/luckier1.png);}"
                                  "QPushButton:hover{border-image:url(:/picture/luckier2.png);}");

    ui->lucklabel1->setStyleSheet("background-color: transparent");
    ui->lucklabel1->setFont(font1);
    ui->lucklabel1->setStyleSheet("color: #227700;");
    ui->lucklabel1->setText("$");

    ui->lucklabel2->setStyleSheet("background-color: transparent");
    ui->lucklabel2->setFont(font1);
    ui->lucklabel2->setStyleSheet("color: #227700;");
    ui->lucklabel2->setText(QString::number(p));
}

void Lucky_Clover::disappear(Ui::MainWindow *ui) {
    ui->luckButton->setCursor(QCursor(Qt::ArrowCursor));
    ui->luckButton->setStyleSheet("QPushButton{border-image:url(:/picture/transparent.png);}"
                                  "QPushButton:hover{border-image:url(:/picture/transparent.png);}");

    ui->lucklabel1->setText(" ");
    ui->lucklabel2->setText(" ");
}

void Stone_Book::appear(int p, Ui::MainWindow *ui) {
    QFont font1;
    font1.setPointSize(20); // 设置字体大小
    font1.setBold(true); // 设置字体加粗

    ui->stoneButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->stoneButton->setStyleSheet("QPushButton{border-image:url(:/picture/betterstone1.png);}"
                                   "QPushButton:hover{border-image:url(:/picture/betterstone2.png);}"
                                   );

    ui->stonelabel1->setStyleSheet("background-color: transparent");
    ui->stonelabel1->setFont(font1);
    ui->stonelabel1->setStyleSheet("color: #227700;");
    ui->stonelabel1->setText("$");

    ui->stonelabel2->setStyleSheet("background-color: transparent");
    ui->stonelabel2->setFont(font1);
    ui->stonelabel2->setStyleSheet("color: #227700;");
    ui->stonelabel2->setText(QString::number(p));
}

void Stone_Book::disappear(Ui::MainWindow *ui) {
    ui->stoneButton->setCursor(QCursor(Qt::ArrowCursor));
    ui->stoneButton->setStyleSheet("QPushButton{border-image:url(:/picture/transparent.png);}"
                                   "QPushButton:hover{border-image:url(:/picture/transparent.png);}"
                                   );

    ui->stonelabel1->setText(" ");
    ui->stonelabel2->setText(" ");
}

void Nice_Diomond::appear(int p, Ui::MainWindow *ui) {
    QFont font1;
    font1.setPointSize(20); // 设置字体大小
    font1.setBold(true); // 设置字体加粗

    ui->diamondButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->diamondButton->setStyleSheet("QPushButton{border-image:url(:/picture/betterdiamond1.png);}"
                                     "QPushButton:hover{border-image:url(:/picture/betterdiamond2.png);}"
                                     );

    ui->diomondlabel1->setStyleSheet("background-color: transparent");
    ui->diomondlabel1->setFont(font1);
    ui->diomondlabel1->setStyleSheet("color: #227700;");
    ui->diomondlabel1->setText("$");

    ui->diomondlabel2->setStyleSheet("background-color: transparent");
    ui->diomondlabel2->setFont(font1);
    ui->diomondlabel2->setStyleSheet("color: #227700;");
    ui->diomondlabel2->setText(QString::number(p));
}

void Nice_Diomond::disappear(Ui::MainWindow *ui) {
    ui->diamondButton->setCursor(QCursor(Qt::ArrowCursor));
    ui->diamondButton->setStyleSheet("QPushButton{border-image:url(:/picture/transparent.png);}"
                                     "QPushButton:hover{border-image:url(:/picture/transparent.png);}"
                                     );

    ui->diomondlabel1->setText(" ");
    ui->diomondlabel2->setText(" ");
}
