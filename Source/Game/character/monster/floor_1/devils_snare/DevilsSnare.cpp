#include "stdafx.h"
#include "DevilsSnare.h"

#include "../../../../manager/ObjectManager.h"
#include "../../../../pool/ProjectilePool.h"
#include "../../../../projectile/bullet/RedRectangleBullet.h"
#include "../../../../weapon/melee_weapon/Hammer.h"
#include "../../../../weapon/ranged_weapon/UfoWeapon.h"
#include "DevilsSnareSkill.h"
#include "../../../../utils/Rand.h"

DevilsSnare::DevilsSnare(double level = 1) : Monster(level), timer(0) {
    skills[0] = new DevilsSnareSkill0(&position);
    skills[1] = new DevilsSnareSkill1(&position);
    skills[2] = new DevilsSnareSkill2(&position);
    skills[3] = new DevilsSnareSkill3(&position);
    skills[4] = new DevilsSnareSkill4(&position);
    skills[5] = new DevilsSnareSkill5(&position);
}

DevilsSnare::~DevilsSnare() {
    for (int i = 0; i < 6; i++) {
        delete skills[i];
    }
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
    if (hp <= maxHp / 2 && !isAngry) {
        isAngry = true;
    }
    
    for (int i = 0; i < 6; i++) {
        skills[i]->Update();
    }
    if (timer == 0) {
        if (isAngry) {
            skills[Rand::Instance()->Get(0, 5)]->Activate();
            skills[Rand::Instance()->Get(0, 5)]->Activate();
            skills[Rand::Instance()->Get(0, 5)]->Activate();
        }
        else {
            skills[Rand::Instance()->Get(0, 3)]->Activate();
            skills[Rand::Instance()->Get(0, 3)]->Activate();
        }
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
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void DevilsSnare::AutoMation() {
}

void DevilsSnare::InitializeWeapon() {
    this->SetWeapon(new UfoWeapon(5));
}
