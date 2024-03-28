#include "stdafx.h"
#include "character.h"
#include "../weapon/Weapon.h"

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
}

void Character::Update() {
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
