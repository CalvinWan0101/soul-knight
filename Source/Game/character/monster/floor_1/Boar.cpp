#include "stdafx.h"
#include "Boar.h"
#include "../../../weapon/melee_weapon/Hammer.h"

Boar::Boar(double level = 1) : Monster(level) {
}

void Boar::Start() {
    this->AddAnimation({
                           "resources/monster/floor_1/boar/idle/1.bmp",
                           "resources/monster/floor_1/boar/idle/2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/boar/idle/flip_1.bmp",
                           "resources/monster/floor_1/boar/idle/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/boar/run/1.bmp",
                           "resources/monster/floor_1/boar/run/2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/boar/run/flip_1.bmp",
                           "resources/monster/floor_1/boar/run/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/boar/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/boar/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->speed.SetVec(0.0, 0.0);
    this->maxHp = 30 * level;
    this->maxSpeed = 4;
    this->hp = maxHp;
    this->SetWeapon(new Hammer());
    Monster::Start();
}

void Boar::Update() {
    Monster::Update();
}
