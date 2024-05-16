#include "stdafx.h"
#include "Player.h"
#include "Character.h"
#include "../config.h"
#include "../manager/ObjectManager.h"
#include "../utils/draw/Draw.h"

Player::Player():
alertRange(position),
mp(0),
shield(0),
interactive(false),
damageCooldownCounter(0),
damageCooldownFrameCD(150){
    shieldRecoverCooldownFrameCD = 250;
    shieldRecoverCooldownCounter = shieldRecoverCooldownFrameCD;
    AddTag(Tag::PLAYER);
}

void Player::Start() {
    Character::Start();
    SetHitBoxByRatio(0.8, 0.3);
    SetAlertRange(200, 200);
}

void Player::Update() {
    Character::Update();
    CalculateDamageCooldownCounter();
    CalculateShieldRecoverCounter();
}

void Player::Collision(GameObject* gameObject) {
    Character::Collision(gameObject);
    if (gameObject->HasTag(Tag::MONSTER_ATTACK)) {
        if (damageCooldownCounter == 0) {
            Injuried(dynamic_cast<Projectile*>(gameObject)->GetDamage());
        }
    }
    else if (gameObject->HasTag(Tag::PLAYER_WEAPON) && interactive == true) {
        interactive = false;
        Weapon* weapon = dynamic_cast<Weapon*>(gameObject);
        weapon->AddTag(Tag::REMOVE_ON_NEXT_FRAME);
        this->ChangeWeapon(weapon->Copy());
    }
}

void Player::Attack() {
    if (weapon) {
        if (weapon->CanAttack()) {
            int mpCost = weapon->GetMpCost();
            if (mp > mpCost) {
                mp -= mpCost;
                Character::Attack();
            }
        }
    }
}


int Player::GetMP() {
    return mp;
}

int Player::GetMaxMP() {
    return maxMp;
}

double Player::GetShield() {
    return shield;
}

double Player::GetMaxShield() {
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
    this->weapon->RemoveTag(Tag::MONSTER_WEAPON);
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

void Player::Injuried(double damage) {
    damageCooldownCounter = damageCooldownFrameCD;
    shieldRecoverCooldownCounter = shieldRecoverCooldownFrameCD;
    if (damage > shield) {
        damage -= shield;
        shield = 0;
        hp -= (damage > hp) ? hp : damage;
    }
    else {
        shield -= damage;
    }
}

void Player::CalculateDamageCooldownCounter() {
    if (damageCooldownCounter > 0) {
        damageCooldownCounter--;
        if (damageCooldownCounter > 100 && TRANSLUCENT_EFFECT == true) {
            game_framework::Draw::Instance()->Rectangle(Point(0,0),Point(SIZE_X, SIZE_Y),RGB(200,0,0),(damageCooldownCounter - 100) * 2);
        }
        visible = damageCooldownCounter / 7 % 2 == 0;
    }
}

void Player::CalculateShieldRecoverCounter() {
    if (shield < maxShild) {
        shieldRecoverCooldownCounter--;
        if (shieldRecoverCooldownCounter == 0) {
            shield++;
            shieldRecoverCooldownCounter = 50;
        }
    }
    else {
        shieldRecoverCooldownCounter = shieldRecoverCooldownFrameCD;
    }
}

