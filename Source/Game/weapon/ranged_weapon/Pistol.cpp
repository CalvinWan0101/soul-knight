#include "stdafx.h"
#include "Pistol.h"

#include "../../manager/ObjectManager.h"
#include "../../projectile/bullet/BadPistolBullet.h"

class Bullet;

Pistol::Pistol(Point point) : RangedWeapon(point) {
}

Pistol::Pistol(double damage) : RangedWeapon(damage) {
}

Weapon* Pistol::Copy() {
    return new Pistol(this->position);
}

void Pistol::Start() {
    SetImages("Resources/weapon/pistol/", 3, RGB(255, 255, 255));
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 0.5);
    RangedWeapon::Start();
}

void Pistol::Update() {
    RangedWeapon::Update();
}

void Pistol::Attack() {
    Bullet* bullet = new BadPistolBullet();
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    bullet->AddTag(HasTag(Tag::PLAYER_WEAPON) ? Tag::PLAYER_ATTACK : Tag::MONSTER_ATTACK);
    ObjectManager::Instance()->AddObject(bullet);
}
