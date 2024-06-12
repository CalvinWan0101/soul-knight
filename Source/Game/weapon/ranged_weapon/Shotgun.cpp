#include "stdafx.h"
#include "Shotgun.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/BadPistolBullet.h"

Shotgun::Shotgun(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 5;
}


Weapon* Shotgun::Copy() {
    return new Shotgun(this->damage, this->position);
}

void Shotgun::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 0.5);
    SetInteractiveText("shotgun", InteractiveText::LEGENDARY);
}

void Shotgun::Update() {
    RangedWeapon::Update();
}

void Shotgun::LoadResources() {
    SetImages("Resources/weapon/shotgun/", 3, RGB(255, 255, 255));
}

void Shotgun::Attack() {
    if (HasTag(Tag::PLAYER_WEAPON)) {
        GeneratePlayerBullet();
    }
    else {
        GenerateMonsterBullet();
    }
}

void Shotgun::GeneratePlayerBullet() {
    ProjectilePool* projectilePool = ProjectilePool::Instance();
    ObjectManager* objectManager = ObjectManager::Instance();

    Vec currentRotation = this->rotation;
    currentRotation.Rotate(0.4);

    for (int i = 0; i < 5; ++i) {
        Bullet* bullet = static_cast<BadPistolBullet*>(projectilePool->Acquire(ProjectileType::BAD_PISTOL_BULLET));
        bullet->SetSpeed(currentRotation, 7);
        bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
        bullet->SetDamage(this->GetDamage());
        UpdateTag(bullet);
        objectManager->AddObject(bullet);
        currentRotation.Rotate(-0.2);
    }
}

void Shotgun::GenerateMonsterBullet() {
    ProjectilePool* projectilePool = ProjectilePool::Instance();
    ObjectManager* objectManager = ObjectManager::Instance();

    Vec currentRotation = this->rotation;
    currentRotation.Rotate(0.4);

    for (int i = 0; i < 5; ++i) {
        Bullet* bullet = static_cast<BadPistolBullet*>(projectilePool->Acquire(ProjectileType::RED_DIAMOND_BULLET));
        bullet->SetSpeed(currentRotation, 7);
        bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
        bullet->SetDamage(this->GetDamage());
        UpdateTag(bullet);
        objectManager->AddObject(bullet);
        currentRotation.Rotate(-0.2);
    }
}
