#include "stdafx.h"
#include "monster.h"
#include <iostream>

// Monster::Monster(Point point, Vec speed, std::vector<game_framework::CMovingBitmap> cMovingBitmaps) :
//     GameObject(point, speed, cMovingBitmaps)
// {
// }

Monster::Monster()
{
    
}


void Monster::Start() 
{
    this->cMovingBitmaps.push_back(game_framework::CMovingBitmap());
    this->cMovingBitmaps[0].LoadBitmapByString({"resources/ball/ball-1.bmp" , "resources/ball/ball-2.bmp" , "resources/ball/ball-3.bmp"});
    this->cMovingBitmaps[0].SetAnimation(250 , false);
}

void Monster::Update() 
{
    std::cout<<"moster:(" << this->point.GetX()  << "," << this->point.GetY() << ")" << "\n";
    std::cout<<"screen:(" << this->cMovingBitmaps[0].GetTop() << "," << this->cMovingBitmaps[0].GetLeft() << ")" << "\n";
}
