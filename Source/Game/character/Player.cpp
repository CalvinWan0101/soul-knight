#include "stdafx.h"
#include "Player.h"
#include "Character.h"
#include "../config.h"
#include "../collectable/Collectable.h"
#include "../manager/ObjectManager.h"
#include "../utils/draw/Draw.h"

Player::Player():
alertRange(position),
mp(0),
shield(0),
interactive(false),
damageCooldownCounter(0),
damageCooldownFrameCD(150),
damageEffectCounter(0),
weapon2(nullptr){
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
    DamageEffect();
    if (weapon2) {
        weapon2->SetPosition(GetPosition());
    }
}

void Player::Collision(GameObject* gameObject) {
    Character::Collision(gameObject);
    if (gameObject->HasTag(Tag::MONSTER_ATTACK)) {
        if (damageCooldownCounter == 0) {
            damageCooldownCounter = damageCooldownFrameCD;
            Injuried(dynamic_cast<Projectile*>(gameObject)->GetDamage());
        }
    }
    else if (gameObject->HasTag(Tag::INTERACTABLE) && interactive == true) {
        interactive = false;
        Interactable* interactable = dynamic_cast<Interactable*>(gameObject);
        interactable->Interactive(this);
    }
}

void Player::Attack() {
    if (weapon1) {
        if (weapon1->CanAttack()) {
            int mpCost = weapon1->GetMpCost();
            if (mp >= mpCost) {
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

void Player::RecoverMP(int value) {
    this->mp += value;
    if (this->mp > maxMp) {
        this->mp = maxMp;
    }
}

void Player::Healing(int value) {
    this->hp += value;
    if (this->hp > this->maxHp) {
        this->hp = this->maxHp;
    }
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
    if (weapon2 == nullptr && weapon1 != nullptr) {
        weapon2 = weapon1;
        weapon1 = nullptr;
        RemoveFrontChile(weapon2);
        AddBackChild(weapon2);
    }
    if (this->weapon1 != nullptr) {
        this->weapon1->SetPosition(&this->position);
        RemoveFrontChile(this->weapon1);
        ObjectManager::Instance()->AddObject(this->weapon1);
    }
    this->weapon1 = newWeapon;
    this->weapon1->RemoveTag(Tag::MONSTER_WEAPON);
    this->weapon1->AddTag(Tag::PLAYER_WEAPON);
    this->AddFrontChild(newWeapon);
}

void Player::SwitchWeapon() {
    if (weapon2 != nullptr) {
        RemoveFrontChile(weapon1);
        AddBackChild(weapon1);
        RemoveBackChild(weapon2);
        AddFrontChild(weapon2);
        Weapon* tmpWeapon = weapon1;
        weapon1 = weapon2;
        weapon2 = tmpWeapon;
    }
}

void Player::UseSkill() {
    if (skillCounter == 0) {
        skillCounter = skillFrameCD;
        Skill();
    }
}

void Player::SetInteractive(bool interactive) {
    this->interactive = interactive;
}

void Player::SetAlertRange(double height, double width) {
    alertRange.SetHeight(height);
    alertRange.SetWidth(width);
}

void Player::Injuried(double damage) {
    shieldRecoverCooldownCounter = shieldRecoverCooldownFrameCD;
    damageEffectCounter = 40;
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

void Player::DamageEffect() {
    if (damageEffectCounter > 0 && TRANSLUCENT_EFFECT == true) {
        damageEffectCounter--;
        game_framework::Draw::Instance()->Rectangle(Point(0,0),Point(SIZE_X, SIZE_Y),RGB(200,0,0),damageEffectCounter * 3);
    }
}

