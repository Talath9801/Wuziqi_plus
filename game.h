#ifndef GAME_H
#define GAME_H

#include <vector>
using namespace std;

const int PAN_SIZE=15;//15*15的棋盘
const int MARGIN=30;//棋盘边缘空格
const int CHESS_SIZE=15;//棋子半径
const int MARK_SIZE=6;//落子之前的标记大小
const int CELL_SIZE=40;//格子大小
const int CLICK_RANGE=15;//判断鼠标点击的范围



enum GameCondition
{
    playing,
    win,
    fail
};

class Game
{
public:
    Game();
    GameCondition myGameCondition;
    void startGame();
    vector<int> ChessList;//每个位置安放棋子的情况，空格为0，玩家黑子1，电脑白字-1
    vector<int> ScoreList;//每个位置额评分情况，AI落子的依据
    bool playerDo;//true玩家落子，false电脑落子
};

#endif // GAME_H
