#include "stdafx.h"
#include "EliteGoblinGuardHoe.h"

#include "../../../../weapon/melee_weapon/Hoe.h"

EliteGoblinGuardHoe::EliteGoblinGuardHoe(double level) : EliteGoblinGuard(level) {
}

void EliteGoblinGuardHoe::Start() {
    EliteGoblinGuard::Start();
    SetMonsterType(MonsterType::ELITE_GOBLIN_GUARD_HOE);
}

void EliteGoblinGuardHoe::InitializeWeapon() {
    this->SetWeapon(new Hoe(3));
}
