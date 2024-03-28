#include "stdafx.h"
#include "monster.h"

#include "../character.h"

Monster::Monster() {
    AddTag(Tag::MONSTER);
}

void Monster::Start() {
    Character::Start();
}

void Monster::Update() {
    Character::Update();
}

void Monster::SetWeapon(Weapon* weapon) {
    this->weapon = weapon;
    this->AddFrontChild(weapon);
}
