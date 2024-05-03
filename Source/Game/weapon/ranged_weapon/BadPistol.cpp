#include "stdafx.h"
#include "BadPistol.h"

#include "../../projectile/bullet/arrow.h"
#include "../../manager/object_manager.h"

BadPistol::BadPistol() {
}

BadPistol::BadPistol(Point point) : RangedWeapon(point) {
}

Weapon* BadPistol::Copy() {
    return new BadPistol(this->position);
}

void BadPistol::Start() {
    // SetCd(0.5);
    damage = 3;
    SetImages("Resources/weapon/bad_pistol/", 3, RGB(255, 255, 255));
    SetAttackAnimation({-0.8, -0.4, 0}, 0.5);
    RangedWeapon::Start();
}

void BadPistol::Update() {
    RangedWeapon::Update();
}

void BadPistol::Attack() {
    Bullet* bullet = new Arrow();
    bullet->SetSpeed(rotation, 1);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    bullet->AddTag(HasTag(Tag::PLAYER_WEAPON) ? Tag::PLAYER_ATTACK : Tag::MONSTER_ATTACK);
    ObjectManager::Instance()->AddObject(bullet);
}
