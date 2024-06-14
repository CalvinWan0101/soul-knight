#include "stdafx.h"
#include "GatlingGun.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

GatlingGun::GatlingGun(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 2;
}

Weapon* GatlingGun::Copy() {
    return new GatlingGun(this->damage, this->position);
}

void GatlingGun::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({0}, {-2, 0}, 0.1);
    SetInteractiveText("Gatling Gun", InteractiveText::EPIC);
}

void GatlingGun::Update() {
    RangedWeapon::Update();
}

void GatlingGun::LoadResources() {
    SetImages("Resources/weapon/gatling_gun/", 3, RGB(255, 255, 255));
}

void GatlingGun::Attack() {
    Vec currentRotation = GetRotation();
    currentRotation.Rotate(-0.3);
    for (int i = 0; i < 4; i++) {
        Bullet* bullet = static_cast<Bullet*>(ProjectilePool::Instance()->Acquire(
            ProjectileType::YELLOW_RECTANGLE_BULLET));
        bullet->SetSpeed(currentRotation, 9);
        bullet->SetPosition(&(this->position + Vec(&currentRotation, 7)));
        bullet->SetDamage(this->GetDamage());
        UpdateTag(bullet);
        ObjectManager::Instance()->AddObject(bullet);
        currentRotation.Rotate(0.2);
    }
}
