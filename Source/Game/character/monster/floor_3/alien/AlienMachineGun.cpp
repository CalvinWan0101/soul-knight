#include "stdafx.h"
#include "AlienMachineGun.h"

#include "../../../../weapon/ranged_weapon/BlueMachineGun.h"

AlienMachineGun::AlienMachineGun(double level) : Alien(level) {
}

void AlienMachineGun::Start() {
    Alien::Start();
    SetMonsterType(MonsterType::ALIEN_MACHINE_GUN);
}

void AlienMachineGun::InitializeWeapon() {
    this->SetWeapon(new BlueMachineGun(4));
}