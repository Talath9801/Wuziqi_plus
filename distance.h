#ifndef DISTANCE_H
#define DISTANCE_H

#include <QPoint>
#include "math.h"

inline bool inRange(QPoint p1,QPoint p2,int dis)
{
    int t=sqrt((p1.x()-p2.x())*(p1.x()-p2.x())+(p1.y()-p2.y())*(p1.y()-p2.y()));
    if(t<=dis)
        return true;
    else
        return false;
}

#endif // DISTANCE_H
