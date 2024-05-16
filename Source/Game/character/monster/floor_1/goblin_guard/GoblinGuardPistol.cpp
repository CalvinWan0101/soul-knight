#include "stdafx.h"
#include "GoblinGuardPistol.h"

#include "../../../../weapon/ranged_weapon/Pistol.h"

GoblinGuardPistol::GoblinGuardPistol(double level) : GoblinGuard(level) {
}

void GoblinGuardPistol::Start() {
    GoblinGuard::Start();
    SetMonsterType(MonsterType::GOBLIN_GUARD_PISTOL);
}

void GoblinGuardPistol::InitializeWeapon() {
    this->SetWeapon(new Pistol(2));
}
