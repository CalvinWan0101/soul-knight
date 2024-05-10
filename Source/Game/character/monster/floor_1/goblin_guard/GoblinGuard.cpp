#include "stdafx.h"
#include "GoblinGuard.h"

GoblinGuard::GoblinGuard(double level = 1) : Monster(level) {
}

void GoblinGuard::Start() {
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_guard/idle/1.bmp",
                           "resources/monster/floor_1/goblin_guard/idle/2.bmp",
                           "resources/monster/floor_1/goblin_guard/idle/3.bmp",
                           "resources/monster/floor_1/goblin_guard/idle/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_guard/idle/flip_1.bmp",
                           "resources/monster/floor_1/goblin_guard/idle/flip_2.bmp",
                           "resources/monster/floor_1/goblin_guard/idle/flip_3.bmp",
                           "resources/monster/floor_1/goblin_guard/idle/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_guard/run/1.bmp",
                           "resources/monster/floor_1/goblin_guard/run/2.bmp",
                           "resources/monster/floor_1/goblin_guard/run/3.bmp",
                           "resources/monster/floor_1/goblin_guard/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_guard/run/flip_1.bmp",
                           "resources/monster/floor_1/goblin_guard/run/flip_2.bmp",
                           "resources/monster/floor_1/goblin_guard/run/flip_3.bmp",
                           "resources/monster/floor_1/goblin_guard/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_guard/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_guard/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->speed.SetVec(0.0, 0.0);
    this->maxHp = 30 * level;
    this->maxSpeed = 3;
    this->hp = maxHp;
    Monster::Start();
}

void GoblinGuard::Update() {
    Monster::Update();
}
