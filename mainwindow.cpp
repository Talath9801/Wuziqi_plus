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

    painter.setBrush(Qt::black);
    if(ifClick)
    {
        painter.drawEllipse(toClick.x(),toClick.y(),MARK_SIZE,MARK_SIZE);
    }
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
void MainWindow::mouseTracking(QMouseEvent *event)
{
    QPoint mypoint=event->pos();
    for(int i=0;i<16*16;i++)
    {
        if(inRange(mypoint,mygame->pointList[i],CLICK_RANGE))//遍历pointlist，看是否有与鼠标位置的距离小于识别距离的点位
        {
            toClick=mygame->pointList[i];
            ifClick=true;
            break;
        }
    }
    update();
}
