#include "stdafx.h"
#include "player.h"
#include "character.h"
#include "../manager/object_manager.h"

Player::Player(): alertRange(position) {
    mp = 0;
    shield = 0;
    interactive = false;
    AddTag(Tag::PLAYER);
}

void Player::Start() {
    SetHitBoxByRatio(0.8, 0.3);
    SetAlertRange(200, 200);
    Character::Start();
}

void Player::Update() {
    Character::Update();
}

void Player::Collision(GameObject* gameObject) {
    Character::Collision(gameObject);
    if (gameObject->HasTag(Tag::MONSTER_ATTACK)) {
        this->hp = this->hp - dynamic_cast<Projectile*>(gameObject)->GetDamage();
    }
    else if (gameObject->HasTag(Tag::PLAYER_WEAPON) && interactive == true) {
        interactive = false;
        Weapon* weapon = dynamic_cast<Weapon*>(gameObject);
        weapon->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
        this->ChangeWeapon(weapon->Copy());
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

HitBox& Player::GetAlertRange() {
    return alertRange;
}


void Player::SetVision(Vec vision) {
    this->vision = vision;
}

void Player::ChangeWeapon(Weapon* newWeapon) {
    if (this->weapon != nullptr) {
        this->weapon->SetPosition(&this->position);
        RemoveFrontChile(this->weapon);
        ObjectManager::Instance()->AddObject(this->weapon);
    }
    this->weapon = newWeapon;
    this->weapon->AddTag(Tag::PLAYER_WEAPON);
    this->AddFrontChild(newWeapon);
}

void Player::SetInteractive(bool interactive) {
    this->interactive = interactive;
}

void Player::SetAlertRange(double height, double width) {
    alertRange.SetHeight(height);
    alertRange.SetWidth(width);
}
