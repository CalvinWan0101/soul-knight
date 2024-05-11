#include "stdafx.h"
#include "EliteGoblinGuardShotgun.h"

#include "../../../../weapon/melee_weapon/Hoe.h"
#include "../../../../weapon/ranged_weapon/Shotgun.h"

EliteGoblinGuardShotgun::EliteGoblinGuardShotgun(double level) : EliteGoblinGuard(level) {
}

void EliteGoblinGuardShotgun::Start() {
    this->SetWeapon(new Shotgun(3));
    EliteGoblinGuard::Start();
}