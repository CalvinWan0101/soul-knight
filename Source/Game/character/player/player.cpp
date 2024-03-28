#include "stdafx.h"
#include "player.h"
#include "../character.h"
#include "../../utils/object_manager.h"

Player::Player() {
    mp = 0;
    shield = 0;
    AddTag(Tag::PLAYER);
}

void Player::Start() {
    SetHitBoxByRatio(0.8, 0.3);
    Character::Start();
}

void Player::Update() {
    Character::Update();
}

void Player::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::MONSTER_BULLET)) {
        this->hp = this->hp - dynamic_cast<Bullet*>(gameObject)->GetDamage();
    }
}

int Player::GetMP() {
    return mp;
}

int Player::GetMaxMP() {
    return maxMp;
}

int Player::GetShield() {
    return shield;
}

int Player::GetMaxShield() {
    return maxShild;
}

void Player::SetVision(Vec vision) {
    this->vision = vision;
}

void Player::ChangeWeapon(Weapon* newWeapon) {
    if (this->weapon != nullptr) {
        this->weapon->SetPoint(&this->point);
        RemoveFrontChile(this->weapon);
        ObjectManager::Instance()->AddObject(this->weapon);
    }
    this->weapon = newWeapon;
    this->AddFrontChild(newWeapon);
}

