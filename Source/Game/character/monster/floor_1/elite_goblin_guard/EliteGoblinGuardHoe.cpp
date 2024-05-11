#include "stdafx.h"
#include "EliteGoblinGuardHoe.h"

#include "../../../../weapon/melee_weapon/Hoe.h"

EliteGoblinGuardHoe::EliteGoblinGuardHoe(double level) : EliteGoblinGuard(level) {
}

void EliteGoblinGuardHoe::Start() {
    this->SetWeapon(new Hoe(3));
    EliteGoblinGuard::Start();
}
