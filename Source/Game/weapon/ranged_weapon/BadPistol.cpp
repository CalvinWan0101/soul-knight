#include "stdafx.h"
#include "BadPistol.h"

#include "../../projectile/bullet/BadPistolBullet.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/Arrow.h"

BadPistol::BadPistol(double damage, Point position) {
    this->damage = damage;
    this->position = position;
}

Weapon* BadPistol::Copy() {
    return new BadPistol(this->damage, this->position);
}

void BadPistol::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 0.5);
    SetInteractiveText("bad pistol", InteractiveText::COMMON);
}

void BadPistol::Update() {
    RangedWeapon::Update();
}

void BadPistol::LoadResources() {
    SetImages("Resources/weapon/bad_pistol/", 3, RGB(255, 255, 255));
}

void BadPistol::Attack() {
    Bullet* bullet = static_cast<BadPistolBullet*>((ProjectilePool::Instance()->Acquire(
        ProjectileType::BAD_PISTOL_BULLET)));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
