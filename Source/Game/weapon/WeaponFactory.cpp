#include "stdafx.h"
#include "WeaponFactory.h"

#include "melee_weapon/CurvedSword.h"
#include "melee_weapon/Hammer.h"
#include "melee_weapon/Hoe.h"
#include "melee_weapon/LongBlade40m.h"
#include "melee_weapon/RedLightsaber.h"
#include "melee_weapon/Spear.h"
#include "ranged_weapon/BadPistol.h"
#include "ranged_weapon/Bazooka.h"
#include "ranged_weapon/Bow.h"
#include "ranged_weapon/Blowpipe.h"
#include "ranged_weapon/GatlingGun.h"
#include "ranged_weapon/P250.h"
#include "ranged_weapon/Rifle.h"
#include "ranged_weapon/Shotgun.h"
#include "ranged_weapon/SnowFoxVintage.h"
#include "ranged_weapon/SplitterCannon.h"
#include "ranged_weapon/StaffOfLight.h"

Weapon* WeaponFactory::Create(WeaponType weaponType) {
    switch (weaponType) {
    // ranged weapons
    case WeaponType::BAD_PISTOL:
        return new BadPistol();
    case WeaponType::BOW:
        return new Bow();
    case WeaponType::BLOWPIPE:
        return new Blowpipe();
    case WeaponType::P250:
        return new P250();
    case WeaponType::SHOTGUN:
        return new Shotgun();
    case WeaponType::GATLING_GUN:
        return new GatlingGun();
    case WeaponType::STAFF_OF_LIGHT:
        return new StaffOfLight();
    case WeaponType::SPLITTER_CANNON:
        return new SplitterCannon();
    case WeaponType::SNOW_FOX_VINTAGE:
        return new SnowFoxVintage();
    case WeaponType::BAZOOKA:
        return new Bazooka();

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
