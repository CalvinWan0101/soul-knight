#include "stdafx.h"
#include "character.h"
#include "../weapon/Weapon.h"

#include <cmath>

Character::Character() {
    hp = 1;
    maxHp = 1;
    face = RIGHT;
    state = IDLE;
    weaponOffsetX = 0;
    weaponOffsetY = 0;
    weapon = nullptr;
}

void Character::Start() {
    GeneralObject::Start();
}

void Character::Update() {
    GeneralObject::Update();
    CheckState();
    CheckFace();
    index = state * 2 + face;
    weapon->Aim(&vision);
    if (face == RIGHT) {
        weapon->SetPosition(&(this->position + Vec(weaponOffsetX , weaponOffsetY)));
    }
    else if (face == LEFT) {
        weapon->SetPosition(&(this->position + Vec(-weaponOffsetX , weaponOffsetY)));
    }
}

void Character::Collision(GeneralObject* generalObject) {
    GeneralObject::Collision(generalObject);
    if (generalObject->HasTag(Tag::OBSTACLE)) {
        Vec speedXComponent(speed.GetX(), 0.0);
        Vec speedYComponent(0.0, speed.GetY());
        this->position = this->position - speedXComponent;
        if (hitBox.IsCollision(&generalObject->GetHitBox())) {
            this->position = this->position + speedXComponent;
            speedYComponent.SetLength(generalObject->GetHitBox().GetHalfHeight() + this->hitBox.GetHalfHeight() - abs(generalObject->GetPosition().GetY() - this->position.GetY()) + 0.1);
            this->position = this->position - speedYComponent;
        }
        else {
            this->position = this->position + speedXComponent;
            speedXComponent.SetLength(generalObject->GetHitBox().GetHalfWidth() + this->hitBox.GetHalfWidth() - abs(generalObject->GetPosition().GetX() - this->position.GetX()) + 0.1);
            this->position = this->position - speedXComponent;
        }
    }
}


int Character::GetHP() {
    return hp;
}

int Character::GetMaxHP() {
    return maxHp;
}

void Character::Attack() {
    if (weapon == nullptr) {
        throw exception("Do not have weapon.");
    }
    weapon->DefaultAttack();
}

void Character::BeAttacked(int damage) {
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

