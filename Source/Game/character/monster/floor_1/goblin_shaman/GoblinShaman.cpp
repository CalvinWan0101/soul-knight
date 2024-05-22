#include "stdafx.h"
#include "GoblinShaman.h"

#include "../../../../weapon/ranged_weapon/GoblinStaff.h"

GoblinShaman::GoblinShaman(double level) : Monster(level) {
}

void GoblinShaman::Start() {
    Monster::Start();
    this->maxHp = 15 * level;
    hp = maxHp;
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 3;
    SetMonsterType(MonsterType::GOBLIN_SHAMAN);
}

void GoblinShaman::Update() {
    Monster::Update();
}

void GoblinShaman::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_shaman/idle/1.bmp",
                           "resources/monster/floor_1/goblin_shaman/idle/2.bmp",
                           "resources/monster/floor_1/goblin_shaman/idle/3.bmp",
                           "resources/monster/floor_1/goblin_shaman/idle/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_shaman/idle/flip_1.bmp",
                           "resources/monster/floor_1/goblin_shaman/idle/flip_2.bmp",
                           "resources/monster/floor_1/goblin_shaman/idle/flip_3.bmp",
                           "resources/monster/floor_1/goblin_shaman/idle/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_shaman/run/1.bmp",
                           "resources/monster/floor_1/goblin_shaman/run/2.bmp",
                           "resources/monster/floor_1/goblin_shaman/run/3.bmp",
                           "resources/monster/floor_1/goblin_shaman/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_shaman/run/flip_1.bmp",
                           "resources/monster/floor_1/goblin_shaman/run/flip_2.bmp",
                           "resources/monster/floor_1/goblin_shaman/run/flip_3.bmp",
                           "resources/monster/floor_1/goblin_shaman/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_shaman/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_shaman/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void GoblinShaman::AutoMation() {
    Attack();
}

void GoblinShaman::InitializeWeapon() {
    this->SetWeapon(new GoblinStaff(3));
}
