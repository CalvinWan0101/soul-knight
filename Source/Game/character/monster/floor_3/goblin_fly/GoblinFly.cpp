#include "stdafx.h"
#include "GoblinFly.h"

#include "../../../../weapon/ranged_weapon/GoblinFlyWeapon.h"

GoblinFly::GoblinFly(double level = 1) : Monster(level) {
}

void GoblinFly::Start() {
    Monster::Start();
    this->maxHp = 20 * level;
    hp = maxHp;
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 3;
    SetMonsterType(MonsterType::GOBLIN_FLY);
}

void GoblinFly::Update() {
    Monster::Update();
}

void GoblinFly::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_3/goblin_fly/run/1.bmp",
                           "resources/monster/floor_3/goblin_fly/run/2.bmp",
                           "resources/monster/floor_3/goblin_fly/run/3.bmp",
                           "resources/monster/floor_3/goblin_fly/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/goblin_fly/run/flip_1.bmp",
                           "resources/monster/floor_3/goblin_fly/run/flip_2.bmp",
                           "resources/monster/floor_3/goblin_fly/run/flip_3.bmp",
                           "resources/monster/floor_3/goblin_fly/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/goblin_fly/run/1.bmp",
                           "resources/monster/floor_3/goblin_fly/run/2.bmp",
                           "resources/monster/floor_3/goblin_fly/run/3.bmp",
                           "resources/monster/floor_3/goblin_fly/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/goblin_fly/run/flip_1.bmp",
                           "resources/monster/floor_3/goblin_fly/run/flip_2.bmp",
                           "resources/monster/floor_3/goblin_fly/run/flip_3.bmp",
                           "resources/monster/floor_3/goblin_fly/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/goblin_fly/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/goblin_fly/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void GoblinFly::AutoMation() {
    Attack();
}

void GoblinFly::InitializeWeapon() {
    this->SetWeapon(new GoblinFlyWeapon(3));
}
