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
    GameObject::Start();
}

void Character::Update() {
    GameObject::Update();
    CheckState();
    index = state * 2 + face;
    weapon->SetRotation(&vision);
    if (face == RIGHT) {
        weapon->SetPoint(&(this->point + Vec(weaponOffsetX , weaponOffsetY)));
    }
    else if (face == LEFT) {
        weapon->SetPoint(&(this->point + Vec(-weaponOffsetX , weaponOffsetY)));
    }
}

void Character::Collision(GameObject* gameObject) {
    GameObject::Collision(gameObject);
    if (gameObject->HasTag(Tag::OBSTACLE)) {
        Vec speedXComponent(speed.GetX(), 0.0);
        Vec speedYComponent(0.0, speed.GetY());
        this->point = this->point - speedXComponent;
        if (hitBox.IsCollision(&gameObject->GetHitBox())) {
            this->point = this->point + speedXComponent;
            speedYComponent.SetLength(gameObject->GetHitBox().GetHalfHeight() + this->hitBox.GetHalfHeight() - abs(gameObject->GetPoint().GetY() - this->point.GetY()) + 0.1);
            this->point = this->point - speedYComponent;
        }
        else {
            this->point = this->point + speedXComponent;
            speedXComponent.SetLength(gameObject->GetHitBox().GetHalfWidth() + this->hitBox.GetHalfWidth() - abs(gameObject->GetPoint().GetX() - this->point.GetX()) + 0.1);
            this->point = this->point - speedXComponent;
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

bool Character::IsDead() {
    return hp <= 0;
}

void Character::CheckState() {
    if (vision.GetX() > 0) {
        face = RIGHT;
    }
    else if (vision.GetX() < 0) {
        face = LEFT;
    }

    if (speed.GetLength() == 0.0) {
        state = IDLE;
    }
    else if (speed.GetLength() != 0.0) {
        state = RUN;
    }
    if (hp <= 0) {
        state = DEAD;
    }
}
