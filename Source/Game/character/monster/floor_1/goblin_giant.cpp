#include "stdafx.h"
#include "goblin_giant.h"

void GoblinGiant::Start()
{
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_giant/idle/1.bmp",
                           "resources/monster/floor_1/goblin_giant/idle/2.bmp",
                           "resources/monster/floor_1/goblin_giant/idle/3.bmp",
                           "resources/monster/floor_1/goblin_giant/idle/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_giant/run/1.bmp",
                           "resources/monster/floor_1/goblin_giant/run/2.bmp",
                           "resources/monster/floor_1/goblin_giant/run/3.bmp",
                           "resources/monster/floor_1/goblin_giant/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->index = 0;
    this->speed.SetVec(0.0, 0.0);
    // TODO: Replace bad pistol with the correct weapon
    // this->AddFrontChild(static_cast<Weapon*>(new BadPistol()));
}
void GoblinGiant::Update()
{
    
}