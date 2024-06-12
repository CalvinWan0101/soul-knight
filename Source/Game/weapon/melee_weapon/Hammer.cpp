#include "stdafx.h"
#include "Hammer.h"

#include "../../projectile/ShockWave.h"
#include "../../projectile/shock_wave/HammerWave.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

Hammer::Hammer(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 5;
}

Weapon* Hammer::Copy() {
    return new Hammer(this->damage, this->position);
}

void Hammer::Start() {
    MeleeWeapon::Start();
    SetAttackAnimation({-0.7, -1.4, 1.4, 0.7, 0}, {}, 0.835, 0.65);
    SetInteractiveText("hammer", InteractiveText::RARE);
}

void Hammer::Update() {
    MeleeWeapon::Update();
}

void Hammer::LoadResources() {
    SetImages("Resources/weapon/hammer/", 3, RGB(255, 255, 255));
}

void Hammer::Attack() {
    ShockWave* shockWave = static_cast<HammerWave*>(ProjectilePool::Instance()->Acquire(ProjectileType::HAMMER_WAVE));
    shockWave->SetPosition(&(this->position + Vec(&rotation, 17) + Vec(0.0, -15)));
    shockWave->SetDamage(damage);
    UpdateTag(shockWave);
    ObjectManager::Instance()->AddObject(shockWave);
}
