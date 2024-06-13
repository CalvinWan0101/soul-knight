#include "stdafx.h"
#include "Dart.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

Dart::Dart(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 3;
}


Weapon* Dart::Copy() {
    return new Dart(this->damage, this->position);
}

void Dart::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({0, 0, 0}, {-2, 0}, 0.5);
    SetInteractiveText("Dart", InteractiveText::RARE);
}

void Dart::Update() {
    RangedWeapon::Update();
}

void Dart::LoadResources() {
    SetImages("Resources/weapon/dart/", 3, RGB(255, 255, 255));
}

void Dart::Attack() {
    if (HasTag(Tag::PLAYER_WEAPON)) {
        GeneratePlayerBullet();
    }
    else {
        GenerateMonsterBullet();
    }
}

void Dart::GeneratePlayerBullet() {
    Bullet* bullet = static_cast<Bullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::GAS_BLASTER_BULLET));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    bullet->SetPoison(true);
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}

void Dart::GenerateMonsterBullet() {
    Bullet* bullet = static_cast<Bullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::RED_RECTANGLE_BULLET));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    bullet->SetPoison(true);
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
