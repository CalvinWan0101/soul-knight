#include "stdafx.h"
#include "BigSkeleton.h"

#include "../../../../weapon/ranged_weapon/SkeletonHammer.h"

BigSkeleton::BigSkeleton(double level = 1) : Monster(level) {
}

void BigSkeleton::Start() {
    Monster::Start();
    this->maxHp = 50 * level;
    hp = maxHp;
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 3;
    SetMonsterType(MonsterType::BIG_SKELETON);
}

void BigSkeleton::Update() {
    Monster::Update();
}

void BigSkeleton::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_2/big_skeleton/idle/1.bmp",
                           "resources/monster/floor_2/big_skeleton/idle/2.bmp",
                           "resources/monster/floor_2/big_skeleton/idle/3.bmp",
                           "resources/monster/floor_2/big_skeleton/idle/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/big_skeleton/idle/flip_1.bmp",
                           "resources/monster/floor_2/big_skeleton/idle/flip_2.bmp",
                           "resources/monster/floor_2/big_skeleton/idle/flip_3.bmp",
                           "resources/monster/floor_2/big_skeleton/idle/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/big_skeleton/run/1.bmp",
                           "resources/monster/floor_2/big_skeleton/run/2.bmp",
                           "resources/monster/floor_2/big_skeleton/run/3.bmp",
                           "resources/monster/floor_2/big_skeleton/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/big_skeleton/run/flip_1.bmp",
                           "resources/monster/floor_2/big_skeleton/run/flip_2.bmp",
                           "resources/monster/floor_2/big_skeleton/run/flip_3.bmp",
                           "resources/monster/floor_2/big_skeleton/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/big_skeleton/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/big_skeleton/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void BigSkeleton::AutoMation() {
    Attack();
}

void BigSkeleton::InitializeWeapon() {
    this->SetWeapon(new SkeletonHammer(3));
}
