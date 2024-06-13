#include "stdafx.h"
#include "Knight.h"

#include "../../../weapon/ranged_weapon/Dart.h"
#include "../../../weapon/ranged_weapon/GasBlaster.h"
#include "../../../weapon/ranged_weapon/Pistol.h"

Knight::Knight() : skillKeepMaxFrame(250) {
    skillKeepCounter = 0;
    skillEffect = new KinghtSkillEffect(&position);
    AddBackChild(skillEffect);
    skillFrameCD = 650;
}

void Knight::Start() {
    Player::Start();
    weaponOffsetX = 7;
    weaponOffsetY = 7;
    ChangeWeapon(new Dart());
    maxHp = 7;
    hp = maxHp;
    maxMp = 200;
    mp = maxMp;
    maxShild = 6;
    shield = maxShild;
}

void Knight::Update() {
    Player::Update();
    if (skillKeepCounter > 0) {
        skillKeepCounter--;
        skillEffect->SetVisible(true);
        if (weapon2) {
            weapon2->Aim(&vision);
            if (face == RIGHT) {
                weapon2->SetPosition(&(this->position + Vec(weaponOffsetX, weaponOffsetY)));
            }
            else if (face == LEFT) {
                weapon2->SetPosition(&(this->position + Vec(-weaponOffsetX, weaponOffsetY)));
            }
        }
    }
    else {
        skillEffect->SetVisible(false);
    }
}

void Knight::Attack() {
    Player::Attack();
    if (skillKeepCounter > 0) {
        if (weapon2) {
            if (weapon2->CanAttack()) {
                int mpCost = weapon2->GetMpCost();
                if (mp >= mpCost) {
                    mp -= mpCost;
                    weapon2->DefaultAttack();
                }
            }
        }
    }
}


void Knight::Skill() {
    skillKeepCounter = skillKeepMaxFrame;
}

void Knight::LoadResources() {
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
