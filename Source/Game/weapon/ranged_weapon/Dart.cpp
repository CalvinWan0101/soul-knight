#include "stdafx.h"
#include "Dart.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

Dart::Dart(Point point) : RangedWeapon(point) {
}

Dart::Dart(double damage) : RangedWeapon(damage) {
}

Weapon* Dart::Copy() {
    return new Dart(this->position);
}

void Dart::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({0, 0, 0}, {-2, 0}, 0.5);
}

void Dart::Update() {
    RangedWeapon::Update();
}

void Dart::LoadResources() {
    SetImages("Resources/weapon/dart/", 3, RGB(255, 255, 255));
}

void Dart::Attack() {
    Bullet* bullet = static_cast<Bullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::RED_RECTANGLE_BULLET));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
