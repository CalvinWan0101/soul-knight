#include "stdafx.h"
#include "Hammer.h"

#include "../../projectile/ShockWave.h"
#include "../../projectile/shock_wave/HammerWave.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

Hammer::Hammer() {
}

Hammer::Hammer(Point point) : MeleeWeapon(point) {
}

Hammer::Hammer(double damage = 5) : MeleeWeapon(damage) {
}

Weapon* Hammer::Copy() {
    return new Hammer(this->position);
}

void Hammer::Start() {
    SetImages("Resources/weapon/hammer/", 3, RGB(255, 255, 255));
    SetAttackAnimation({-0.7, -1.4, 1.4, 0.7, 0}, {}, 0.835, 0.65);
    MeleeWeapon::Start();
}

void Hammer::Update() {
    MeleeWeapon::Update();
}

void Hammer::Attack() {
    ShockWave* shockWave = ProjectilePool::Instance()->AcquireHammerWave();
    shockWave->SetPosition(&(this->position + Vec(&rotation, 17) + Vec(0.0, -15)));
    shockWave->SetDamage(damage);
    UpdateTag(shockWave);
    ObjectManager::Instance()->AddObject(shockWave);
}
