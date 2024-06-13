#include "stdafx.h"
#include "StaffOfLight.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

StaffOfLight::StaffOfLight(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 2;
}

Weapon* StaffOfLight::Copy() {
    return new StaffOfLight(this->damage, this->position);
}

void StaffOfLight::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 0.5);
    SetInteractiveText("Staff of Light", InteractiveText::UNCOMMON);
}

void StaffOfLight::Update() {
    RangedWeapon::Update();
}

void StaffOfLight::LoadResources() {
    SetImages("Resources/weapon/staff_of_light/", 3, RGB(255, 255, 255));
}

void StaffOfLight::Attack() {
    Vec currentRotation = this->rotation;
    for (int i = 0; i < 4; ++i) {
        Bullet* bullet = static_cast<Bullet*>((ProjectilePool::Instance()->
            Acquire(ProjectileType::BIG_YELLOW_CIRCLE_BULLET)));
        bullet->SetSpeed(currentRotation, 7);
        bullet->SetPosition(&(this->position + Vec(&currentRotation, 7)));
        bullet->SetDamage(this->GetDamage());
        UpdateTag(bullet);
        ObjectManager::Instance()->AddObject(bullet);
        currentRotation.Rotate(-1.57);
    }
}
