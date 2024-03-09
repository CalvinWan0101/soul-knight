#include "stdafx.h"
#include "monster.h"
#include <iostream>


Monster::Monster()
{
}


void Monster::Start()
{
    this->cMovingBitmaps.push_back(game_framework::CMovingBitmap());
    this->cMovingBitmaps.push_back(game_framework::CMovingBitmap());
    this->cMovingBitmaps[0].LoadBitmapByString({
                                               "resources/monster/floor_1/goblin_giant/idle/1.bmp",
                                               "resources/monster/floor_1/goblin_giant/idle/2.bmp",
                                               "resources/monster/floor_1/goblin_giant/idle/3.bmp",
                                               "resources/monster/floor_1/goblin_giant/idle/4.bmp"
                                           }, RGB(255, 255, 255));
    this->cMovingBitmaps[1].LoadBitmapByString({
                                                   "resources/monster/floor_1/goblin_giant/run/1.bmp",
                                                   "resources/monster/floor_1/goblin_giant/run/2.bmp",
                                                   "resources/monster/floor_1/goblin_giant/run/3.bmp",
                                                   "resources/monster/floor_1/goblin_giant/run/4.bmp"
                                               }, RGB(255, 255, 255));
    this->cMovingBitmaps[0].SetAnimation(250, false);
    this->cMovingBitmaps[1].SetAnimation(250, false);

}

void Monster::Update()
{
    std::cout << "moster:(" << this->point.GetX() << "," << this->point.GetY() << ")" << "\n";
    std::cout << "screen:(" << this->cMovingBitmaps[0].GetTop() << "," << this->cMovingBitmaps[0].GetLeft() << ")" <<
        "\n";
    run.Notify(this);
}
