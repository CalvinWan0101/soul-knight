#pragma once
#include "point.h"

class HitBox
{
public:
    HitBox(Point& authorPoint);
    void SetWidth(int width);
    void SetHeight(int height);
    bool IsCollision(HitBox* otherHitBox);

private:
    Point& authorPoint;
    int halfWidth;
    int halfHeight;
};
