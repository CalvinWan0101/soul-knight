#include "stdafx.h"
#include "GoblinGuardPistol.h"

#include "../../../../weapon/ranged_weapon/Pistol.h"

GoblinGuardPistol::GoblinGuardPistol(double level) : GoblinGuard(level) {
}

void GoblinGuardPistol::Start() {
    this->SetWeapon(new Pistol(2));
    GoblinGuard::Start();
    SetMonsterType(MonsterType::GOBLIN_GUARD_PISTOL);
}
