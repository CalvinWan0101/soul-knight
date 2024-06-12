#include "stdafx.h"
#include "WeaponFactory.h"

#include "melee_weapon/CurvedSword.h"
#include "melee_weapon/Hammer.h"
#include "melee_weapon/Hoe.h"
#include "melee_weapon/LongBlade40m.h"
#include "melee_weapon/RedLightsaber.h"
#include "melee_weapon/Spear.h"
#include "ranged_weapon/BadPistol.h"
#include "ranged_weapon/Bow.h"
#include "ranged_weapon/Dart.h"
#include "ranged_weapon/Pistol.h"
#include "ranged_weapon/Rifle.h"
#include "ranged_weapon/Shotgun.h"

Weapon* WeaponFactory::Create(WeaponType weaponType) {
    switch (weaponType) {
    // ranged weapons
    case WeaponType::BAD_PISTOL:
        return new BadPistol();
    case WeaponType::BOW:
        return new Bow();
    case WeaponType::Dart:
        return new Dart();
    case WeaponType::PISTOL:
        return new Pistol();
    case WeaponType::SHOTGUN:
        return new Shotgun();

    // melee weapons
    case WeaponType::HAMMER:
        return new Hammer();
    case WeaponType::HOE:
        return new Hoe();
    case WeaponType::SPEAR:
        return new Spear();
    case WeaponType::CURVED_SWORD:
        return new CurvedSword();
    case WeaponType::LONG_BLADE_40M:
        return new LongBlade40m();
    case WeaponType::RED_LIGHT_SABER:
        return new RedLightsaber();
    default:
        return nullptr;
    }
}
