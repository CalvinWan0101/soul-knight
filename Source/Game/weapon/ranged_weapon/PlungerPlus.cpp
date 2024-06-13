#include "stdafx.h"
#include "PlungerPlus.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

PlungerPlus::PlungerPlus(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 3;
}

Weapon* PlungerPlus::Copy() {
    return new PlungerPlus(this->damage, this->position);
}

void PlungerPlus::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 0.5);
    SetInteractiveText("Plunger Plus", InteractiveText::EPIC);
}

void PlungerPlus::Update() {
    RangedWeapon::Update();
}

void PlungerPlus::LoadResources() {
    SetImages("Resources/weapon/plunger_plus/", 3, RGB(255, 255, 255));
}

void PlungerPlus::Attack() {
    Bullet* bullet = static_cast<Bullet*>((ProjectilePool::Instance()->Acquire(
        ProjectileType::SHIT)));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
