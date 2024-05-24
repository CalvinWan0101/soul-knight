#pragma once
#include "WeaponType.h"

class Weapon;

class WeaponFactory {
public:
    static Weapon* Create(WeaponType weaponType);
};
