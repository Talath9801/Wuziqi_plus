#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(MARGIN*2+TOTAL_PAN_SIZE*CELL_SIZE,MARGIN*2+TOTAL_PAN_SIZE*CELL_SIZE);
    inGame();//开始游戏
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int  i=0;i<16;i++)
    {
        painter.drawLine(MARGIN,MARGIN+i*CELL_SIZE,MARGIN+15*CELL_SIZE,MARGIN+i*CELL_SIZE);
        painter.drawLine(MARGIN+i*CELL_SIZE,MARGIN,MARGIN+i*CELL_SIZE,MARGIN+15*CELL_SIZE);
    }//绘制棋盘
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inGame()//构造函数中调用，初始化一个游戏
{
    mygame=new Game;
    mygame->myGameCondition=playing;//设置为游戏中
    mygame->startGame();
    update();
}
