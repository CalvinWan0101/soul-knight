#include "stdafx.h"
#include "SnowFoxVintage.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

SnowFoxVintage::SnowFoxVintage(double damage, Point position) : fireCooldown(0), bulletNumber(0) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 3;
}

Weapon* SnowFoxVintage::Copy() {
    return new SnowFoxVintage(this->damage, this->position);
}

void SnowFoxVintage::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({0, 0, 0}, {-8, 0}, 0.4);
    SetInteractiveText("Snow Fox Vintage", InteractiveText::LEGENDARY);
}

void SnowFoxVintage::Update() {
    RangedWeapon::Update();
    if (bulletNumber > 0) {
        GenerateBullets();
    }
}

void SnowFoxVintage::LoadResources() {
    SetImages("Resources/weapon/snow_fox_vintage/", 3, RGB(255, 255, 255));
}

void SnowFoxVintage::Attack() {
    bulletNumber = 3;
}

void SnowFoxVintage::GenerateBullets() {
    if (fireCooldown == 0) {
        Bullet* bullet = static_cast<Bullet*>(ProjectilePool::Instance()->Acquire(
            ProjectileType::BAD_PISTOL_BULLET));
        bullet->SetSpeed(rotation, 7);
        bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
        bullet->SetDamage(this->GetDamage());
        UpdateTag(bullet);
        ObjectManager::Instance()->AddObject(bullet);
        fireCooldown = 2;
        bulletNumber--;
    }
    else {
        fireCooldown--;
    }
}
