﻿#include "stdafx.h"
#include "BadPistol.h"

#include "../../projectile/bullet/BadPistolBullet.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/Arrow.h"

BadPistol::BadPistol(Point point) : RangedWeapon(point) {
}

BadPistol::BadPistol(double damage) : RangedWeapon(damage) {
}

Weapon* BadPistol::Copy() {
    return new BadPistol(this->position);
}

void BadPistol::Start() {
    SetImages("Resources/weapon/bad_pistol/", 3, RGB(255, 255, 255));
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 0.5);
    RangedWeapon::Start();
}

void BadPistol::Update() {
    RangedWeapon::Update();
}

void BadPistol::Attack() {
    Bullet* bullet = ProjectilePool::Instance()->AcquireBadPistolBullet();
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
