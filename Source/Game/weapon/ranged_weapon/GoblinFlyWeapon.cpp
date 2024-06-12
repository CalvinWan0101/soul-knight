#include "stdafx.h"
#include "GoblinFlyWeapon.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/RedCircleBullet.h"

GoblinFlyWeapon::GoblinFlyWeapon(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 18;
}

Weapon* GoblinFlyWeapon::Copy() {
    return new GoblinFlyWeapon(this->damage, this->position);
}

void GoblinFlyWeapon::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({0, 0, 0}, {-8, 0}, 2);
    SetInteractiveText("goblin fly weapon", InteractiveText::COMMON);
}

void GoblinFlyWeapon::Update() {
    RangedWeapon::Update();
}

void GoblinFlyWeapon::LoadResources() {
    SetImages("Resources/weapon/ufo_weapon/", 3, RGB(255, 255, 255));
}

void GoblinFlyWeapon::Attack() {
    GenerateBullets();
}

void GoblinFlyWeapon::GenerateBullets() {
    Vec currentRotation = new Vec(this->rotation);

    for (int i = 0; i < 18; ++i) {
        RedCircleBullet* bullet = static_cast<RedCircleBullet*>(ProjectilePool::Instance()->Acquire(
            ProjectileType::RED_CIRCLE_BULLET));
        bullet->SetPosition(&(this->position + Vec(&rotation, 7) + currentRotation * 20));
        bullet->SetSpeed(rotation, 7);
        bullet->SetDamage(this->GetDamage());
        UpdateTag(bullet);
        ObjectManager::Instance()->AddObject(bullet);
        currentRotation.Rotate(-0.389);
    }
}
