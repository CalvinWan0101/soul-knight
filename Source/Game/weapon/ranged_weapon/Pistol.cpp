#include "stdafx.h"
#include "Pistol.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
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
    RangedWeapon::Start();
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 0.5);
}

void Pistol::Update() {
    RangedWeapon::Update();
}

void Pistol::LoadResources() {
    SetImages("Resources/weapon/pistol/", 3, RGB(255, 255, 255));
}

void Pistol::Attack() {
    Bullet* bullet = static_cast<Bullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::BAD_PISTOL_BULLET));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
