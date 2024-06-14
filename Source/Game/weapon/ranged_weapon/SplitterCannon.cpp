#include "stdafx.h"
#include "SplitterCannon.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

SplitterCannon::SplitterCannon(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 3;
}

Weapon* SplitterCannon::Copy() {
    return new SplitterCannon(this->damage, this->position);
}

void SplitterCannon::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 0.5);
    SetInteractiveText("Splitter Cannon", InteractiveText::UNCOMMON);
}

void SplitterCannon::Update() {
    RangedWeapon::Update();
}

void SplitterCannon::LoadResources() {
    SetImages("Resources/weapon/splitter_cannon/", 3, RGB(255, 255, 255));
}

void SplitterCannon::Attack() {
    Bullet* bullet = static_cast<Bullet*>((ProjectilePool::Instance()->Acquire(
        ProjectileType::SPLITTER_CANNON_BULLET)));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
