#include "stdafx.h"
#include "LongBlade40m.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

LongBlade40m::LongBlade40m(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 0;
}

Weapon* LongBlade40m::Copy() {
    return new LongBlade40m(this->damage, this->position);
}

void LongBlade40m::Start() {
    MeleeWeapon::Start();
    SetAttackAnimation({-0.3 , -0.7 , -1.4, 1.4, 0.7 , 0.3, 0}, {}, 1.5, 0.423);
    SetInteractiveText("40m-Long-Blade", InteractiveText::LEGENDARY);
    SetHitBoxByRatio(0.1, 0.1);
}

void LongBlade40m::Update() {
    MeleeWeapon::Update();
}

void LongBlade40m::LoadResources() {
    SetImages("Resources/weapon/40m_Long_Blade/", 3, RGB(255,255,255));
}

void LongBlade40m::Attack() {
    InvisibleShockWave* shockWave = static_cast<InvisibleShockWave*>(ProjectilePool::Instance()->Acquire(
    ProjectileType::INVISIBLE_SHOCK_WAVE));
    shockWave->SetPosition(&(this->position + Vec(&rotation, 80)));
    shockWave->SetSpeed(rotation, 0);
    shockWave->SetSize(190);
    shockWave->SetDamage(damage);
    shockWave->SetAliveTime(0.1);
    UpdateTag(shockWave);
    ObjectManager::Instance()->AddObject(shockWave);
}



