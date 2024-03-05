#include "stdafx.h"
#include "monster.h"

Monster::Monster(Point point, Vec speed, std::vector<game_framework::CMovingBitmap> cMovingBitmaps) :
    GameObject(point, speed, cMovingBitmaps)
{
}

void Monster::Start() 
{
    LoadBitmapByString({ "resources/ball/ball_1.bmp", "resources/ball/ball_2.bmp", "resources/ball/ball_3.bmp" }, RGB(255, 255, 255));
    LoadBitmapByString({ "resources/door/door_close.bmp", "resources/door/door_open.bmp"}, RGB(255, 255, 255));
}

void Monster::Update() 
{
}
