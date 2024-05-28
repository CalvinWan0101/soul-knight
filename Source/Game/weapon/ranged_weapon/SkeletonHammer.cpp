#include "stdafx.h"
#include "SkeletonHammer.h"

#include "../../character/monster/floor_2/skeleton/Skeleton.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/RedCircleBullet.h"

SkeletonHammer::SkeletonHammer(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 18;
}

Weapon* SkeletonHammer::Copy() {
    return new SkeletonHammer(this->damage, this->position);
}

void SkeletonHammer::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({-0.7, -1.4, 1.4, 0.7, 0}, {}, 0.835, 0.65);
    SetInteractiveText("skeleton hammer", InteractiveText::UNCOMMON);
}

void SkeletonHammer::Update() {
    RangedWeapon::Update();
}

void SkeletonHammer::LoadResources() {
    SetImages("Resources/weapon/skeleton_hammer/", 3, RGB(255, 255, 255));
}

void SkeletonHammer::Attack() {
    ProjectilePool* projectilePool = ProjectilePool::Instance();
    ObjectManager* objectManager = ObjectManager::Instance();

    Vec currentRotation = this->rotation;

    for (int i = 0; i < 18; ++i) {
        Bullet* bullet = static_cast<RedCircleBullet*>(projectilePool->Acquire(ProjectileType::RED_CIRCLE_BULLET));
        bullet->SetSpeed(currentRotation, 7);
        bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
        bullet->SetDamage(this->GetDamage());
        UpdateTag(bullet);
        objectManager->AddObject(bullet);
        currentRotation.Rotate(-0.35);
    }
}
