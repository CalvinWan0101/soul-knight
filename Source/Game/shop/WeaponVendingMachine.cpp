#include "stdafx.h"
#include "WeaponVendingMachine.h"

#include "../manager/ObjectManager.h"
#include "../utils/Rand.h"
#include "../weapon/Weapon.h"
#include "../weapon/WeaponFactory.h"

WeaponVendingMachine::WeaponVendingMachine(int level, int stage) : VendingMachine(level, stage) {
}

void WeaponVendingMachine::Shipment() {
    int weaponId = Rand::Instance()->Get(0, static_cast<int>(WeaponType::Count) - 1);
    Weapon* weapon = WeaponFactory::Create(static_cast<WeaponType>(weaponId));
    weapon->SetPosition(this->position + Point(0, 45));
    ObjectManager::Instance()->AddObject(weapon);
}

void WeaponVendingMachine::LoadResources() {
    AddAnimation({"Resources/shop/weapon_vending_machine.bmp"}, RGB(255,255,255), 1000, false);
}