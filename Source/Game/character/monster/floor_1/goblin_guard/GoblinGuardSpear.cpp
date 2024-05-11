#include "stdafx.h"
#include "GoblinGuardSpear.h"
#include "../../../../weapon/melee_weapon/Spear.h"

GoblinGuardSpear::GoblinGuardSpear(double level) : GoblinGuard(level) {
}

void GoblinGuardSpear::Start() {
    this->SetWeapon(new Spear(3));
    GoblinGuard::Start();
}
