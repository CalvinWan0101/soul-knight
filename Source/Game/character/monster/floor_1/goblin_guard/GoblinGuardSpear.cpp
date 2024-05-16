#include "stdafx.h"
#include "GoblinGuardSpear.h"
#include "../../../../weapon/melee_weapon/Spear.h"

GoblinGuardSpear::GoblinGuardSpear(double level) : GoblinGuard(level) {
}

void GoblinGuardSpear::Start() {
    GoblinGuard::Start();
    SetMonsterType(MonsterType::GOBLIN_GUARD_SPEAR);
}

void GoblinGuardSpear::InitializeWeapon() {
    this->SetWeapon(new Spear(3));
}

