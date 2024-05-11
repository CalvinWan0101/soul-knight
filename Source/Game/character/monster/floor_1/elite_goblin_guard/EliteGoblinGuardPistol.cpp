#include "stdafx.h"
#include "EliteGoblinGuardPistol.h"

#include "../../../../weapon/ranged_weapon/Pistol.h"

EliteGoblinGuardPistol::EliteGoblinGuardPistol(double level) : EliteGoblinGuard(level) {
}

void EliteGoblinGuardPistol::Start() {
    this->SetWeapon(new Pistol(3));
    EliteGoblinGuard::Start();
}