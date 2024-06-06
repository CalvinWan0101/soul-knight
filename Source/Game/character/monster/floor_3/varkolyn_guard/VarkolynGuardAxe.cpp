#include "stdafx.h"
#include "VarkolynGuardAxe.h"

#include "../../../../weapon/melee_weapon/PurpleAxe.h"

VarkolynGuardAxe::VarkolynGuardAxe(double level) : VarkolynGuard(level) {
}

void VarkolynGuardAxe::Start() {
    VarkolynGuard::Start();
    SetMonsterType(MonsterType::VARKOLYN_GUARD_AXE);
}

void VarkolynGuardAxe::InitializeWeapon() {
    this->SetWeapon(new PurpleAxe(4));
}
