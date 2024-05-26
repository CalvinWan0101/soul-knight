#include "stdafx.h"
#include "GasBlaster.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

GasBlaster::GasBlaster(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 1;
}

Weapon* GasBlaster::Copy() {
    return new GasBlaster(this->damage, this->position);
}

void GasBlaster::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({-0.4, -0.2, 0}, {-2, 0}, 0.1);
    SetInteractiveText("gas blaster", InteractiveText::COMMON);
}

void GasBlaster::Update() {
    RangedWeapon::Update();
}

void GasBlaster::LoadResources() {
    SetImages("Resources/weapon/gas_blaster/", 3, RGB(255, 255, 255));
}

void GasBlaster::Attack() {
    Bullet* bullet = static_cast<Bullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::GAS_BLASTER_BULLET));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    bullet->SetPoison(true);
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
