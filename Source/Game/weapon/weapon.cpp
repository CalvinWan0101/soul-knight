#include "stdafx.h"
#include "weapon.h"

Weapon::Weapon()
{
}


void Weapon::Start()
{
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_giant/run/1.bmp",
                           "resources/monster/floor_1/goblin_giant/run/2.bmp",
                           "resources/monster/floor_1/goblin_giant/run/3.bmp",
                           "resources/monster/floor_1/goblin_giant/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->point.SetPoint(30, 30);
}

void Weapon::Update()
{
}
