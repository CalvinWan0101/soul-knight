#include "stdafx.h"
#include "bullet.h"

Bullet::Bullet() {
    damage = 0;
}

void Bullet::Start() {
    SetHitBoxByRatio(0.3, 0.3);
    RotatableObject::Start();
}

void Bullet::Update() {
    RotatableObject::Update();
}

void Bullet::Collision(GameObject* gameObject) {
    if ((gameObject->HasTag(Tag::PLAYER) && this->HasTag(Tag::MONSTER_ATTACK)) ||
        (gameObject->HasTag(Tag::MONSTER) && this->HasTag(Tag::PLAYER_ATTACK)) ||
        gameObject->HasTag(Tag::OBSTACLE)) {
        this->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
    }
}

void Bullet::SetDamage(int damage) {
    this->damage = damage;
}

int Bullet::GetDamage() {
    return damage;
}


