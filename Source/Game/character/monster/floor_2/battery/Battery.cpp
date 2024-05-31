#include "stdafx.h"
#include "Battery.h"

#include "../../../../weapon/ranged_weapon/BatteryHead.h"

Battery::Battery(double level) : Monster(level) {
}

void Battery::Start() {
    Monster::Start();
    this->maxHp = 15 * level;
    hp = maxHp;
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 3;
    SetMonsterType(MonsterType::BATTERY);
}

void Battery::Update() {
    Monster::Update();
}

void Battery::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_2/battery/battery_body.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/battery/flip_battery_body.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/battery/battery_body.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/battery/flip_battery_body.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/battery/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_2/battery/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void Battery::AutoMation() {
    Attack();
}

void Battery::InitializeWeapon() {
    this->SetWeapon(new BatteryHead(5));
}
