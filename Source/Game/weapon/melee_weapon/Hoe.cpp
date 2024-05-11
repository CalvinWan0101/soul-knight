#include "stdafx.h"
#include "Hoe.h"

#include "stdafx.h"
#include "Hammer.h"

#include "../../projectile/ShockWave.h"
#include "../../projectile/shock_wave/HammerWave.h"
#include "../../manager/ObjectManager.h"

Hoe::Hoe() {
}

Hoe::Hoe(Point point) : MeleeWeapon(point) {
}

Hoe::Hoe(double damage = 5) : MeleeWeapon(damage) {
}

Weapon* Hoe::Copy() {
    return new Hammer(this->position);
}

void Hoe::Start() {
    SetImages("Resources/weapon/hoe/", 3, RGB(255, 255, 255));
    SetAttackAnimation({-0.7, -1.4, 1.4, 0.7, 0}, {}, 10, 0);
    MeleeWeapon::Start();
}

void Hoe::Update() {
    MeleeWeapon::Update();
}

void Hoe::Attack() {
    ShockWave* shockWave = new HammerWave();
    shockWave->SetPosition(&(this->position + Vec(&rotation, 17) + Vec(0.0, -15)));
    shockWave->SetDamage(damage);
    shockWave->AddTag(HasTag(Tag::PLAYER_WEAPON) ? Tag::PLAYER_ATTACK : Tag::MONSTER_ATTACK);
    ObjectManager::Instance()->AddObject(shockWave);
}
