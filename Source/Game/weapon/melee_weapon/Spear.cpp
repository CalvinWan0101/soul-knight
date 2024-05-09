#include "stdafx.h"
#include "Spear.h"

#include "../../projectile/ShockWave.h"
#include "../../projectile/shock_wave/HammerWave.h"
#include "../../manager/ObjectManager.h"

class ShockWave;

Spear::Spear() {
}

Spear::Spear(Point point) : MeleeWeapon(point) {
}

Weapon* Spear::Copy() {
    return new Spear(this->position);
}

void Spear::Start() {
    damage = 10;
    SetImages("Resources/weapon/spear/", 3, RGB(255, 255, 255));
    SetAttackAnimation({}, {15, 12, 9, 6, 3, 0},0.835, 0.65);
    MeleeWeapon::Start();
}

void Spear::Update() {
    MeleeWeapon::Update();
}

void Spear::Attack() {
    // ShockWave* shockWave = new HammerWave();
    // shockWave->SetPosition(&(this->position + Vec(&rotation, 17) + Vec(0.0, -15)));
    // shockWave->SetDamage(damage);
    // shockWave->AddTag(HasTag(Tag::PLAYER_WEAPON) ? Tag::PLAYER_ATTACK : Tag::MONSTER_ATTACK);
    // ObjectManager::Instance()->AddObject(shockWave);
}
