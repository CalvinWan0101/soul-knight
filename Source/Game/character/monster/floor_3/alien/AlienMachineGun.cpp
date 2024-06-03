#include "stdafx.h"
#include "AlienMachineGun.h"

#include "../../../../weapon/ranged_weapon/MachineGun.h"

AlienMachineGun::AlienMachineGun(double level) : Alien(level) {
}

void AlienMachineGun::Start() {
    Alien::Start();
    SetMonsterType(MonsterType::ALIEN_MACHINE_GUN);
}

void AlienMachineGun::InitializeWeapon() {
    this->SetWeapon(new MachineGun(4));
}