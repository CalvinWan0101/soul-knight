#include "stdafx.h"
#include "Alchemist.h"

#include "PoisonBottle.h"
#include "../../../manager/ObjectManager.h"
#include "../../../weapon/ranged_weapon/BlueMachineGun.h"
#include "../../../weapon/ranged_weapon/BadPistol.h"
#include "../../../weapon/ranged_weapon/BatteryHead.h"
#include "../../../weapon/ranged_weapon/GasBlaster.h"

Alchemist::Alchemist() {
    skillFrameCD = 200;
}

void Alchemist::Start() {
    Player::Start();
    weaponOffsetX = 7;
    weaponOffsetY = 7;
    ChangeWeapon(new GasBlaster(200));
    maxHp = 6;
    hp = maxHp;
    maxMp = 200;
    mp = maxMp;
    maxShild = 6;
    shield = maxShild;
}

void Alchemist::Update() {
    Player::Update();
}

void Alchemist::Skill() {
    PoisonBottle* poisonBottle;
    Vec direction = this->vision;
    direction.Rotate(-0.5);
    for (int i = 0; i < 3; i++) {
        poisonBottle = new PoisonBottle();
        poisonBottle->SetPosition(this->position);
        poisonBottle->SetSpeed(direction, 6);
        ObjectManager::Instance()->AddObject(poisonBottle);
        direction.Rotate(0.5);
    }
}

void Alchemist::LoadResources() {
    this->AddAnimation({
                           "resources/player/alchemist/idle/1.bmp",
                           "resources/player/alchemist/idle/2.bmp",
                           "resources/player/alchemist/idle/3.bmp",
                           "resources/player/alchemist/idle/4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/alchemist/idle/flip_1.bmp",
                           "resources/player/alchemist/idle/flip_2.bmp",
                           "resources/player/alchemist/idle/flip_3.bmp",
                           "resources/player/alchemist/idle/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/alchemist/run/1.bmp",
                           "resources/player/alchemist/run/2.bmp",
                           "resources/player/alchemist/run/3.bmp",
                           "resources/player/alchemist/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/alchemist/run/flip_1.bmp",
                           "resources/player/alchemist/run/flip_2.bmp",
                           "resources/player/alchemist/run/flip_3.bmp",
                           "resources/player/alchemist/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/alchemist/dead.bmp",
                       }, RGB(255, 255, 255), 100, true);

    this->AddAnimation({
                           "resources/player/alchemist/flip_dead.bmp",
                       }, RGB(255, 255, 255), 100, true);
}
