#include "stdafx.h"
#include "CurvedSword.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

CurvedSword::CurvedSword(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 0;
}

Weapon* CurvedSword::Copy() {
    return new CurvedSword(this->damage, this->position);
}

void CurvedSword::Start() {
    MeleeWeapon::Start();
    SetAttackAnimation({-0.7, -1.4, 1.4, 0.7, 0}, {}, 0.6, 0.65);
    SetInteractiveText("Curved Sword", InteractiveText::COMMON);
}

void CurvedSword::Update() {
    MeleeWeapon::Update();
}

void CurvedSword::LoadResources() {
    SetImages("Resources/weapon/curved_sword/", 3, RGB(255, 255, 255));
}

void CurvedSword::Attack() {
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
