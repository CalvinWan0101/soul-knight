#include "stdafx.h"
#include "Hoe.h"

#include "../../projectile/ShockWave.h"
#include "../../projectile/InvisibleShockWave.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

Hoe::Hoe(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 0;
}

Weapon* Hoe::Copy() {
    return new Hoe(this->damage, this->position);
}

void Hoe::Start() {
    MeleeWeapon::Start();
    SetAttackAnimation({-0.7, -1.4, 1.4, 0.7, 0}, {}, 0.6, 0.65);
    SetInteractiveText("hoe", InteractiveText::UNCOMMON);
}

void Hoe::Update() {
    MeleeWeapon::Update();
}

void Hoe::LoadResources() {
    SetImages("Resources/weapon/hoe/", 3, RGB(255, 255, 255));
}

void Hoe::Attack() {
    InvisibleShockWave* shockWave = static_cast<InvisibleShockWave*>(ProjectilePool::Instance()->Acquire(
        ProjectileType::INVISIBLE_SHOCK_WAVE));
    shockWave->SetPosition(&(this->position + Vec(&rotation, 10)));
    shockWave->SetSpeed(rotation, 0);
    shockWave->SetSize(30);
    shockWave->SetDamage(damage);
    shockWave->SetAliveTime(0.1);
    UpdateTag(shockWave);
    ObjectManager::Instance()->AddObject(shockWave);
}
