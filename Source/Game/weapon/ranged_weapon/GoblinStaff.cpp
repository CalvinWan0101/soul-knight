#include "stdafx.h"
#include "GoblinStaff.h"

#include "../../projectile/bullet/RedSplinterBullet.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

GoblinStaff::GoblinStaff(Point point) : RangedWeapon(point) {
}

GoblinStaff::GoblinStaff(double damage) : RangedWeapon(damage) {
}

Weapon* GoblinStaff::Copy() {
    return new GoblinStaff(this->position);
}

void GoblinStaff::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 0.5);
}

void GoblinStaff::Update() {
    RangedWeapon::Update();
}

void GoblinStaff::LoadResources() {
    SetImages("Resources/weapon/goblin_staff/", 3, RGB(255, 255, 255));
}

void GoblinStaff::Attack() {
    Bullet* bullet = static_cast<RedSplinterBullet*>((ProjectilePool::Instance()->Acquire(ProjectileType::RED_SPLINTER_BULLET)));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
