#pragma once
#include "point.h"

class HitBox {
public:
    HitBox(Point& authorPoint);
    void SetWidth(double width);
    void SetHeight(double height);
    bool IsCollision(HitBox* otherHitBox);

private:
    Point& authorPoint;
    double halfWidth;
    double halfHeight;
};
