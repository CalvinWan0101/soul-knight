#include "stdafx.h"
#include "Bow.h"
#include "../../manager/ObjectManager.h"
#include "../../projectile/bullet/Arrow.h"

class Bullet;

Bow::Bow() {
}

Bow::Bow(Point point) : RangedWeapon(point) {
}

Weapon* Bow::Copy() {
    return new Bow(this->position);
}

void Bow::Start() {
    damage = 5;
    SetImages("Resources/weapon/bow/bow/", 3, RGB(255, 255, 255));
    SetAttackAnimation({0}, {-2, 0}, 0.5);
    RangedWeapon::Start();
}

void Bow::Update() {
    RangedWeapon::Update();
}

void Bow::Attack() {
    Bullet* bullet = new Arrow();
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    bullet->AddTag(HasTag(Tag::PLAYER_WEAPON) ? Tag::PLAYER_ATTACK : Tag::MONSTER_ATTACK);
    ObjectManager::Instance()->AddObject(bullet);
}
