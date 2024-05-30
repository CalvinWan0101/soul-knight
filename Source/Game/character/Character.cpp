#include "stdafx.h"
#include "Character.h"
#include "../weapon/Weapon.h"

#include <cmath>

Character::Character(): hp(1), maxHp(1), face(RIGHT), state(IDLE), weaponOffsetX(0), weaponOffsetY(0), weapon1(nullptr), poisonedIcon(nullptr) {
    poison.damage = 0;
    poison.counter = poison.damageInterval;
    poison.damageRemainingTimes = 0;
}

void Character::Start() {
    GeneralObject::Start();
    if (!poisonedIcon) {
        poisonedIcon = new PoisonedIcon();
        AddFrontChild(poisonedIcon);
    }
    this->hp = maxHp;
    poison.damageRemainingTimes = 0;
}

void Character::Update() {
    GeneralObject::Update();
    CheckState();
    CheckFace();
    index = state * 2 + face;
    weapon1->Aim(&vision);
    if (face == RIGHT) {
        weapon1->SetPosition(&(this->position + Vec(weaponOffsetX, weaponOffsetY)));
    }
    else if (face == LEFT) {
        weapon1->SetPosition(&(this->position + Vec(-weaponOffsetX, weaponOffsetY)));
    }

    if (poison.damageRemainingTimes > 0 && !this->HasTag(Tag::DEAD)) {
        poisonedIcon->SetPosition(this->position + Point(0, -hitBox.GetHalfHeight() - 10));
        poisonedIcon->SetVisible(true);
        poison.counter--;
        if (poison.counter == 0) {
            poison.counter = poison.damageInterval;
            poison.damageRemainingTimes--;
            Injuried(poison.damage);
        }
    }
    else {
        poisonedIcon->SetVisible(false);
    }
}

void Character::Collision(GameObject* gameObject) {
    GeneralObject::Collision(gameObject);
    if (gameObject->HasTag(Tag::OBSTACLE)) {
        Vec speedXComponent(speed.GetX(), 0.0);
        Vec speedYComponent(0.0, speed.GetY());
        this->position = this->position - speedXComponent;
        if (hitBox.IsCollision(&gameObject->GetHitBox())) {
            this->position = this->position + speedXComponent;
            speedYComponent.SetLength(
                gameObject->GetHitBox().GetHalfHeight() + this->hitBox.GetHalfHeight() - abs(
                    gameObject->GetPosition().GetY() - this->position.GetY()) + 0.1);
            this->position = this->position - speedYComponent;
        }
        else {
            this->position = this->position + speedXComponent;
            speedXComponent.SetLength(
                gameObject->GetHitBox().GetHalfWidth() + this->hitBox.GetHalfWidth() - abs(
                    gameObject->GetPosition().GetX() - this->position.GetX()) + 0.1);
            this->position = this->position - speedXComponent;
        }
    }
}


double Character::GetHP() {
    return hp;
}

double Character::GetMaxHP() {
    return maxHp;
}

void Character::Attack() {
    if (weapon1 == nullptr) {
        throw exception("Do not have weapon.");
    }
    weapon1->DefaultAttack();
}

void Character::Poisoned(double poisonDamage) {
    poison.damage = poisonDamage;
    poison.damageRemainingTimes = 3;
}


void Character::CheckState() {
    if (hp <= 0) {
        state = DEAD;
        AddTag(Tag::DEAD);
    }
    else if (speed.GetLength() == 0.0) {
        state = IDLE;
    }
    else if (speed.GetLength() != 0.0) {
        state = RUN;
    }
}

void Character::CheckFace() {
    if (vision.GetX() > 0) {
        face = RIGHT;
    }
    else if (vision.GetX() < 0) {
        face = LEFT;
    }
}
