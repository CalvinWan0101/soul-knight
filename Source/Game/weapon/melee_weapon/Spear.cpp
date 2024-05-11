#include "stdafx.h"
#include "Spear.h"

#include "../../projectile/ShockWave.h"
#include "../../projectile/shock_wave/HammerWave.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/InvisibleShockWave.h"

class ShockWave;

Spear::Spear(Point point) : MeleeWeapon(point) {
}

Spear::Spear(double damage) : MeleeWeapon(damage) {
}

Weapon* Spear::Copy() {
    return new Spear(this->position);
}

void Spear::Start() {
    SetImages("Resources/weapon/spear/", 3, RGB(255, 255, 255));
    SetAttackAnimation({}, {15, 12, 9, 6, 3, 0}, 1, 0.1);
    MeleeWeapon::Start();
}

void Spear::Update() {
    MeleeWeapon::Update();
}

void Spear::Attack() {
    InvisibleShockWave* shockWave = ProjectilePool::Instance()->AcquireInvisibleShockWave();
    shockWave->SetPosition(&(this->position + Vec(&rotation, 10)));
    shockWave->SetSpeed(rotation, 0.5);
    shockWave->SetSize(30);
    shockWave->SetDamage(damage);
    shockWave->SetAliveTime(0.3);
    UpdateTag(shockWave);
    ObjectManager::Instance()->AddObject(shockWave);
}
