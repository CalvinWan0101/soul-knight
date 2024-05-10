#pragma once
#include "GoblinGuard.h"

class GoblinGuardSpear : public GoblinGuard{
public:
    GoblinGuardSpear(double level);
    void Start() override;
};
