#include "stdafx.h"
#include "SkeletonShaman.h"

#include "../../../../weapon/ranged_weapon/SkeletonStaff.h"

SkeletonShaman::SkeletonShaman(double level) : Monster(level) {
}

void SkeletonShaman::Start() {
    Monster::Start();
    this->maxHp = 20 * level;
    hp = maxHp;
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 3;
    SetMonsterType(MonsterType::SKELETON_SHAMAN);
}

void SkeletonShaman::Update() {
    Monster::Update();
}

void SkeletonShaman::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_2/skeleton_shaman/idle/1.bmp",
                           "resources/monster/floor_2/skeleton_shaman/idle/2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/skeleton_shaman/idle/flip_1.bmp",
                           "resources/monster/floor_2/skeleton_shaman/idle/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/skeleton_shaman/run/1.bmp",
                           "resources/monster/floor_2/skeleton_shaman/run/2.bmp",
                           "resources/monster/floor_2/skeleton_shaman/run/3.bmp",
                           "resources/monster/floor_2/skeleton_shaman/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/skeleton_shaman/run/flip_1.bmp",
                           "resources/monster/floor_2/skeleton_shaman/run/flip_2.bmp",
                           "resources/monster/floor_2/skeleton_shaman/run/flip_3.bmp",
                           "resources/monster/floor_2/skeleton_shaman/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/skeleton_shaman/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/skeleton_shaman/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void SkeletonShaman::AutoMation() {
    Attack();
}

void SkeletonShaman::InitializeWeapon() {
    this->SetWeapon(new SkeletonStaff(3));
}
