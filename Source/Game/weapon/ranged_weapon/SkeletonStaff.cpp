#include "stdafx.h"
#include "SkeletonStaff.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/RedSquareBullet.h"

SkeletonStaff::SkeletonStaff(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 25;
}

Weapon* SkeletonStaff::Copy() {
    return new SkeletonStaff(this->damage, this->position);
}

void SkeletonStaff::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 2, 0.65);
}

void SkeletonStaff::Update() {
    RangedWeapon::Update();
}

void SkeletonStaff::LoadResources() {
    SetImages("Resources/weapon/skeleton_staff/", 3, RGB(255, 255, 255));
}

void SkeletonStaff::Attack() {
    ProjectilePool* projectilePool = ProjectilePool::Instance();
    ObjectManager* objectManager = ObjectManager::Instance();

    Vec currentRotation = this->rotation;

    for (int i = 0; i < 25; ++i) {
        Bullet* bullet = static_cast<RedSquareBullet*>(projectilePool->Acquire(ProjectileType::RED_CIRCLE_BULLET));
        bullet->SetSpeed(currentRotation, 5);
        bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
        bullet->SetDamage(this->GetDamage());
        UpdateTag(bullet);
        objectManager->AddObject(bullet);
        currentRotation.Rotate(-0.3);
    }
}
