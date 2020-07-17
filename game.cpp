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
void Game::AIAction(int x, int y)
{

}
