#include "stdafx.h"
#include "Varkolyn.h"

#include "../../../../manager/ObjectManager.h"
#include "../../../../projectile/effect/PoisonEffect.h"
#include "../../../../weapon/melee_weapon/FakeWeapon.h"

Varkolyn::Varkolyn(double level) : Monster(level, true) {
    SetDamage(5);
}

void Varkolyn::Start() {
    Monster::Start();
    SetHitBoxByRatio(0.8, 0.8);
    AddTag(Tag::MONSTER_ATTACK);
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 3;
    this->maxHp = 12 * level;
    hp = maxHp;
    SetMonsterType(MonsterType::VARKOLYN);
}

void Varkolyn::Update() {
    Monster::Update();
    if (this->HasTag(Tag::DEAD)) {
        RemoveTag(Tag::MONSTER_ATTACK);
    }
}

void Varkolyn::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_3/varkolyn/idle/1.bmp",
                           "resources/monster/floor_3/varkolyn/idle/2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/varkolyn/idle/flip_1.bmp",
                           "resources/monster/floor_3/varkolyn/idle/flip_2.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/varkolyn/run/1.bmp",
                           "resources/monster/floor_3/varkolyn/run/2.bmp",
                           "resources/monster/floor_3/varkolyn/run/3.bmp",
                           "resources/monster/floor_3/varkolyn/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/varkolyn/run/flip_1.bmp",
                           "resources/monster/floor_3/varkolyn/run/flip_2.bmp",
                           "resources/monster/floor_3/varkolyn/run/flip_3.bmp",
                           "resources/monster/floor_3/varkolyn/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/varkolyn/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_3/varkolyn/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void Varkolyn::InitializeWeapon() {
    this->SetWeapon(new FakeWeapon());
}

void Varkolyn::AutoMation() {
    Attack();
}

void Varkolyn::OnDead() {
    Monster::OnDead();
    PoisonEffect* poisonEffect = new PoisonEffect(PoisonEffect::MONSTER_PURPLE);
    poisonEffect->SetPosition(this->position);
    ObjectManager::Instance()->AddObject(poisonEffect);
}
