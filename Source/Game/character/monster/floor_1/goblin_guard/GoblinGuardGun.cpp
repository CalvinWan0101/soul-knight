#include "stdafx.h"
#include "GoblinGuardGun.h"

#include "../../../../weapon/ranged_weapon/BadPistol.h"

GoblinGuardGun::GoblinGuardGun(double level) : GoblinGuard(level) {
}

void GoblinGuardGun::Start() {
    this->SetWeapon(new BadPistol());
    GoblinGuard::Start();
}
