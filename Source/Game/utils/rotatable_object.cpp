#include "stdafx.h"
#include "rotatable_object.h"
// #include "../mygame.h"

#include <string>
#include <vector>

#define PI 3.14159265359

RotatableObject::RotatableObject()
{
    rotation = Vec(1, 0);
}

void RotatableObject::SetRotation(Vec* radian)
{
    rotation = Vec(radian);
}

Vec RotatableObject::GetRotation() const
{
    return rotation;
}

void RotatableObject::SetImages(std::vector<std::string> filepaths, COLORREF color)
{
    game_framework::CMovingBitmap cMovingBitmap = game_framework::CMovingBitmap();
    cMovingBitmap.LoadBitmapByString(filepaths, color);
    cMovingBitmaps.push_back(cMovingBitmap);
}

void RotatableObject::SetFrameIndexOfBitmap(double radian)
{
    cMovingBitmaps[0].SetFrameIndexOfBitmap((int)(radian / PI * 60));
}
