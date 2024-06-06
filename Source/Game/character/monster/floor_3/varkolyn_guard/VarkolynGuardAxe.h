#pragma once
#include "VarkolynGuard.h"

class VarkolynGuardAxe : public VarkolynGuard {
public:
    VarkolynGuardAxe(double level);
    void Start() override;
    void InitializeWeapon() override;
};
