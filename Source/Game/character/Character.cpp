#include "stdafx.h"
#include "Character.h"
#include "../weapon/Weapon.h"

#include <cmath>

Character::Character(): hp(1), maxHp(1), face(RIGHT), state(IDLE), weaponOffsetX(0), weaponOffsetY(0), weapon(nullptr) {
}

void Character::Start() {
    GeneralObject::Start();
    this->hp = maxHp;
}

void Character::Update() {
    GeneralObject::Update();
    CheckState();
    CheckFace();
    index = state * 2 + face;
    weapon->Aim(&vision);
    if (face == RIGHT) {
        weapon->SetPosition(&(this->position + Vec(weaponOffsetX, weaponOffsetY)));
    }
    else if (face == LEFT) {
        weapon->SetPosition(&(this->position + Vec(-weaponOffsetX, weaponOffsetY)));
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
    if (weapon == nullptr) {
        throw exception("Do not have weapon.");
    }
    weapon->DefaultAttack();
}

void Character::BeAttacked(double damage) {
    hp -= damage;
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
