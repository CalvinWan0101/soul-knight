#include "stdafx.h"
#include "Spear.h"

#include "../../projectile/ShockWave.h"
#include "../../projectile/shock_wave/HammerWave.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/InvisibleShockWave.h"

class ShockWave;

Spear::Spear(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 2;
}


Weapon* Spear::Copy() {
    return new Spear(this->damage, this->position);
}

void Spear::Start() {
    MeleeWeapon::Start();
    SetAttackAnimation({}, {15, 12, 9, 6, 3, 0}, 1, 0.1);
    SetInteractiveText("goblin spear", InteractiveText::COMMON);
}

void Spear::Update() {
    MeleeWeapon::Update();
}

void Spear::LoadResources() {
    SetImages("Resources/weapon/spear/", 3, RGB(255, 255, 255));
}

void Spear::Attack() {
    InvisibleShockWave* shockWave = static_cast<InvisibleShockWave*>(ProjectilePool::Instance()->Acquire(
        ProjectileType::INVISIBLE_SHOCK_WAVE));
    shockWave->SetPosition(&(this->position + Vec(&rotation, 10)));
    shockWave->SetSpeed(rotation, 0.5);
    shockWave->SetSize(30);
    shockWave->SetDamage(damage);
    shockWave->SetAliveTime(0.3);
    UpdateTag(shockWave);
    ObjectManager::Instance()->AddObject(shockWave);
}
