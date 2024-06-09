#pragma once
#include "FloatingGunState.h"

class FloatingGunIdleState : public FloatingGunState
{
public:
    FloatingGunIdleState(FloatingGun* floatingGun);
    void Update() override;
};
