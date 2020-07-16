#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "game.h"
#include "distance.h"

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
    void mouseTracking(QMouseEvent *event);
    void inGame();//进入游戏


private:
    Ui::MainWindow *ui;
    Game *mygame;
    QPoint toClick;
    bool ifClick=false;
};

#endif // MAINWINDOW_H
