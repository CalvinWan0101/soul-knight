#include "stdafx.h"
#include "Pistol.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/BadPistolBullet.h"
#include "../../projectile/bullet/RedCircleBullet.h"

class Bullet;

Pistol::Pistol(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 2;
}


Weapon* Pistol::Copy() {
    return new Pistol(this->damage, this->position);
}

void Pistol::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 0.35);
    SetInteractiveText("P250", InteractiveText::UNCOMMON);
}

void Pistol::Update() {
    RangedWeapon::Update();
}

void Pistol::LoadResources() {
    SetImages("Resources/weapon/pistol/", 3, RGB(255, 255, 255));
}

void Pistol::Attack() {
    if (HasTag(Tag::PLAYER_WEAPON)) {
        GeneratePlayerBullet();
    }
    else {
        GenerateMonsterBullet();
    }
}


void Pistol::GeneratePlayerBullet() {
    Bullet* bullet = static_cast<Bullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::BAD_PISTOL_BULLET));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}

void Pistol::GenerateMonsterBullet() {
    Bullet* bullet = static_cast<RedCircleBullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::RED_CIRCLE_BULLET));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
