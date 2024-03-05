#pragma once
#include <vector>

#include "point.h"
#include "../../Library/gameutil.h"

class GameObject
{
public:
    // GameObject(Point point, Vec speed, std::vector<game_framework::CMovingBitmap> cMovingBitmaps);
    // GameObject(Point point, Vec speed);
    // GameObject(Point point);
    GameObject();
    virtual ~GameObject();
    virtual void Start() = 0;
    virtual void Update() = 0;
    void Show(Point screenPositoin);
    Point GetPoint();
    Vec GetSpeed();

protected:
    Point point = Point(0, 0);
    Vec speed = Vec(0.0, 0.0);
    std::vector<game_framework::CMovingBitmap> cMovingBitmaps;
    INT index = 0;

    // void LoadBitmapByString(vector<string> filepaths, COLORREF color);
};
