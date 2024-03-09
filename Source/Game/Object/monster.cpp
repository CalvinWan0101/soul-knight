#include "stdafx.h"
#include "monster.h"
#include <iostream>

#include "weapon.h"


Monster::Monster()
{
}


void Monster::Start()
{
    this->AddAnimation({
                        "resources/monster/floor_1/goblin_giant/idle/1.bmp",
                        "resources/monster/floor_1/goblin_giant/idle/2.bmp",
                        "resources/monster/floor_1/goblin_giant/idle/3.bmp",
                        "resources/monster/floor_1/goblin_giant/idle/4.bmp"
                        }, RGB(255, 255, 255), 250, false);
    this->AddAnimation({
                        "resources/monster/floor_1/goblin_giant/run/1.bmp",
                        "resources/monster/floor_1/goblin_giant/run/2.bmp",
                        "resources/monster/floor_1/goblin_giant/run/3.bmp",
                        "resources/monster/floor_1/goblin_giant/run/4.bmp"
                    }, RGB(255, 255, 255), 250, false);
    this->index = 0;
    this->speed.SetVec(1 , 1);
    this->AddFontChild((GameObject*)(new Weapon()));
}

void Monster::Update()
{
    run.Notify(this);
}
