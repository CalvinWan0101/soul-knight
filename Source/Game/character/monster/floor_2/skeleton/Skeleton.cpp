#include "stdafx.h"
#include "Skeleton.h"

Skeleton::Skeleton(double level = 1, bool isMeleeAttackMonster) : Monster(level, isMeleeAttackMonster) {
}

void Skeleton::Start() {
    Monster::Start();
    this->speed.SetVec(0.0, 0.0);
    this->maxHp = 10 * level;
    hp = maxHp;
    this->maxSpeed = 3;
}

void Skeleton::Update() {
    Monster::Update();
}

void Skeleton::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_2/skeleton/idle/1.bmp",
                           "resources/monster/floor_2/skeleton/idle/2.bmp",
                           "resources/monster/floor_2/skeleton/idle/3.bmp",
                           "resources/monster/floor_2/skeleton/idle/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/skeleton/idle/flip_1.bmp",
                           "resources/monster/floor_2/skeleton/idle/flip_2.bmp",
                           "resources/monster/floor_2/skeleton/idle/flip_3.bmp",
                           "resources/monster/floor_2/skeleton/idle/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/skeleton/run/1.bmp",
                           "resources/monster/floor_2/skeleton/run/2.bmp",
                           "resources/monster/floor_2/skeleton/run/3.bmp",
                           "resources/monster/floor_2/skeleton/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/skeleton/run/flip_1.bmp",
                           "resources/monster/floor_2/skeleton/run/flip_2.bmp",
                           "resources/monster/floor_2/skeleton/run/flip_3.bmp",
                           "resources/monster/floor_2/skeleton/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/skeleton/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/skeleton/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void Skeleton::AutoMation() {
    Attack();
}
