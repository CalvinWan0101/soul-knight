#pragma once
#include "VarkolynGuard.h"

class VarkolynGuardMachinGun : public VarkolynGuard {
public:
    VarkolynGuardMachinGun(double level);
    void Start() override;
    void InitializeWeapon() override;
};
