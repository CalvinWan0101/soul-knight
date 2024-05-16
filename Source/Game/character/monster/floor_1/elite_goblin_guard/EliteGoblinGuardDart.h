#pragma once
#include "EliteGoblinGuard.h"

class EliteGoblinGuardDart : public EliteGoblinGuard {
public:
    EliteGoblinGuardDart(double level);
    void Start();
    void InitializeWeapon() override;
};
