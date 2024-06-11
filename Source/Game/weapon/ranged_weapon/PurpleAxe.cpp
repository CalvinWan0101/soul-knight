#include "stdafx.h"
#include "PurpleAxe.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/RedTriangleBullet.h"

PurpleAxe::PurpleAxe(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 18;
}

Weapon* PurpleAxe::Copy() {
    return new PurpleAxe(this->damage, this->position);
}

void PurpleAxe::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({-0.7, -1.4, 1.4, 0.7, 0}, {}, 2, 0.65);
    SetInteractiveText("purple axe", InteractiveText::UNCOMMON);
}

void PurpleAxe::Update() {
    RangedWeapon::Update();
}

void PurpleAxe::LoadResources() {
    SetImages("Resources/weapon/purple_axe/", 3, RGB(255, 255, 255));
}

void PurpleAxe::Attack() {
    ProjectilePool* projectilePool = ProjectilePool::Instance();
    ObjectManager* objectManager = ObjectManager::Instance();

    Vec currentRotation = this->rotation;
    // currentRotation.Rotate(-0.785);

    for (int i = 0; i < 9; ++i) {
        Bullet* bullet = static_cast<RedTriangleBullet*>(projectilePool->Acquire(ProjectileType::RED_TRIANGLE_BULLET));
        bullet->SetSpeed(currentRotation, 5);
        bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
        bullet->SetDamage(this->GetDamage());
        UpdateTag(bullet);
        objectManager->AddObject(bullet);
        currentRotation.Rotate(-0.19625);
    }
}
