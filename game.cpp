#include "game.h"

Game::Game()
{

}

void Game::startGame()
{
    chessList.clear();
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            chessList.push_back(0);
        }
    }
    scoreList.clear();
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            scoreList.push_back(0);
        }
        //scoreList[0]=1;
    }
    pointList.clear();
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            pointList.push_back(QPoint(MARGIN+i*CELL_SIZE,MARGIN+j*CELL_SIZE));
        }
    }
    playerDo=true;
}
void Game::manAction(int x, int y)
{
    updatePan(x,y);
}

void Game::updatePan(int x, int y)
{
    if(playerDo)
        chessList[16*x+y]=1;//人下棋
    else
        chessList[16*x+y]=-1;//电脑下棋
    playerDo=!playerDo;//换手
}
void Game::AIAction(int &clickX, int &clickY)
{
    // 计算评分
    calculate();
    int maxx=0;//记录最大评分
    vector<pair<int,int>> pointList;
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            if(chessList[i*16+j]==00)
            {
                if(scoreList[i*16+j]>maxx)
                {
                    pointList.clear();
                    maxx=scoreList[i*16+j];
                    pointList.push_back(make_pair(i,j));
                }
            }
        }
    }
    clickX=pointList[0].first;
    clickY=pointList[0].second;
    updatePan(clickX,clickY);

}

void Game::calculate()
{
    int manNUm=0;//玩家连子
    int AINum=0;//电脑连子
    int emptyNum=0;//空白个数

    scoreList.clear();
    for(int i=0;i<16*16;i++)
    {
        scoreList.push_back(0);//重置评分表
    }
    for(int row=0;row<16;row++)
        for(int line=0;line<16;line++)
        {
            if(chessList[row*16+line]==0)//空格
            {
                for(int yy=-1;yy<=1;yy++)
                    for(int xx=-1;xx<=1;xx++)//遍历周围8个方向
                    {
                        manNUm=0;
                        AINum=0;
                        emptyNum=0;
                        if(yy!=0||xx!=0)
                        {
                            //玩家
                            for(int i=1;i<=4;i++)//计算连子数目
                            {
                                if(row+i*yy>=0&&row+i*yy<=16
                                        &&line+i*xx>=0&&line+i*xx<=16//棋盘范围内
                                        &&chessList[(row+i*yy)*16+line+i*xx]==1)
                                {
                                    manNUm++;
                                }
                                else if(row+i*yy>=0&&row+i*yy<=16
                                        &&line+i*xx>=0&&line+i*xx<=16//棋盘范围内
                                        &&chessList[(row+i*yy)*16+line+i*xx]==0)
                                {
                                    emptyNum++;
                                    break;//连子中断
                                }
                                else break;//不在棋盘范围内
                            }
                            //反向
                            for(int i=1;i<=4;i++)//计算连子数目
                            {
                                if(row-i*yy>=0&&row-i*yy<=16
                                        &&line-i*xx>=0&&line-i*xx<=16//棋盘范围内
                                        &&chessList[(row-i*yy)*16+line-i*xx]==1)
                                {
                                    manNUm++;
                                }
                                else if(row-i*yy>=0&&row-i*yy<=16
                                        &&line-i*xx>=0&&line-i*xx<=16//棋盘范围内
                                        &&chessList[(row-i*yy)*16+line-i*xx]==0)
                                {
                                    emptyNum++;
                                    break;//连子中断
                                }
                                else break;//不在棋盘范围内
                            }
                            if(manNUm==1)
                                scoreList[row*16+line]+=10;//杀二
                            else if(manNUm==2)
                            {
                                if(emptyNum==1)
                                {
                                    scoreList[row*16+line]+=30;
                                }
                                else if(emptyNum==2)
                                {
                                    scoreList[row*16+line]+=40;//杀三
                                }

                            }
                            else if(manNUm==3)
                            {
                                if(emptyNum==1)
                                    scoreList[row*16+line]+=60;
                                else if(emptyNum==2)
                                    scoreList[row*16+line]+=300;
                            }
                            else if(manNUm==4)
                            {
                                scoreList[row*16+line]+=20000;//必杀
                            }
                            emptyNum=0;

                            //电脑
                            for(int i=1;i<=4;i++)//计算连子数目
                            {
                                if(row+i*yy>=0&&row+i*yy<=16
                                        &&line+i*xx>=0&&line+i*xx<=16//棋盘范围内
                                        &&chessList[(row+i*yy)*16+line+i*xx]==-1)//电脑的子
                                {
                                    AINum++;
                                }
                                else if(row+i*yy>=0&&row+i*yy<=16
                                        &&line+i*xx>=0&&line+i*xx<=16//棋盘范围内
                                        &&chessList[(row+i*yy)*16+line+i*xx]==0)
                                {
                                    emptyNum++;
                                    break;//连子中断
                                }
                                else break;//不在棋盘范围内
                            }
                            //反向
                            for(int i=1;i<=4;i++)//计算连子数目
                            {
                                if(row-i*yy>=0&&row-i*yy<=16
                                        &&line-i*xx>=0&&line-i*xx<=16//棋盘范围内
                                        &&chessList[(row-i*yy)*16+line-i*xx]==-1)
                                {
                                    AINum++;
                                }
                                else if(row-i*yy>=0&&row-i*yy<=16
                                        &&line-i*xx>=0&&line-i*xx<=16//棋盘范围内
                                        &&chessList[(row-i*yy)*16+line-i*xx]==0)
                                {
                                    emptyNum++;
                                    break;//连子中断
                                }
                                else break;//不在棋盘范围内
                            }
                            if(AINum==0)
                                scoreList[row*16+line]+=5;
                            else if(AINum==1)
                                scoreList[row*16+line]+=10;
                            else if(AINum==2)
                            {
                                if(emptyNum==1)
                                    scoreList[row*16+line]+=25;
                                else if(emptyNum==2)
                                    scoreList[row*16+line]+=50;
                            }
                            else if(AINum==3)
                            {
                                if(emptyNum==1)
                                    scoreList[row*16+line]+=55;
                                else if(emptyNum==2)
                                    scoreList[row*16+line]+=100;
                            }
                            else if (AINum>=4)
                                scoreList[row*16+line]+=30000;

                        }
                    }
            }
        }

}
