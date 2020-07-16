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
     playerDo=true;
}
