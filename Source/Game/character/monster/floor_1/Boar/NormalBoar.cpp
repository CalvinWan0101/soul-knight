#include "stdafx.h"
#include "NormalBoar.h"

NormalBoar::NormalBoar(double level) : Boar(level) {
}

void NormalBoar::Start() {
    this->AddAnimation({
                       "resources/monster/floor_1/boar/idle/1.bmp",
                       "resources/monster/floor_1/boar/idle/2.bmp"
                   }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/boar/idle/flip_1.bmp",
                           "resources/monster/floor_1/boar/idle/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/boar/run/1.bmp",
                           "resources/monster/floor_1/boar/run/2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/boar/run/flip_1.bmp",
                           "resources/monster/floor_1/boar/run/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/boar/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/boar/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->maxHp = 8 * level;
    SetDamage(2);
    Boar::Start();
}


