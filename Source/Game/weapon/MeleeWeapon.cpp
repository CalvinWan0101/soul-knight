#include "stdafx.h"
#include "MeleeWeapon.h"
#include "../character/Player.h"


MeleeWeapon::MeleeWeapon() {
}

MeleeWeapon::MeleeWeapon(Point point) : Weapon(point) {
}

MeleeWeapon::MeleeWeapon(double damage) : Weapon(damage) {
}

void MeleeWeapon::Start() {
    Weapon::Start();
}

void MeleeWeapon::Update() {
    Weapon::Update();
}
