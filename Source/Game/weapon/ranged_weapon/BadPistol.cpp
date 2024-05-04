#include "stdafx.h"
#include "BadPistol.h"

#include "../../projectile/bullet/BadPistolBullet.h"
#include "../../manager/ObjectManager.h"

BadPistol::BadPistol() {
}

BadPistol::BadPistol(Point point) : RangedWeapon(point) {
}

Weapon* BadPistol::Copy() {
    return new BadPistol(this->position);
}

void BadPistol::Start() {
    damage = 3;
    SetImages("Resources/weapon/bad_pistol/", 3, RGB(255, 255, 255));
    SetAttackAnimation({-0.8, -0.4, 0}, 0.1);
    RangedWeapon::Start();
}

void BadPistol::Update() {
    RangedWeapon::Update();
}

void BadPistol::Attack() {
    Bullet* bullet = new BadPistolBullet();
    bullet->SetSpeed(rotation, 20);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    bullet->AddTag(HasTag(Tag::PLAYER_WEAPON) ? Tag::PLAYER_ATTACK : Tag::MONSTER_ATTACK);
    ObjectManager::Instance()->AddObject(bullet);
}
