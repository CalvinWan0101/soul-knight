#include "stdafx.h"
#include "BaseSpider.h"

#include "../../../../weapon/melee_weapon/FakeWeapon.h"

BaseSpider::BaseSpider(double level) : Monster(level) {
    SetDamage(3);
}

void BaseSpider::Start() {
    Monster::Start();
    SetHitBoxByRatio(0.8, 0.8);
    AddTag(Tag::MONSTER_ATTACK);
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 3;
    this->maxHp = 12 * level;
    hp = maxHp;
}

void BaseSpider::Update() {
    Monster::Update();
    if (this->HasTag(Tag::DEAD)) {
        RemoveTag(Tag::MONSTER_ATTACK);
    }
}

void BaseSpider::InitializeWeapon() {
    this->SetWeapon(new FakeWeapon());
}

void BaseSpider::AutoMation() {
    Attack();
}

void BaseSpider::OnDead() {
    Monster::OnDead();
}




