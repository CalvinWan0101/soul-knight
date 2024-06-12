#include "stdafx.h"
#include "RedLightsaber.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

RedLightsaber::RedLightsaber(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 0;
}

Weapon* RedLightsaber::Copy() {
    return new RedLightsaber(this->damage, this->position);
}

void RedLightsaber::Start() {
    MeleeWeapon::Start();
    SetAttackAnimation({-0.7, -1.4, 1.4, 0.7, 0}, {}, 0.6, 0.65);
    SetInteractiveText("Red lightsaber", InteractiveText::EPIC);
}

void RedLightsaber::Update() {
    MeleeWeapon::Update();
}

void RedLightsaber::LoadResources() {
    SetImages("Resources/weapon/red_lightsaber/", 3, RGB(255, 255, 255));
}

void RedLightsaber::Attack() {
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
