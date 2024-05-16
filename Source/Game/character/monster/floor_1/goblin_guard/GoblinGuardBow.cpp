#include "stdafx.h"
#include "GoblinGuardBow.h"

#include "../../../../weapon/ranged_weapon/Bow.h"

GoblinGuardBow::GoblinGuardBow(double level) : GoblinGuard(level) {
}

void GoblinGuardBow::Start() {
    GoblinGuard::Start();
    SetMonsterType(MonsterType::GOBLIN_GUARD_BOW);
}

void GoblinGuardBow::InitializeWeapon() {
    this->SetWeapon(new Bow(4));
}
