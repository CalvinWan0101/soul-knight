#pragma once
#include "point.h"

class HitBox {
public:
    HitBox(Point& authorPoint);
    void SetWidth(double width);
    void SetHeight(double height);
    double GetHalfHeight();
    double GetHalfWidth();
    bool IsCollision(HitBox* otherHitBox);
    void Show(Point screenPositoin); // TODO: Test function for HitBox location

private:
    Point& authorPoint;
    double halfWidth;
    double halfHeight;
    bool isCollisionInThisFrame; // TODO: Test code for HitBox collision visualization
};
