#include "stdafx.h"
#include "Bullet.h"

#include "../character/Character.h"

Bullet::Bullet() {
    AddTag(Tag::PROJECTILE);
}

void Bullet::Start() {
    RotatableObject::Start();
    SetHitBoxByRatio(0.3, 0.3);
}

void Bullet::Update() {
    RotatableObject::Update();
}

void Bullet::Collision(GameObject* gameObject) {
    if ((gameObject->HasTag(Tag::PLAYER) && this->HasTag(Tag::MONSTER_ATTACK)) ||
        (gameObject->HasTag(Tag::MONSTER) && !gameObject->HasTag(Tag::DEAD) && this->HasTag(Tag::PLAYER_ATTACK)) ||
        gameObject->HasTag(Tag::OBSTACLE)) {
        this->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
        if (GetPoison()) {
            if (gameObject->HasTag(Tag::PLAYER)) {
                dynamic_cast<Character*>(gameObject)->Poisoned(1);
            }
            else if (gameObject->HasTag(Tag::MONSTER)) {
                dynamic_cast<Character*>(gameObject)->Poisoned(5);
            }
        }
    }
}

void Bullet::UpdateTag(GameObject* gameObject) {
    if (HasTag(Tag::PLAYER_ATTACK)) {
        gameObject->AddTag(Tag::PLAYER_ATTACK);
        gameObject->RemoveTag(Tag::MONSTER_ATTACK);
    }
    else if (HasTag(Tag::MONSTER_ATTACK)) {
        gameObject->AddTag(Tag::MONSTER_ATTACK);
        gameObject->RemoveTag(Tag::PLAYER_ATTACK);
    }
}
