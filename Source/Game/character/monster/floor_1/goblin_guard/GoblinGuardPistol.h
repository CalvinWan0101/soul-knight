#pragma once
#include "GoblinGuard.h"

class GoblinGuardPistol : public GoblinGuard{
public:
    GoblinGuardPistol(double level);
    void Start() override;
    void InitializeWeapon() override;
};
