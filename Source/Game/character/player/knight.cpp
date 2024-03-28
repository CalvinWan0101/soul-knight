#include "stdafx.h"
#include "knight.h"

#include "..\..\weapon\bad_pistol.h"

Knight::Knight() {
    state = IDLE;
    maxHp = 1000;
    hp = maxHp;
}

void Knight::Start() {
    weaponOffsetX = 7;
    weaponOffsetY = 7;
    ChangeWeapon(new BadPistol());
    this->AddAnimation({
                           "resources/player/knight/idle/1.bmp",
                           "resources/player/knight/idle/2.bmp",
                           "resources/player/knight/idle/3.bmp",
                           "resources/player/knight/idle/4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/knight/idle/flip_1.bmp",
                           "resources/player/knight/idle/flip_2.bmp",
                           "resources/player/knight/idle/flip_3.bmp",
                           "resources/player/knight/idle/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    
    this->AddAnimation({
                           "resources/player/knight/run/1.bmp",
                           "resources/player/knight/run/2.bmp",
                           "resources/player/knight/run/3.bmp",
                           "resources/player/knight/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/knight/run/flip_1.bmp",
                           "resources/player/knight/run/flip_2.bmp",
                           "resources/player/knight/run/flip_3.bmp",
                           "resources/player/knight/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/knight/dead.bmp",
                       }, RGB(255, 255, 255), 100, true);

    this->AddAnimation({
                           "resources/player/knight/flip_dead.bmp",
                       }, RGB(255, 255, 255), 100, true);
}

void Knight::Update() {
    Player::Update();
}
