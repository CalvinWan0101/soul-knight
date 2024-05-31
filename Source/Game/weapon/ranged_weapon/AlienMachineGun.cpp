#include "stdafx.h"
#include "AlienMachineGun.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/RedRectangleBullet.h"

AlienMachineGun::AlienMachineGun(double damage, Point position) : fireCooldown(0), bulletNumber(0) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 3;
}

Weapon* AlienMachineGun::Copy() {
    return new AlienMachineGun(this->damage, this->position);
}

void AlienMachineGun::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({0, 0, 0}, {-8, 0}, 2);
    SetInteractiveText("alien machine gun", InteractiveText::COMMON);
}

void AlienMachineGun::Update() {
    RangedWeapon::Update();
    if (bulletNumber > 0) {
        GenerateBullets();
    }
}

void AlienMachineGun::LoadResources() {
    SetImages("Resources/weapon/alien_machine_gun/", 3, RGB(255, 255, 255));
}

void AlienMachineGun::Attack() {
    bulletNumber = 2;
}

void AlienMachineGun::GenerateBullets() {
    if (fireCooldown == 0) {
        Vec currentRotation = new Vec(this->rotation);
        currentRotation.Rotate(0.2);

        for (int i = 0; i < 3; ++i) {
            RedRectangleBullet* bullet = static_cast<RedRectangleBullet*>(ProjectilePool::Instance()->Acquire(
                ProjectileType::RED_RECTANGLE_BULLET));
            bullet->SetSpeed(currentRotation, 7);
            bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
            bullet->SetDamage(this->GetDamage());
            UpdateTag(bullet);
            ObjectManager::Instance()->AddObject(bullet);
            currentRotation.Rotate(-0.2);
        }
        fireCooldown = 5;
        bulletNumber--;
    }
    else {
        fireCooldown--;
    }
}
