#include "stdafx.h"
#include "EliteGoblinGuardDart.h"

#include "../../../../weapon/ranged_weapon/Dart.h"

EliteGoblinGuardDart::EliteGoblinGuardDart(double level) : EliteGoblinGuard(level) {
}

void EliteGoblinGuardDart::Start() {
    EliteGoblinGuard::Start();
    SetMonsterType(MonsterType::ELITE_GOBLIN_GUARD_DART);
}

void EliteGoblinGuardDart::InitializeWeapon() {
    this->SetWeapon(new Dart(3));
}
