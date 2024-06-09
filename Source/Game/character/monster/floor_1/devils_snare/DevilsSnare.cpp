#include "stdafx.h"
#include "DevilsSnare.h"

#include "../../../../manager/ObjectManager.h"
#include "../../../../pool/ProjectilePool.h"
#include "../../../../projectile/bullet/RedRectangleBullet.h"
#include "../../../../weapon/melee_weapon/Hammer.h"
#include "../../../../weapon/ranged_weapon/UfoWeapon.h"
#include "DevilsSnareSkill.h"

DevilsSnare::DevilsSnare(double level = 1) : Monster(level), timer(0) {
    skill1 = new DevilsSnareSkill1(&position);
    skill2 = new DevilsSnareSkill2(&position);
}

DevilsSnare::~DevilsSnare() {
}

void DevilsSnare::Start() {
    Monster::Start();
    this->maxHp = 552 * level;
    hp = maxHp;
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 0.0001;
    SetMonsterType(MonsterType::DEVELS_SNARE);
}

void DevilsSnare::Update() {
    Monster::Update();
    skill1->Update();
    skill2->Update();
    if (timer == 0) {
        skill1->Activate();
        skill2->Activate();
        timer = 100;
    }
    timer--;
}

void DevilsSnare::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_1/1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_1/flip_1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_1/1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_1/flip_1.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void DevilsSnare::AutoMation() {
}

void DevilsSnare::InitializeWeapon() {
    this->SetWeapon(new UfoWeapon(5));
}
