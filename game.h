#ifndef GAME_H
#define GAME_H

#include <vector>
#include <QPoint>
using namespace std;

const int TOTAL_PAN_SIZE=15;//15*15的棋盘
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
    vector<int> checkList;//棋子的状态,0为空，1黑子，-1白子
    vector<int> scoreList;//每个格子的打分
    vector<QPoint> pointList;
    bool playerDo;//是否轮到玩家
};

#endif // GAME_H
