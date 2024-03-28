#include "stdafx.h"
#include "bullet.h"

Bullet::Bullet() {
    damage = 0;;
}

void Bullet::Start() {
    SetHitBoxByRatio(0.3, 0.3);
    RotatableObject::Start();
}

void Bullet::Update() {
    RotatableObject::Update();
}

void Bullet::SetDamage(int damage) {
    this->damage = damage;
}

int Bullet::GetDamage() {
    return damage;
}


