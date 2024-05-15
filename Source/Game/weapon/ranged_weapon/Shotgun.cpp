#include "stdafx.h"
#include "Shotgun.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/BadPistolBullet.h"

Shotgun::Shotgun(Point point) : RangedWeapon(point) {
}

Shotgun::Shotgun(double damage) : RangedWeapon(damage) {
}

Weapon* Shotgun::Copy() {
    return new Shotgun(this->position);
}

void Shotgun::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 0.5);
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

    Bullet* bullet1 = static_cast<BadPistolBullet*>(projectilePool->Acquire(ProjectileType::BAD_PISTOL_BULLET));
    bullet1->SetSpeed(currentRotation, 7);
    bullet1->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet1->SetDamage(this->GetDamage());
    UpdateTag(bullet1);
    objectManager->AddObject(bullet1);

    currentRotation.Rotate(-0.2);

    Bullet* bullet2 = static_cast<BadPistolBullet*>(projectilePool->Acquire(ProjectileType::BAD_PISTOL_BULLET));
    bullet2->SetSpeed(currentRotation, 7);
    bullet2->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet2->SetDamage(this->GetDamage());
    UpdateTag(bullet2);
    objectManager->AddObject(bullet2);

    currentRotation.Rotate(-0.2);

    Bullet* bullet3 = static_cast<BadPistolBullet*>(projectilePool->Acquire(ProjectileType::BAD_PISTOL_BULLET));
    bullet3->SetSpeed(currentRotation, 7);
    bullet3->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet3->SetDamage(this->GetDamage());
    UpdateTag(bullet3);
    objectManager->AddObject(bullet3);

    currentRotation.Rotate(-0.2);

    Bullet* bullet4 = static_cast<BadPistolBullet*>(projectilePool->Acquire(ProjectileType::BAD_PISTOL_BULLET));
    bullet4->SetSpeed(currentRotation, 7);
    bullet4->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet4->SetDamage(this->GetDamage());
    UpdateTag(bullet4);
    objectManager->AddObject(bullet4);

    currentRotation.Rotate(-0.2);

    Bullet* bullet5 = static_cast<BadPistolBullet*>(projectilePool->Acquire(ProjectileType::BAD_PISTOL_BULLET));
    bullet5->SetSpeed(currentRotation, 7);
    bullet5->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet5->SetDamage(this->GetDamage());
    UpdateTag(bullet5);
    objectManager->AddObject(bullet5);
}

void Shotgun::GenerateMonsterBullet() {
    ProjectilePool* projectilePool = ProjectilePool::Instance();
    Vec currentRotation = this->rotation;
    currentRotation.Rotate(0.4);

    Bullet* bullet1 = static_cast<BadPistolBullet*>(projectilePool->Acquire(ProjectileType::RED_DIAMOND_BULLET));
    bullet1->SetSpeed(currentRotation, 7);
    bullet1->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet1->SetDamage(this->GetDamage());
    UpdateTag(bullet1);
    ObjectManager::Instance()->AddObject(bullet1);

    currentRotation.Rotate(-0.2);

    Bullet* bullet2 = static_cast<BadPistolBullet*>(projectilePool->Acquire(ProjectileType::RED_DIAMOND_BULLET));
    bullet2->SetSpeed(currentRotation, 7);
    bullet2->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet2->SetDamage(this->GetDamage());
    UpdateTag(bullet2);
    ObjectManager::Instance()->AddObject(bullet2);

    currentRotation.Rotate(-0.2);

    Bullet* bullet3 = static_cast<BadPistolBullet*>(projectilePool->Acquire(ProjectileType::RED_DIAMOND_BULLET));
    bullet3->SetSpeed(currentRotation, 7);
    bullet3->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet3->SetDamage(this->GetDamage());
    UpdateTag(bullet3);
    ObjectManager::Instance()->AddObject(bullet3);

    currentRotation.Rotate(-0.2);

    Bullet* bullet4 = static_cast<BadPistolBullet*>(projectilePool->Acquire(ProjectileType::RED_DIAMOND_BULLET));
    bullet4->SetSpeed(currentRotation, 7);
    bullet4->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet4->SetDamage(this->GetDamage());
    UpdateTag(bullet4);
    ObjectManager::Instance()->AddObject(bullet4);

    currentRotation.Rotate(-0.2);

    Bullet* bullet5 = static_cast<BadPistolBullet*>(projectilePool->Acquire(ProjectileType::RED_DIAMOND_BULLET));
    bullet5->SetSpeed(currentRotation, 7);
    bullet5->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet5->SetDamage(this->GetDamage());
    UpdateTag(bullet5);
    ObjectManager::Instance()->AddObject(bullet5);
}
