#ifndef DISTANCE_H
#define DISTANCE_H

#include<QPoint>
#include<math.h>

inline bool inRange(QPoint p1,QPoint p2,int distance)//检查距离
{
    int t;
    t=sqrt((p1.x()-p2.x())*(p1.x()-p2.x())+(p1.y()-p2.y())*(p1.y()-p2.y()));
    if(t<=distance)
        return true;
    else
        return false;
}

#endif // DISTANCE_H
