#include "stdafx.h"
#include "Bazooka.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

Bazooka::Bazooka(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 4;
}

Weapon* Bazooka::Copy() {
    return new Bazooka(this->damage, this->position);
}

void Bazooka::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 0.5);
    SetInteractiveText("Bazooka", InteractiveText::UNCOMMON);
}

void Bazooka::Update() {
    RangedWeapon::Update();
}

void Bazooka::LoadResources() {
    SetImages("Resources/weapon/bazooka/", 3, RGB(255, 255, 255));
}

void Bazooka::Attack() {
    Bullet* bullet = static_cast<Bullet*>((ProjectilePool::Instance()->Acquire(
        ProjectileType::RPG)));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
