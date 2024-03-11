#include "stdafx.h"
#include "monster.h"
#include "weapon.h"

#include <iostream>
#include <cmath>

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
                        }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                        "resources/monster/floor_1/goblin_giant/run/1.bmp",
                        "resources/monster/floor_1/goblin_giant/run/2.bmp",
                        "resources/monster/floor_1/goblin_giant/run/3.bmp",
                        "resources/monster/floor_1/goblin_giant/run/4.bmp"
                    }, RGB(255, 255, 255), 100, false);
    this->index = 0;
    this->speed.SetVec(1 , 1);
    this->AddFontChild((GameObject*)(new Weapon()));
}

double t = 0; // TODO delete useless code
void Monster::Update()
{
    t += 0.1;
    fontGameObjects[0]->GetPoint().SetPoint(90*cos(t) ,  90*sin(t));
    run.Notify(this);
}
