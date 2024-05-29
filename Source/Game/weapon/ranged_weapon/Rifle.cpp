#include "stdafx.h"
#include "Rifle.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/BadPistolBullet.h"

Rifle::Rifle(double damage, Point position) : generateBulletCounter(0), bulletNumber(0) {
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
    if (bulletNumber > 0) {
        GenerateBullets();   
    }
}

void Rifle::LoadResources() {
    SetImages("Resources/weapon/rifle/", 3, RGB(255, 255, 255));
}

void Rifle::Attack() {
    bulletNumber = 9;
}

void Rifle::GenerateBullets() {
    if (generateBulletCounter == 0) {
        Vec* currentRotation = new Vec(this->rotation);

        ProjectilePool* projectilePool = ProjectilePool::Instance();
        ObjectManager* objectManager = ObjectManager::Instance();
        Bullet* bullet;
        if (HasTag(Tag::PLAYER_ATTACK)) {
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
        
        delete currentRotation;

        generateBulletCounter = 5;
        bulletNumber--;
    }
    generateBulletCounter--;
}
