#include "stdafx.h"
#include "P250.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/BadPistolBullet.h"
#include "../../projectile/bullet/RedCircleBullet.h"

class Bullet;

P250::P250(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 2;
}


Weapon* P250::Copy() {
    return new P250(this->damage, this->position);
}

void P250::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 0.35);
    SetInteractiveText("P250", InteractiveText::UNCOMMON);
}

void P250::Update() {
    RangedWeapon::Update();
}

void P250::LoadResources() {
    SetImages("Resources/weapon/pistol/", 3, RGB(255, 255, 255));
}

void P250::Attack() {
    if (HasTag(Tag::PLAYER_WEAPON)) {
        GeneratePlayerBullet();
    }
    else {
        GenerateMonsterBullet();
    }
}


void P250::GeneratePlayerBullet() {
    Bullet* bullet = static_cast<Bullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::BAD_PISTOL_BULLET));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}

void P250::GenerateMonsterBullet() {
    Bullet* bullet = static_cast<RedCircleBullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::RED_CIRCLE_BULLET));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
