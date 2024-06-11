#include "stdafx.h"
#include "VarkolynGuardMachinGun.h"

#include "../../../../weapon/ranged_weapon/PurpleMachineGun.h"

VarkolynGuardMachinGun::VarkolynGuardMachinGun(double level) : VarkolynGuard(level) {
}

void VarkolynGuardMachinGun::Start() {
    VarkolynGuard::Start();
    SetMonsterType(MonsterType::VARKOLYN_GUARD_MACHINE_GUN);
}

void VarkolynGuardMachinGun::InitializeWeapon() {
    this->SetWeapon(new PurpleMachineGun(4));
}
