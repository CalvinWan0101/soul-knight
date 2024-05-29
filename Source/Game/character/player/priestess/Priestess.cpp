#include "stdafx.h"
#include "Priestess.h"

#include "HealingCircle.h"
#include "../../../manager/ObjectManager.h"
#include "../../../weapon/ranged_weapon/BadPistol.h"

Priestess::Priestess() {
    skillFrameCD = 600;
}

void Priestess::Start() {
    Player::Start();
    weaponOffsetX = 7;
    weaponOffsetY = 7;
    ChangeWeapon(new BadPistol());
    maxHp = 4;
    hp = maxHp;
    maxMp = 220;
    mp = maxMp;
    maxShild = 6;
    shield = maxShild;
}

void Priestess::Update() {
    Player::Update();
}

void Priestess::Skill() {
    HealingCircle* healingCircle = new HealingCircle();
    healingCircle->SetPosition(this->position);
    ObjectManager::Instance()->AddObject(healingCircle);
}

void Priestess::LoadResources() {
    this->AddAnimation({
                       "resources/player/priestess/idle/1.bmp",
                       "resources/player/priestess/idle/2.bmp",
                       "resources/player/priestess/idle/3.bmp",
                       "resources/player/priestess/idle/4.bmp"
                   }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/priestess/idle/flip_1.bmp",
                           "resources/player/priestess/idle/flip_2.bmp",
                           "resources/player/priestess/idle/flip_3.bmp",
                           "resources/player/priestess/idle/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/priestess/run/1.bmp",
                           "resources/player/priestess/run/2.bmp",
                           "resources/player/priestess/run/3.bmp",
                           "resources/player/priestess/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/priestess/run/flip_1.bmp",
                           "resources/player/priestess/run/flip_2.bmp",
                           "resources/player/priestess/run/flip_3.bmp",
                           "resources/player/priestess/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/priestess/dead.bmp",
                       }, RGB(255, 255, 255), 100, true);

    this->AddAnimation({
                           "resources/player/priestess/flip_dead.bmp",
                       }, RGB(255, 255, 255), 100, true);
}




