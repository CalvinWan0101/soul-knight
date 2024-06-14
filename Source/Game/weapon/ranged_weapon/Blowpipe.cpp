#include "stdafx.h"
#include "Blowpipe.h"

#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

Blowpipe::Blowpipe(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 3;
}


Weapon* Blowpipe::Copy() {
    return new Blowpipe(this->damage, this->position);
}

void Blowpipe::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({0, 0, 0}, {-2, 0}, 0.5);
    SetInteractiveText("Blowpipe", InteractiveText::RARE);
}

void Blowpipe::Update() {
    RangedWeapon::Update();
}

void Blowpipe::LoadResources() {
    SetImages("Resources/weapon/dart/", 3, RGB(255, 255, 255));
}

void Blowpipe::Attack() {
    if (HasTag(Tag::PLAYER_WEAPON)) {
        GeneratePlayerBullet();
    }
    else {
        GenerateMonsterBullet();
    }
}

void Blowpipe::GeneratePlayerBullet() {
    Bullet* bullet = static_cast<Bullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::GREEN_RECTANGLE_BULLET));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    bullet->SetPoison(true);
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}

void Blowpipe::GenerateMonsterBullet() {
    Bullet* bullet = static_cast<Bullet*>(ProjectilePool::Instance()->Acquire(ProjectileType::RED_RECTANGLE_BULLET));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    bullet->SetPoison(true);
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
