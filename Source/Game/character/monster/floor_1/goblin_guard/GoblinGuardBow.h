#pragma once
#include "GoblinGuard.h"

class GoblinGuardBow : public GoblinGuard{
public:
    GoblinGuardBow(double level);
    void Start() override;
};
