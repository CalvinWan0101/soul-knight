#include "stdafx.h"
#include "weapon.h"

Weapon::Weapon() {
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
