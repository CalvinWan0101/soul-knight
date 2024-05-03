#include "stdafx.h"
#include "RangedWeapon.h"

RangedWeapon::RangedWeapon() {
}

RangedWeapon::RangedWeapon(Point point) : Weapon(point) {
}

void RangedWeapon::Start() {
    Weapon::Start();   
}

void RangedWeapon::Update() {
    Weapon::Update();
}

