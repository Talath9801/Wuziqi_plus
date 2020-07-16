#include "game.h"

Game::Game()
{

}

void Game::startGame()
{
    ChessList.clear();
    for(int i=0;i<(PAN_SIZE+1)*(PAN_SIZE+1);i++)
    {
        ChessList.push_back(0);
    }
    ScoreList.clear();
    for(int i=0;i<(PAN_SIZE+1)*(PAN_SIZE+1);i++)
    {
        ScoreList.push_back(0);
    }
    playerDo=true;//玩家先手
}
