#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "game.h"
#include "distance.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void inGame();//进入游戏
    void manDo();//人下棋一步
public slots:
    void  AIdo();


private:
    Ui::MainWindow *ui;
    Game *mygame;
    QPoint toClick;
    int numToClick=-1;
    int toClickX;
    int toClickY;
    bool ifClick=false;
};

#endif // MAINWINDOW_H
