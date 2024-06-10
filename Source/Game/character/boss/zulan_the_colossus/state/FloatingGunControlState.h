#pragma once
#include "FloatingGunState.h"

class FloatingGunControlState : public FloatingGunState
{
public:
    FloatingGunControlState(FloatingGun* floatingGun);
    void Update() override;
};
