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
        painter.drawEllipse(toClick.x()-MARK_SIZE/2,toClick.y()-MARK_SIZE/2,MARK_SIZE,MARK_SIZE);
    }

    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            if(mygame->chessList[i*16+j]==1)
            {
                //黑棋
                painter.setBrush(Qt::black);
                painter.drawEllipse(MARGIN+i*CELL_SIZE-CHESS_SIZE,MARGIN+j*CELL_SIZE-CHESS_SIZE,2*CHESS_SIZE,2*CHESS_SIZE);
            }
            else if(mygame->chessList[i*16+j]==-1)
            {
                //白棋
                painter.setBrush(Qt::white);
                painter.drawEllipse(MARGIN+i*CELL_SIZE-CHESS_SIZE,MARGIN+j*CELL_SIZE-CHESS_SIZE,2*CHESS_SIZE,2*CHESS_SIZE);
            }
        }
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
void MainWindow::mouseMoveEvent(QMouseEvent *event)//用于实现感应鼠标位置
{
    QPoint mypoint=event->pos();
    //toClick=mypoint;
    for(int i=0;i<16*16;i++)
    {
        if(inRange(mypoint,mygame->pointList[i],CLICK_RANGE)
                &&mygame->chessList[i]==0
                &&mygame->playerDo)//遍历pointlist，看是否有与鼠标位置的距离小于识别距离的点位
                                   //且满足该位置没有放棋子,且轮到玩家
        {
            toClick=mygame->pointList[i];
            numToClick=i;
            toClickY=numToClick%16;
            toClickX=(numToClick-toClickY)/16;
            ifClick=true;
            break;
        }
        else ifClick=false;
    }
    update();

}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(ifClick==false)
        return;
    else
    {
          manDo();//人来落子
          ifClick=false;//落子之后改变状态
    }
    QTimer::singleShot(500, this, SLOT(AIdo()));
}

void MainWindow::manDo()
{
    if(ifClick==true)
    {
        mygame->manAction(toClickX,toClickY);
        update();
    }
}
void MainWindow::AIdo()
{
    mygame->AIAction(toClickX,toClickY);
    update();
}
