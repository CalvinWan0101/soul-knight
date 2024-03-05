#include "stdafx.h"
#include "game_object.h"

GameObject::GameObject(Point point, Vec speed, std::vector<game_framework::CMovingBitmap> cMovingBitmaps) :
    point(point), speed(speed), cMovingBitmaps(cMovingBitmaps)
{
    index = 0;
}

// GameObject::GameObject(Point point, Vec speed)
// {
//     this(point, speed, std::vector<game_framework::CMovingBitmap>());
// }

// GameObject::GameObject(Point point)
// {
//     this(point, Vec(0.0, 0.0), std::vector<game_framework::CMovingBitmap>());
// }

GameObject::~GameObject()
{
}

void GameObject::Show(Point screenPositoin)
{
    Point cMovingBitmapsShowPosition = this->point - screenPositoin;
    cMovingBitmaps[index].SetTopLeft((int)cMovingBitmapsShowPosition.GetX(), (int)cMovingBitmapsShowPosition.GetY());
    cMovingBitmaps[index].ShowBitmap();
}

void GameObject::LoadBitmapByString(vector<string> filepaths, COLORREF color)
{
    cMovingBitmaps[cMovingBitmaps.size()].LoadBitmapByString(filepaths, color);
}

Point GameObject::GetPoint()
{
    return point;
}

Vec GameObject::GetSpeed()
{
    return speed;
}
