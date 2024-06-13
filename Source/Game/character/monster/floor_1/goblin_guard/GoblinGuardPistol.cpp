#include "stdafx.h"
#include "GoblinGuardPistol.h"

#include "../../../../weapon/ranged_weapon/P250.h"

GoblinGuardPistol::GoblinGuardPistol(double level) : GoblinGuard(level) {
}

void GoblinGuardPistol::Start() {
    GoblinGuard::Start();
    SetMonsterType(MonsterType::GOBLIN_GUARD_PISTOL);
}

void GoblinGuardPistol::InitializeWeapon() {
    this->SetWeapon(new P250(2));
}
