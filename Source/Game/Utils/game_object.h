#pragma once
#include <vector>

#include "point.h"
#include "../../Library/gameutil.h"

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Show(Point screenPositoin);
    Point GetPoint();
    Vec GetSpeed();

protected:
    Point point;
    Vec speed;
    std::vector<game_framework::CMovingBitmap> cMovingBitmaps;
    int index;
};
