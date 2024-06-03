#include "stdafx.h"
#include "UFO.h"

#include "../../../../weapon/ranged_weapon/UfoWeapon.h"

UFO::UFO(double level = 1) : Monster(level) {
}

void UFO::Start() {
    Monster::Start();
    this->maxHp = 24 * level;
    hp = maxHp;
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 3;
    SetMonsterType(MonsterType::UFO);
}

void UFO::Update() {
    Monster::Update();
}

void UFO::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_3/ufo/live.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/ufo/flip_live.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/ufo/live.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/ufo/flip_live.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/ufo/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/ufo/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void UFO::AutoMation() {
    Attack();
}

void UFO::InitializeWeapon() {
    this->SetWeapon(new UfoWeapon(3));
}
