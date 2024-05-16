#pragma once
#include "EliteGoblinGuard.h"

class EliteGoblinGuardShotgun : public EliteGoblinGuard{
public:
    EliteGoblinGuardShotgun(double level);
    void Start();
    void InitializeWeapon() override;
};
