#pragma once

class Weapon;

class WeaponFactory {
public:
    enum Name {
        BAD_PISTOL,
        BOW,
        Dart,
        GOLBIN_STAFF,
        PISTOL,
        SHOTGUN,

        HAMMER,
        HOE,
        SPEAR,

        Count
    };
    static Weapon* Create(Name weaponName);
};
