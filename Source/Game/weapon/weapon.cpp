#include "stdafx.h"
#include "weapon.h"

Weapon::Weapon() {
    cdCounter = 0;
}

void Weapon::Update() {
    if (cdCounter > 0) {
        cdCounter--;
    }
}

void Weapon::DefaultAttack() {
    if (cdCounter == 0) {
        cdCounter = static_cast<int>(cd * 50);
        Attack();
    }
}

int Weapon::GetCd() {
    return cd;
}

int Weapon::GetDamage() {
    return damage;
}

int Weapon::GetMpCost() {
    return mpCost;
}
