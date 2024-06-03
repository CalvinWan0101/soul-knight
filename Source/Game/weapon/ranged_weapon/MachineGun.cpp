#include "stdafx.h"
#include "MachineGun.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/RedRectangleBullet.h"

MachineGun::MachineGun(double damage, Point position) : fireCooldown(0), bulletNumber(0) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 3;
}

Weapon* MachineGun::Copy() {
    return new MachineGun(this->damage, this->position);
}

void MachineGun::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({0, 0, 0}, {-8, 0}, 2);
    SetInteractiveText("alien machine gun", InteractiveText::COMMON);
}

void MachineGun::Update() {
    RangedWeapon::Update();
    if (bulletNumber > 0) {
        GenerateBullets();
    }
}

void MachineGun::LoadResources() {
    SetImages("Resources/weapon/alien_machine_gun/", 3, RGB(255, 255, 255));
}

void MachineGun::Attack() {
    bulletNumber = 2;
}

void MachineGun::GenerateBullets() {
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
