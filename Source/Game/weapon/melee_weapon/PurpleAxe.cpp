#include "stdafx.h"
#include "PurpleAxe.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

PurpleAxe::PurpleAxe(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 0;
}

Weapon* PurpleAxe::Copy() {
    return new PurpleAxe(this->damage, this->position);
}

void PurpleAxe::Start() {
    MeleeWeapon::Start();
    SetAttackAnimation({-0.7, -1.4, 1.4, 0.7, 0}, {}, 0.6, 0.65);
    SetInteractiveText("purple axe", InteractiveText::COMMON);
}

void PurpleAxe::Update() {
    MeleeWeapon::Update();
}

void PurpleAxe::LoadResources() {
    SetImages("Resources/weapon/purple_axe/", 3, RGB(255, 255, 255));
}

void PurpleAxe::Attack() {
    InvisibleShockWave* shockWave = static_cast<InvisibleShockWave*>(ProjectilePool::Instance()->Acquire(
        ProjectileType::INVISIBLE_SHOCK_WAVE));
    shockWave->SetPosition(&(this->position + Vec(&rotation, 10)));
    shockWave->SetSpeed(rotation, 0);
    shockWave->SetSize(30);
    shockWave->SetDamage(damage);
    shockWave->SetAliveTime(0.1);
    UpdateTag(shockWave);
    ObjectManager::Instance()->AddObject(shockWave);
}
