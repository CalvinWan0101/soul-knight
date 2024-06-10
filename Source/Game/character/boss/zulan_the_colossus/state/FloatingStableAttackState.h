#pragma once
#include "FloatingGunState.h"

class FloatingStableAttackState : public FloatingGunState
{
public:
    FloatingStableAttackState(FloatingGun* floatingGun);
    void Initialize();
    void Update() override;
private:
    int keepTimes;
};
