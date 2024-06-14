#include "stdafx.h"
#include "Bow.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"
#include "../../projectile/bullet/Arrow.h"

class Bullet;

Bow::Bow(double damage, Point position) {
    this->damage = damage;
    this->position = position;
    this->mpCost = 3;
}


Weapon* Bow::Copy() {
    return new Bow(this->damage, this->position);
}

void Bow::Start() {
    RangedWeapon::Start();
    SetAttackAnimation({0}, {-2, 0}, 0.8);
    SetInteractiveText("Bow", InteractiveText::RARE);
}

void Bow::Update() {
    RangedWeapon::Update();
}

void Bow::LoadResources() {
    SetImages("Resources/weapon/bow/drawn_bow/", 3, RGB(255, 255, 255));
}

void Bow::Attack() {
    Bullet* bullet = static_cast<Arrow*>(ProjectilePool::Instance()->Acquire(ProjectileType::ARROW));
    bullet->SetSpeed(rotation, 7);
    bullet->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet->SetDamage(this->GetDamage());
    UpdateTag(bullet);
    ObjectManager::Instance()->AddObject(bullet);
}
