#include "stdafx.h"
#include "GoblinGuardBow.h"

#include "../../../../weapon/ranged_weapon/Bow.h"

GoblinGuardBow::GoblinGuardBow(double level) : GoblinGuard(level) {
}

void GoblinGuardBow::Start() {
    this->SetWeapon(new Bow(4));
    GoblinGuard::Start();
}
