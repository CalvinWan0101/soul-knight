#pragma once
#include "GoblinGuard.h"

class GoblinGuardGun : public GoblinGuard{
public:
    GoblinGuardGun(double level);
    void Start() override;
};
