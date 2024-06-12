#include "stdafx.h"
#include "GoblinGiant.h"
#include "../../../../weapon/melee_weapon/Hammer.h"

GoblinGiant::GoblinGiant(double level = 1) : Monster(level, true) {
}

void GoblinGiant::Start() {
    Monster::Start();
    this->maxHp = 40 * level;
    hp = maxHp;
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 3;
    SetMonsterType(MonsterType::GOBLIN_GIANT);
}

void GoblinGiant::Update() {
    Monster::Update();
}

void GoblinGiant::LoadResources() {
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
}

void GoblinGiant::AutoMation() {
    Attack();
}

void GoblinGiant::InitializeWeapon() {
    this->SetWeapon(new Hammer(5));
}

