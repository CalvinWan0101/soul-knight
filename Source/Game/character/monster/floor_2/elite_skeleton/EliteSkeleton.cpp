#include "stdafx.h"
#include "EliteSkeleton.h"

EliteSkeleton::EliteSkeleton(double level = 1) : Monster(level) {
}

void EliteSkeleton::Start() {
    Monster::Start();
    this->speed.SetVec(0.0, 0.0);
    this->maxHp = 20 * level;
    hp = maxHp;
    this->maxSpeed = 3;
}

void EliteSkeleton::Update() {
    Monster::Update();
}

void EliteSkeleton::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_2/elite_skeleton/idle/1.bmp",
                           "resources/monster/floor_2/elite_skeleton/idle/2.bmp",
                           "resources/monster/floor_2/elite_skeleton/idle/3.bmp",
                           "resources/monster/floor_2/elite_skeleton/idle/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/elite_skeleton/idle/flip_1.bmp",
                           "resources/monster/floor_2/elite_skeleton/idle/flip_2.bmp",
                           "resources/monster/floor_2/elite_skeleton/idle/flip_3.bmp",
                           "resources/monster/floor_2/elite_skeleton/idle/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/elite_skeleton/run/1.bmp",
                           "resources/monster/floor_2/elite_skeleton/run/2.bmp",
                           "resources/monster/floor_2/elite_skeleton/run/3.bmp",
                           "resources/monster/floor_2/elite_skeleton/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/elite_skeleton/run/flip_1.bmp",
                           "resources/monster/floor_2/elite_skeleton/run/flip_2.bmp",
                           "resources/monster/floor_2/elite_skeleton/run/flip_3.bmp",
                           "resources/monster/floor_2/elite_skeleton/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/elite_skeleton/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/elite_skeleton/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void EliteSkeleton::AutoMation() {
    Attack();
}
