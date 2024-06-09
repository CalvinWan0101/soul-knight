#include "stdafx.h"
#include "ZulanTheColossus.h"

#include "../../../drop/DropType.h"
#include "../../../manager/ObjectManager.h"
#include "../../../pool/DropPool.h"
#include "../../../utils/Rand.h"
#include "../../../weapon/melee_weapon/FakeWeapon.h"
#include "../../../drop/Drop.h"

ZulanTheColossus::ZulanTheColossus() : Monster(1), isAngry(false), hpBar(500, 20, RGB(77,0,124), RGB(226,55,44), RGB(17,0,64), Point(280, 30)) {
}

void ZulanTheColossus::Start() {
    Monster::Start();
    this->maxHp = 883;
    this->maxSpeed = 1;
    this->hp = maxHp;
}

void ZulanTheColossus::Update() {
    Monster::Update();
}

void ZulanTheColossus::Show(Point screenPositoin) {
    Monster::Show(screenPositoin);
    hpBar.Show(hp, maxHp);
}

void ZulanTheColossus::OnDead() {
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

void ZulanTheColossus::LoadResources() {
    this->AddAnimation({
                           "Resources/boss/zulan_the_colossus/zulan_the_colossus/normal/1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "Resources/boss/zulan_the_colossus/zulan_the_colossus/normal/flip_1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "Resources/boss/zulan_the_colossus/zulan_the_colossus/angry/1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "Resources/boss/zulan_the_colossus/zulan_the_colossus/angry/flip_1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "Resources/boss/zulan_the_colossus/zulan_the_colossus/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "Resources/boss/zulan_the_colossus/zulan_the_colossus/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void ZulanTheColossus::AutoMation() {
    
}

void ZulanTheColossus::InitializeWeapon() {
    SetWeapon(new FakeWeapon());
}

bool ZulanTheColossus::CheckAngry() {
    return hp < maxHp / 2;
}

void ZulanTheColossus::CheckState() {
    if (hp <= 0) {
        state = DEAD;
        AddTag(Tag::DEAD);
    }
    else if (!CheckAngry()) {
        state = IDLE;
    }
    else {
        state = RUN;
    }
}





