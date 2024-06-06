#include "stdafx.h"
#include "VarkolynGuard.h"

VarkolynGuard::VarkolynGuard(double level = 1) : Monster(level) {
}

void VarkolynGuard::Start() {
    Monster::Start();
    this->speed.SetVec(0.0, 0.0);
    this->maxHp = 28 * level;
    hp = maxHp;
    this->maxSpeed = 3;
}

void VarkolynGuard::Update() {
    Monster::Update();
}

void VarkolynGuard::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_3/varkolyn_guard/idle/1.bmp",
                           "resources/monster/floor_3/varkolyn_guard/idle/2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/varkolyn_guard/idle/flip_1.bmp",
                           "resources/monster/floor_3/varkolyn_guard/idle/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/varkolyn_guard/run/1.bmp",
                           "resources/monster/floor_3/varkolyn_guard/run/2.bmp",
                           "resources/monster/floor_3/varkolyn_guard/run/3.bmp",
                           "resources/monster/floor_3/varkolyn_guard/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/varkolyn_guard/run/flip_1.bmp",
                           "resources/monster/floor_3/varkolyn_guard/run/flip_2.bmp",
                           "resources/monster/floor_3/varkolyn_guard/run/flip_3.bmp",
                           "resources/monster/floor_3/varkolyn_guard/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/varkolyn_guard/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/varkolyn_guard/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void VarkolynGuard::AutoMation() {
    Attack();
}
