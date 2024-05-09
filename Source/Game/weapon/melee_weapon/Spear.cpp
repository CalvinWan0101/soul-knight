#include "stdafx.h"
#include "Spear.h"

#include "../../projectile/ShockWave.h"
#include "../../projectile/shock_wave/HammerWave.h"
#include "../../manager/ObjectManager.h"
#include "../../projectile/rotatable_shock_wave/SpearWave.h"

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
    SetAttackAnimation({}, {15, 12, 9, 6, 3, 0},1, 0.1);
    MeleeWeapon::Start();
}

void Spear::Update() {
    MeleeWeapon::Update();
}

void Spear::Attack() {
    RotatableShockWave* shockWave = new SpearWave();
    shockWave->SetPosition(&(this->position + Vec(&rotation, 10)));
    shockWave->SetSpeed(rotation, 0.5);
    shockWave->SetDamage(damage);
    shockWave->SetAliveTime(0.3);
    shockWave->AddTag(HasTag(Tag::PLAYER_WEAPON) ? Tag::PLAYER_ATTACK : Tag::MONSTER_ATTACK);
    ObjectManager::Instance()->AddObject(shockWave);
}
