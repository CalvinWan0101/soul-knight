#include "stdafx.h"
#include "GoblinGiant.h"
#include "../../../weapon/ranged_weapon/BadPistol.h"
#include "../../../weapon/melee_weapon/Hammer.h"

void GoblinGiant::Start() {
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_giant/idle/1.bmp",
                           "resources/monster/floor_1/goblin_giant/idle/2.bmp",
                           "resources/monster/floor_1/goblin_giant/idle/3.bmp",
                           "resources/monster/floor_1/goblin_giant/idle/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                       "resources/monster/floor_1/goblin_giant/idle/flip_1.bmp",
                       "resources/monster/floor_1/goblin_giant/idle/flip_2.bmp",
                       "resources/monster/floor_1/goblin_giant/idle/flip_3.bmp",
                       "resources/monster/floor_1/goblin_giant/idle/flip_4.bmp"
                   }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_giant/run/1.bmp",
                           "resources/monster/floor_1/goblin_giant/run/2.bmp",
                           "resources/monster/floor_1/goblin_giant/run/3.bmp",
                           "resources/monster/floor_1/goblin_giant/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                       "resources/monster/floor_1/goblin_giant/run/flip_1.bmp",
                       "resources/monster/floor_1/goblin_giant/run/flip_2.bmp",
                       "resources/monster/floor_1/goblin_giant/run/flip_3.bmp",
                       "resources/monster/floor_1/goblin_giant/run/flip_4.bmp"
                   }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                       "resources/monster/floor_1/goblin_giant/dead.bmp"
                   }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                   "resources/monster/floor_1/goblin_giant/flip_dead.bmp"
               }, RGB(255, 255, 255), 100, false);
    
    this->speed.SetVec(0.0, 0.0);
    this->maxHp = 30;
    this->maxSpeed = 3;
    this->hp = maxHp;
    // TODO: Replace bad pistol with the correct weapon
    this->SetWeapon(new Hammer());
    Monster::Start();
}

void GoblinGiant::Update() {
    Monster::Update();
}
