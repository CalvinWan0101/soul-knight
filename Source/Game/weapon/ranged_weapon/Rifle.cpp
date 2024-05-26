#include "stdafx.h"
#include "Rifle.h"

#include <thread>

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/BadPistolBullet.h"

Rifle::Rifle(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 9;
}

Weapon* Rifle::Copy() {
    return new Rifle(this->damage, this->position);
}

void Rifle::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({0, 0, 0}, {-8, 0}, 2);
    SetInteractiveText("rifle", InteractiveText::COMMON);
}

void Rifle::Update() {
    RangedWeapon::Update();
}

void Rifle::LoadResources() {
    SetImages("Resources/weapon/rifle/", 3, RGB(255, 255, 255));
}

void Rifle::Attack() {
    if (HasTag(Tag::PLAYER_WEAPON)) {
        std::thread(&Rifle::GenerateBullets, this, true).detach();
    }
    else {
        std::thread(&Rifle::GenerateBullets, this, false).detach();
    }
}

void Rifle::GenerateBullets(bool isPlayer) {
    Vec* currentRotation = new Vec(this->rotation);

    ProjectilePool* projectilePool = ProjectilePool::Instance();
    ObjectManager* objectManager = ObjectManager::Instance();
    for (int i = 0; i < 9; ++i) {
        Bullet* bullet;
        if (isPlayer) {
            bullet = static_cast<BadPistolBullet*>(projectilePool->Acquire(ProjectileType::BAD_PISTOL_BULLET));
        }
        else {
            bullet = static_cast<BadPistolBullet*>(projectilePool->Acquire(ProjectileType::RED_CIRCLE_BULLET));
        }
        bullet->SetSpeed(currentRotation, 7);
        bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
        bullet->SetDamage(this->GetDamage());
        UpdateTag(bullet);
        objectManager->AddObject(bullet);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    delete currentRotation;
}
