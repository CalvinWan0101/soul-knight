#include "stdafx.h"
#include "game_object.h"

GameObject::GameObject()
{
    index = 0;
}

GameObject::~GameObject()
{
}

void GameObject::Show(Point screenPositoin)
{
    double screenX = this->point.GetX() - screenPositoin.GetX();
    double screenY = this->point.GetY() - screenPositoin.GetY();
    cMovingBitmaps[index].SetTopLeft(static_cast<int>(screenX), static_cast<int>(screenY));
    cMovingBitmaps[index].ShowBitmap();
}

Point GameObject::GetPoint()
{
    return point;
}

Vec GameObject::GetSpeed()
{
    return speed;
}
