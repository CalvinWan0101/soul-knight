#include "stdafx.h"
#include "DevilsSnare.h"

#include "../../../../manager/ObjectManager.h"
#include "../../../../pool/ProjectilePool.h"
#include "../../../../projectile/bullet/RedRectangleBullet.h"
#include "../../../../weapon/melee_weapon/Hammer.h"
#include "../../../../weapon/ranged_weapon/UfoWeapon.h"
#include "DevilsSnareSkill.h"
#include "../../../../drop/Coin.h"
#include "../../../../drop/DropType.h"
#include "../../../../pool/DropPool.h"
#include "../../../../utils/Rand.h"
#include "../../../../weapon/melee_weapon/FakeWeapon.h"

DevilsSnare::DevilsSnare(double level = 1) : Monster(level), timer(0),
                                             hpBar(500, 20, RGB(77, 0, 124), RGB(226, 55, 44), RGB(17, 0, 64),
                                                   Point(280, 30)) {
    skills[0] = new DevilsSnareSkill0(&position);
    skills[1] = new DevilsSnareSkill1(&position);
    skills[2] = new DevilsSnareSkill2(&position);
    skills[3] = new DevilsSnareSkill3(&position);
    skills[4] = new DevilsSnareSkill4(&position);
}

DevilsSnare::~DevilsSnare() {
    for (int i = 0; i < 5; i++) {
        delete skills[i];
    }
}

void DevilsSnare::Start() {
    Monster::Start();
    SetHitBoxByRatio(0.5, 0.5);
    isAngry = false;
    this->maxHp = 552 * level;
    hp = maxHp;
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 0.0001;
    SetMonsterType(MonsterType::DEVELS_SNARE);
}

void DevilsSnare::Update() {
    Monster::Update();
    if (face == Face::RIGHT) {
        if (state == State::DEAD) {
            index = 4;
        }
        else if (!isAngry) {
            index = 0;
        }
        else {
            index = 2;
        }
    }
    else {
        if (state == State::DEAD) {
            index = 5;
        }
        else if (!isAngry) {
            index = 1;
        }
        else {
            index = 3;
        }
    }

    if (hp <= maxHp / 2 && !isAngry) {
        isAngry = true;
    }

    for (int i = 0; i < 5; i++) {
        skills[i]->Update();
    }
    if (timer == 0) {
        if (isAngry) {
            skills[Rand::Instance()->Get(0, 4)]->Activate();
            skills[Rand::Instance()->Get(0, 4)]->Activate();
            skills[Rand::Instance()->Get(0, 4)]->Activate();
        }
        else {
            skills[Rand::Instance()->Get(0, 3)]->Activate();
            skills[Rand::Instance()->Get(0, 3)]->Activate();
        }
        timer = 100;
    }
    timer--;
}

void DevilsSnare::Show(Point screenPositoin) {
    Monster::Show(screenPositoin);
    hpBar.Show(hp, maxHp);
}

void DevilsSnare::OnDead() {
    GameObject* drop;
    for (int i = 0; i < Rand::Instance()->Get(10, 30); i++) {
        drop = DropPool::Instance()->Acquire(DropType::COIN);
        drop->SetPosition(
            this->position + Point(Rand::Instance()->Get(-30, 30), Rand::Instance()->Get(-30, 30)));
        ObjectManager::Instance()->AddObject(drop);
    }
    for (int i = 0; i < Rand::Instance()->Get(10, 30); i++) {
        drop = DropPool::Instance()->Acquire(DropType::MAGIC_BALL);
        drop->SetPosition(
            this->position + Point(Rand::Instance()->Get(-30, 30), Rand::Instance()->Get(-30, 30)));
        ObjectManager::Instance()->AddObject(drop);
    }
}

void DevilsSnare::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_1/1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_1/flip_1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_2/animation_1/1.bmp",
                           "resources/monster/floor_1/devils_snare/section_2/animation_1/2.bmp",
                           "resources/monster/floor_1/devils_snare/section_2/animation_1/3.bmp",
                           "resources/monster/floor_1/devils_snare/section_2/animation_1/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_2/animation_1/flip_1.bmp",
                           "resources/monster/floor_1/devils_snare/section_2/animation_1/flip_2.bmp",
                           "resources/monster/floor_1/devils_snare/section_2/animation_1/flip_3.bmp",
                           "resources/monster/floor_1/devils_snare/section_2/animation_1/flip_4.bmp"
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
    this->SetWeapon(new FakeWeapon());
}
