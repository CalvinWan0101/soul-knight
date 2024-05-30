#include "stdafx.h"
#include "BatteryHead.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/BigRedCircleBullet.h"

BatteryHead::BatteryHead(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 5;
}

Weapon* BatteryHead::Copy() {
    return new BatteryHead(this->damage, this->position);
}

void BatteryHead::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({0}, {-2, 0}, 0.8);
    SetInteractiveText("battery head", InteractiveText::COMMON);
}

void BatteryHead::Update() {
    RangedWeapon::Update();
}

void BatteryHead::LoadResources() {
    SetImages("Resources/weapon/battery_head/", 3, RGB(255, 255, 255));
}

void BatteryHead::Attack() {
    Bullet* bullet = static_cast<BigRedCircleBullet*>((ProjectilePool::Instance()->Acquire(
        ProjectileType::BIG_RED_CIRCLE_BULLET)));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
