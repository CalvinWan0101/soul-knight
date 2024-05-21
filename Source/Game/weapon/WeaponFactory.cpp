#include "stdafx.h"
#include "WeaponFactory.h"

#include "melee_weapon/Hammer.h"
#include "melee_weapon/Hoe.h"
#include "melee_weapon/Spear.h"
#include "ranged_weapon/BadPistol.h"
#include "ranged_weapon/Bow.h"
#include "ranged_weapon/Dart.h"
#include "ranged_weapon/GoblinStaff.h"
#include "ranged_weapon/Pistol.h"
#include "ranged_weapon/Shotgun.h"


Weapon* WeaponFactory::Create(Name weaponName) {
    switch (weaponName) {
    case BAD_PISTOL:
        return new BadPistol();
    case BOW:
        return new Bow();
    case Dart:
        return new ::Dart();
    case PISTOL:
        return new Pistol();
    case SHOTGUN:
        return new Shotgun();
    case HAMMER:
        return new Hammer();
    case HOE:
        return new Hoe();
    case SPEAR:
        return new Spear();
    default:
        return nullptr;
        
    }
}
