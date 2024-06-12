#include "stdafx.h"
#include "Goblin.h"

#include "../../../../weapon/ranged_weapon/GoblinWeapon.h"

Goblin::Goblin(double level = 1) : Monster(level) {
}

void Goblin::Start() {
    Monster::Start();
    this->maxHp = 20 * level;
    hp = maxHp;
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 3;
    SetMonsterType(MonsterType::GOBLIN);
}

void Goblin::Update() {
    Monster::Update();
}

void Goblin::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_3/goblin/idle/1.bmp",
                           "resources/monster/floor_3/goblin/idle/2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/goblin/idle/flip_1.bmp",
                           "resources/monster/floor_3/goblin/idle/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/goblin/run/1.bmp",
                           "resources/monster/floor_3/goblin/run/2.bmp",
                           "resources/monster/floor_3/goblin/run/3.bmp",
                           "resources/monster/floor_3/goblin/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/goblin/run/flip_1.bmp",
                           "resources/monster/floor_3/goblin/run/flip_2.bmp",
                           "resources/monster/floor_3/goblin/run/flip_3.bmp",
                           "resources/monster/floor_3/goblin/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/goblin/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/goblin/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void Goblin::AutoMation() {
    Attack();
}

void Goblin::InitializeWeapon() {
    this->SetWeapon(new GoblinWeapon(5));
}
