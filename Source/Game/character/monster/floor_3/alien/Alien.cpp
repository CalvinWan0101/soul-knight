#include "stdafx.h"
#include "Alien.h"

Alien::Alien(double level = 1) : Monster(level) {
}

void Alien::Start() {
    Monster::Start();
    this->speed.SetVec(0.0, 0.0);
    this->maxHp = 25 * level;
    hp = maxHp;
    this->maxSpeed = 3;
}

void Alien::Update() {
    Monster::Update();
}

void Alien::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_3/alien/idle/1.bmp",
                           "resources/monster/floor_3/alien/idle/2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/alien/idle/flip_1.bmp",
                           "resources/monster/floor_3/alien/idle/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/alien/run/1.bmp",
                           "resources/monster/floor_3/alien/run/2.bmp",
                           "resources/monster/floor_3/alien/run/3.bmp",
                           "resources/monster/floor_3/alien/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/alien/run/flip_1.bmp",
                           "resources/monster/floor_3/alien/run/flip_2.bmp",
                           "resources/monster/floor_3/alien/run/flip_3.bmp",
                           "resources/monster/floor_3/alien/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/alien/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/alien/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void Alien::AutoMation() {
    Attack();
}
