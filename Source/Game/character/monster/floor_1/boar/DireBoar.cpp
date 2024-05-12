#include "stdafx.h"
#include "DireBoar.h"

DireBoar::DireBoar(double level) : Boar(level) {
}

void DireBoar::Start() {
    Boar::Start();
    this->maxHp = 10 * level;
    SetDamage(3);
    SetMonsterType(MonsterType::DIRE_BOAR);
}

void DireBoar::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_1/dire_boar/idle/1.bmp",
                           "resources/monster/floor_1/dire_boar/idle/2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/dire_boar/idle/flip_1.bmp",
                           "resources/monster/floor_1/dire_boar/idle/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/dire_boar/run/1.bmp",
                           "resources/monster/floor_1/dire_boar/run/2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/dire_boar/run/flip_1.bmp",
                           "resources/monster/floor_1/dire_boar/run/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/dire_boar/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/dire_boar/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}
