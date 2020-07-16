#include "game.h"

Game::Game()
{

}

void Game::startGame()
{
     checkList.clear();
     for(int i=0;i<16;i++)
     {
         for(int j=0;j<16;j++)
         {
             checkList.push_back(0);
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
