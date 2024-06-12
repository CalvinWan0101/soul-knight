#include "stdafx.h"
#include "GoblinWeapon.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/RedCircleBullet.h"
#include "../../utils/Rand.h"

GoblinWeapon::GoblinWeapon(double damage, Point position) : fireCooldown(0), bulletNumber(0) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 9;
}

Weapon* GoblinWeapon::Copy() {
    return new GoblinWeapon(this->damage, this->position);
}

void GoblinWeapon::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({0, 0, 0}, {-8, 0}, 2);
    SetInteractiveText("goblin weapon", InteractiveText::COMMON);
}

void GoblinWeapon::Update() {
    RangedWeapon::Update();
    if (bulletNumber > 0) {
        GenerateBullets();
    }
}

void GoblinWeapon::LoadResources() {
    SetImages("Resources/weapon/ufo_weapon/", 3, RGB(255, 255, 255));
}

void GoblinWeapon::Attack() {
    bulletNumber = 9;
}

void GoblinWeapon::GenerateBullets() {
    if (fireCooldown == 0) {
        Vec currentRotation = new Vec(this->rotation);
        currentRotation.Rotate(Rand::Instance()->Get(-785, 785) / 1000.0);

        RedCircleBullet* bullet = static_cast<RedCircleBullet*>(ProjectilePool::Instance()->Acquire(
            ProjectileType::RED_CIRCLE_BULLET));
        bullet->SetSpeed(currentRotation, 3);
        bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
        bullet->SetDamage(this->GetDamage());
        UpdateTag(bullet);
        ObjectManager::Instance()->AddObject(bullet);
        fireCooldown = 5;
        bulletNumber--;
    }
    else {
        fireCooldown--;
    }
}
