#include "stdafx.h"
#include "character.h"
#include "../weapon/Weapon.h"

Character::Character() {
    hp = 1;
    maxHp = 1;
    face = RIGHT;
    state = IDLE;
}

void Character::Start() {
}

void Character::Update() {
    CheckState();
    if (state <= 1) {
        index = state + 2 * face;
    }
    dynamic_cast<Weapon*>(frontGameObjects[0])->SetRotation(&vision);
    if (face == RIGHT) {
        frontGameObjects[0]->GetPoint().SetX(7);
    }
    else if (face == LEFT) {
        frontGameObjects[0]->GetPoint().SetX(-7);
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
    if (hp == 0) {
        state = DEAD;
    }
}
