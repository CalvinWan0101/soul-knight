#include "stdafx.h"
#include "RangedWeapon.h"

RangedWeapon::RangedWeapon() {
}

RangedWeapon::RangedWeapon(Point point) : Weapon(point) {
}

RangedWeapon::RangedWeapon(double damage) : Weapon(damage) {
}

void RangedWeapon::Start() {
    Weapon::Start();   
}

void RangedWeapon::Update() {
    Weapon::Update();
}

